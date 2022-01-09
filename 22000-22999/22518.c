#include <stdio.h>
#include <string.h>
#define MOD 65423

/*
문제 : H * W(H, W <= 11) 크기의 격자에 '#', '.', '?'가 있다. 상하좌우로 인접한 '#'이 트리 형태가 되도록 하며,
'.'은 상하좌우로 인접하지 않도록 '?'를 적당히 '#'와 '.'로 바꾸어 '#'의 개수를 가장 많이 할 때의 '#'의 개수를 구한다.
만약 어떻게 바꾸어도 조건을 충족시킬 수 없다면 -1을 출력한다.

해결 방법 : 커넥션 프로파일 DP를 이용하여 각 칸마다 이전 줄의 연결 상태에 따른 '#'의 최대 개수를 저장한다.
연결 상태는 각 칸마다 수로 표현된다. '.'인 칸은 0, '#'인 칸은 왼쪽부터 차례로 연결 요소의 번호이다.
각 칸을 확인할 때 마다 '.'과 '#'을 넣을 수 있는 지, 넣으면 연결 상태가 어떻게 변하는 지 확인한다.

먼저 연결 상태는 백트래킹을 통해 가능한 경우를 전처리하고 시작한다.
중간에 줄에 바뀔 수 있음에 유의해야 한다.

'.'을 넣을 수 있는 경우는 위쪽과 왼쪽에 '.'이 없고 해당 칸이 '#'이 아니며 바로 위 칸이 위 줄에서
유일한 연결요소가 아닌 경우로, 넣으면 연결 상태는 단순히 그 칸이 지워지는 것에서 끝나게 된다.
단, 번호는 바뀔 수 있기 때문에 왼쪽부터 연결 요소를 재지정해야 한다.
이때, W가 1인 경우에는 예외적인 경우가 생길 수 있으므로 유의한다.

'#'을 넣을 수 있는 경우는 '.'이 아닌 칸이라면 왼쪽과 위쪽이 '#'이면서 같은 연결 요소인 경우만 아니면 된다.
이 경우 경우에 따라 연결 요소의 상태가 변화하는데, 우선 왼쪽과 위쪽이 모두 '.'인 경우 그 칸이 새로운 연결 요소가 된다.
둘 중 하나만 '#'인 경우에는 그쪽 칸의 연결 요소를 따라가게 된다. 둘 다 '#'이 되면 양쪽을 연결하게 된다.
이를 통해 연결 요소를 확인한 다음 '.'때와 마찬가지로 연결 요소의 값을 재지정한다.

이렇게 격자에 값을 넣은 후 연결 상태를 찾았으면 다음 칸의 해당 연결 상태에 대한 값을 갱신한다.
이를 반복하여 마지막 칸까지 이동한 다음, 마지막 칸에서 연결 요소가 1개 이하인 모든 연결 상태 가운데 최댓값을 구하면 된다.
그러한 값이 없다면 -1을 출력한다.

주요 알고리즘 : DP, 커넥션 프로파일 DP

출처 : JAG 2011S4 E번
*/

char state[32768][16], tstate[16], ttstate[16], thstate[16], scrib[16][16];
int mem[16][16][32768];
int hash[65536];
int sc = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int isvalid(int l, char* s, int c) {
    //이 연결 상태가 나올 수 있는 상태인지 확인한다. c: 줄이 바뀌는 칸
    int cnt = 0;
    for (int j = 0; j < l; j++) {
        //printf("%d ", s[j]);
        if (j > 0 && ((s[j] == 0 && s[j - 1] == 0) || (s[j] > 1 && s[j - 1] > 1 && s[j] != s[j - 1])) && j != c) cnt++;
    }
    if ((c >= 0 && cnt) || (c < 0 && cnt > 1)) return 0;
    else return 1;
}

void track(int w, int x, int st, int cut, int cnt) {
    //백트래킹을 통해 가능한 모든 연결 상태를 전처리한다.
    if (w == x) {
        for (int i = 0; i < w; i++) {
            state[sc][i] = tstate[i];
            //printf("%d ", state[sc][i]);
        }
        //printf("\n");
        sc++;
        return;
    }
    if ((st >> x) & 1) {
        if (x == 0 || (~(st >> (x - 1)) & 1)) {
            for (int i = 1; i <= cnt + 1; i++) {
                tstate[x] = i;
                track(w, x + 1, st, cut, big(cnt, i));
            }
        }
        else {
            if (!cut) {
                for (int i = 1; i <= cnt + 1; i++) {
                    tstate[x] = i;
                    if (i == tstate[x - 1]) continue;
                    track(w, x + 1, st, cut + 1, cnt + 1);
                }
            }
            tstate[x] = tstate[x - 1];
            track(w, x + 1, st, cut, cnt);
        }
    }
    else {
        tstate[x] = 0;
        if (x > 0 && (~(st >> (x - 1)) & 1)) {
            if (!cut) track(w, x + 1, st, cut + 1, cnt);
            else return;
        }
        else track(w, x + 1, st, cut, cnt);
    }
}

void enhash(int l, char* s, int n) {
    //연결 상태를 해시 테이블에 추가한다.
    if (gethash(l, s) >= 0) return;
    long long x = 0;
    for (int i = 0; i < l; i++) {
        x *= 7;
        x += s[i];
    }
    x %= MOD;
    for (int i = x;; i++) {
        if (hash[i] < 0) {
            hash[i] = n;
            return;
        }
    }
}

int gethash(int l, char* s) {
    //주어진 연결 상태에 맞는 상태 번호를 가져온다.
    long long x = 0, t, h;
    for (int i = 0; i < l; i++) {
        x *= 7;
        x += s[i];
    }
    x %= MOD;
    for (int i = x;; i++) {
        h = hash[i];
        if (h < 0) return -1;
        t = 1;
        for (int j = 0; j < l; j++) {
            if (state[h][j] != s[j]) {
                t = 0;
                break;
            }
        }
        if (t) return h;
    }
}

int main(void) {
    int h, w, hn, wn, tmp, cnt, ha, best = -1;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", scrib[i]);
    }
    for (int i = 0; i < (1 << w); i++) {
        tmp = 0;
        for (int j = 0; j < w - 1; j++) {
            if (((i >> j) & 3) == 0) tmp++;
        }
        if (tmp >= 2) continue;
        track(w, 0, i, 0, 0);
    }
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < sc; i++) {
        enhash(w, state[i], i);
    }
    //가능한 모든 연결 상태들을 전처리한다.


    memset(mem, -127, sizeof(mem));
    for (int i = 0; i < (1 << w); i++) {
        //첫 줄로 가능한 모든 연결 상태들을 확인하고 두 번째 줄의 첫 칸에 집어넣는다.
        tmp = 1;
        for (int j = 0; j < w; j++) {
            tstate[j] = ((i >> j) & 1);
            if (j > 0 && tstate[j - 1] == 0 && tstate[j] == 0) tmp = 0;
            if ((tstate[j] && scrib[0][j] == '.') || (tstate[j] == 0 && scrib[0][j] == '#')) tmp = 0;
        }
        if (!tmp) continue;
        tmp = 0, cnt = 0;
        for (int j = 0; j < w; j++) {
            if (tstate[j] == 0) continue;
            if (j == 0 || tstate[j - 1] == 0) tmp++;
            tstate[j] = tmp;
            cnt++;
        }
        if (!isvalid(w, tstate, 0)) return 3;
        ha = gethash(w, tstate);
        if (ha < 0) return 1;
        mem[1][0][ha] = cnt;
    }
    if (w == 1) {
        cnt = 0;
        for (int i = 0; i < h; i++) {
            if (i != 0 && i != h - 1 && scrib[i][0] == '.') {
                printf("-1");
                return 0;
            }
            else if (scrib[i][0] != '.') cnt++;
        }
        printf("%d", cnt);
        return 0;
    }

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //각 칸의 모든 연결 상태에 대해 최댓값을 구해나간다.
            hn = i + (j == w - 1); //다음 칸의 행
            wn = (j == w - 1) ? 0 : j + 1; //다음 칸의 열
            for (int k = 0; k < sc; k++) {
                if (mem[i][j][k] < 0) continue; //기록되지 않은 경우 확인할 필요가 없다.
                for (int l = 0; l < w; l++) {
                    tstate[l] = state[k][l]; //앞줄의 연결 상태를 가져온다.
                }
                if (!isvalid(w, tstate, j)) {
                    return 3;
                }

                if (scrib[i][j] != '#' && tstate[j] != 0 && (j == 0 || tstate[j - 1] != 0)) {
                    //'.'이 가능한 경우
                    tmp = 0, cnt = 0;
                    for (int l = 0; l < w; l++) {
                        ttstate[l] = tstate[l];
                        if (j != l && tstate[j] == tstate[l]) tmp = 1;
                    }
                    ttstate[j] = 0;
                    memset(thstate, 0, sizeof(thstate));
                    for (int l = 0; l < w; l++) {
                        if (ttstate[l] == 0 || thstate[l]) continue;
                        if (ttstate[l] && (l == 0 || ttstate[l - 1] != ttstate[l])) cnt++;
                        for (int m = l; m < w; m++) {
                            if (ttstate[l] == ttstate[m]) thstate[m] = cnt;
                        }
                    }
                    if (tmp) {
                        //윗칸이 유일한 연결 요소가 아니어야 한다.
                        ha = gethash(w, thstate);
                        if (ha < 0) {
                            return 1;
                        }
                        mem[hn][wn][ha] = big(mem[hn][wn][ha], mem[i][j][k]);
                    }
                }
                if (scrib[i][j] != '.' && (j == 0 || (tstate[j - 1] != tstate[j] || tstate[j] == 0))) {
                    //'#'이 가능한 경우
                    tmp = 0, cnt = 0;
                    for (int l = 0; l < w; l++)  ttstate[l] = tstate[l];
                    for (int l = 0; l < w; l++) {
                        if (l == j) {
                            if ((l != 0 && ttstate[l - 1]) && tstate[l]) {
                                ttstate[l] = ttstate[l - 1];
                                for (int m = 0; m < w; m++) {
                                    if (ttstate[m] == tstate[l]) ttstate[m] = ttstate[l];
                                }
                            }
                            else {
                                ttstate[l] = big(tstate[l - 1], tstate[l]);
                                if (ttstate[l] == 0) ttstate[l] = 10;
                            }

                        }
                    }
                    //경우를 나누어 연결 상태를 바꾼다.

                    memset(thstate, 0, sizeof(thstate));
                    for (int l = 0; l < w; l++) {
                        if (ttstate[l] == 0 || thstate[l]) continue;
                        if (ttstate[l] && (l == 0 || ttstate[l - 1] != ttstate[l])) cnt++;
                        for (int m = l; m < w; m++) {
                            if (ttstate[l] == ttstate[m]) thstate[m] = cnt;
                        }
                    }
                    //연결 상태의 값을 전처리한다.
                    ha = gethash(w, thstate);
                    if (ha < 0) {
                        return 1;
                    }
                    mem[hn][wn][ha] = big(mem[hn][wn][ha], mem[i][j][k] + 1);
                }
            }
            
            best = -1;
            for (int k = 0; k < sc; k++) {
                tmp = 0;
                for (int l = 0; l < w; l++) {
                    tmp = big(tmp, state[k][l]);
                }
                if (tmp == 1) {
                    best = big(best, mem[hn][wn][k]);
                }
            }
            //printf("%d ", best);
            
        }
        //printf("\n");
    }

    //마지막 칸의 다음 칸에서 연결 요소가 1개 이하인 상태 가운데 가장 '#'이 많은 것을 선택한다.
    best = -1;
    for (int i = 0; i < sc; i++) {
        tmp = 0;
        for (int j = 0; j < w; j++) {
            tmp = big(tmp, state[i][j]);
        }
        if (tmp <= 1) best = big(best, mem[h][0][i]);
    }
    printf("%d", best);
    return 0;
}