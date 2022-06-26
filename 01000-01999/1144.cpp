#include <stdio.h>
#include <string.h>
#define MOD 65423

/*
문제 : N * M(N, M <= 9) 크기의 격자에 있는 각 칸마다 절댓값 1000 이하 정수로 비용이 주어진다.
하나의 연결요소를 이루는 부분집합 가운데 가장 작은 비용인 것의 비용을 구한다.
부분집합이 공집합이어도 상관 없다.

해결 방법 : 커넥션 프로파일 DP를 이용한다. 자세한 구현 방법은 코드를 참고한다.

주요 알고리즘 : DP, 커넥션 프로파일 DP

출처 : SRM 312D1 3번
*/

char state[32768][16], tstate[16], ttstate[16], thstate[16];
int cost[16][16], mem[16][16][32768];
int hash[65536];
int sc = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
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
        track(w, x + 1, st, cut, cnt);
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

int main(void) {
    int h, w, hn, wn, tmp, cnt, ha, best = 0;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 0; i < (1 << w); i++) {
        track(w, 0, i, 0, 0);
    }
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < sc; i++) {
        enhash(w, state[i], i);
    }
    for (int i = 0; i < 9; i++) {
        //printf("%d", state[7917][i]);
    }
    //가능한 모든 연결 상태들을 전처리한다.


    memset(mem, 1, sizeof(mem));
    for (int i = 0; i < (1 << w); i++) {
        //첫 줄로 가능한 모든 연결 상태들을 확인하고 두 번째 줄의 첫 칸에 집어넣는다.
        for (int j = 0; j < w; j++) {
            tstate[j] = ((i >> j) & 1);
        }
        tmp = 0, cnt = 0;
        for (int j = 0; j < w; j++) {
            if (tstate[j] == 0) continue;
            if (j == 0 || tstate[j - 1] == 0) tmp++;
            tstate[j] = tmp;
            cnt += cost[0][j];
        }
        ha = gethash(w, tstate);
        if (ha < 0) return 1;
        mem[1][0][ha] = cnt;
        //if (mem[1][0][ha] > 0) mem[1][0][ha] = 0;
        if (tmp == 1) {
            best = small(best, cnt);
        }
    }

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //각 칸의 모든 연결 상태에 대해 최댓값을 구해나간다.
            hn = i + (j == w - 1); //다음 칸의 행
            wn = (j == w - 1) ? 0 : j + 1; //다음 칸의 열
            for (int k = 0; k < sc; k++) {
                if (mem[i][j][k] > 103000) continue; //기록되지 않은 경우 확인할 필요가 없다.
                cnt = 0;
                for (int l = 0; l < w; l++) {
                    tstate[l] = state[k][l]; //앞줄의 연결 상태를 가져온다.
                }

                if (1) {
                    //'.'이 가능한 경우
                    tmp = 0;
                    for (int l = 0; l < w; l++) {
                        ttstate[l] = tstate[l];
                        if (j != l && tstate[j] == tstate[l]) tmp = 1;
                    }
                    if (tstate[j] == 0) tmp = 1;
                    ttstate[j] = 0;
                    cnt = 0;
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
                        mem[hn][wn][ha] = small(mem[hn][wn][ha], mem[i][j][k]);
                        if (ha == 106) {
                            best = best;
                        }

                    }
                }
                if (1) {
                    //'#'이 가능한 경우(항상)
                    tmp = 0;
                    for (int l = 0; l < w; l++)  ttstate[l] = tstate[l];
                    for (int l = 0; l < w; l++) {
                        if (l == j) {
                            if ((l != 0 && ttstate[l - 1]) && tstate[l]) {
                                tmp = ttstate[l];
                                for (int m = 0; m < w; m++) {
                                    if (ttstate[m] == tmp) ttstate[m] = ttstate[l - 1];
                                }
                            }
                            else {
                                ttstate[l] = big(tstate[l - 1], tstate[l]);
                                if (ttstate[l] == 0) ttstate[l] = 10;
                            }

                        }
                    }
                    //경우를 나누어 연결 상태를 바꾼다.

                    cnt = 0;
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
                    mem[hn][wn][ha] = small(mem[hn][wn][ha], mem[i][j][k] + cost[i][j]);
                    if (ha == 106) {
                        best = best;
                    }
                    if (cnt == 1) {
                        best = small(best, mem[hn][wn][ha]);
                        
                    }
                }
            }

            //printf("%d ", best);

        }
        //printf("\n");
    }
    printf("%d", best);
    return 0;
}