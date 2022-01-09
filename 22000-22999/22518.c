#include <stdio.h>
#include <string.h>
#define MOD 65423

/*
���� : H * W(H, W <= 11) ũ���� ���ڿ� '#', '.', '?'�� �ִ�. �����¿�� ������ '#'�� Ʈ�� ���°� �ǵ��� �ϸ�,
'.'�� �����¿�� �������� �ʵ��� '?'�� ������ '#'�� '.'�� �ٲپ� '#'�� ������ ���� ���� �� ���� '#'�� ������ ���Ѵ�.
���� ��� �ٲپ ������ ������ų �� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : Ŀ�ؼ� �������� DP�� �̿��Ͽ� �� ĭ���� ���� ���� ���� ���¿� ���� '#'�� �ִ� ������ �����Ѵ�.
���� ���´� �� ĭ���� ���� ǥ���ȴ�. '.'�� ĭ�� 0, '#'�� ĭ�� ���ʺ��� ���ʷ� ���� ����� ��ȣ�̴�.
�� ĭ�� Ȯ���� �� ���� '.'�� '#'�� ���� �� �ִ� ��, ������ ���� ���°� ��� ���ϴ� �� Ȯ���Ѵ�.

���� ���� ���´� ��Ʈ��ŷ�� ���� ������ ��츦 ��ó���ϰ� �����Ѵ�.
�߰��� �ٿ� �ٲ� �� ������ �����ؾ� �Ѵ�.

'.'�� ���� �� �ִ� ���� ���ʰ� ���ʿ� '.'�� ���� �ش� ĭ�� '#'�� �ƴϸ� �ٷ� �� ĭ�� �� �ٿ���
������ �����Ұ� �ƴ� ����, ������ ���� ���´� �ܼ��� �� ĭ�� �������� �Ϳ��� ������ �ȴ�.
��, ��ȣ�� �ٲ� �� �ֱ� ������ ���ʺ��� ���� ��Ҹ� �������ؾ� �Ѵ�.
�̶�, W�� 1�� ��쿡�� �������� ��찡 ���� �� �����Ƿ� �����Ѵ�.

'#'�� ���� �� �ִ� ���� '.'�� �ƴ� ĭ�̶�� ���ʰ� ������ '#'�̸鼭 ���� ���� ����� ��츸 �ƴϸ� �ȴ�.
�� ��� ��쿡 ���� ���� ����� ���°� ��ȭ�ϴµ�, �켱 ���ʰ� ������ ��� '.'�� ��� �� ĭ�� ���ο� ���� ��Ұ� �ȴ�.
�� �� �ϳ��� '#'�� ��쿡�� ���� ĭ�� ���� ��Ҹ� ���󰡰� �ȴ�. �� �� '#'�� �Ǹ� ������ �����ϰ� �ȴ�.
�̸� ���� ���� ��Ҹ� Ȯ���� ���� '.'���� ���������� ���� ����� ���� �������Ѵ�.

�̷��� ���ڿ� ���� ���� �� ���� ���¸� ã������ ���� ĭ�� �ش� ���� ���¿� ���� ���� �����Ѵ�.
�̸� �ݺ��Ͽ� ������ ĭ���� �̵��� ����, ������ ĭ���� ���� ��Ұ� 1�� ������ ��� ���� ���� ��� �ִ��� ���ϸ� �ȴ�.
�׷��� ���� ���ٸ� -1�� ����Ѵ�.

�ֿ� �˰��� : DP, Ŀ�ؼ� �������� DP

��ó : JAG 2011S4 E��
*/

char state[32768][16], tstate[16], ttstate[16], thstate[16], scrib[16][16];
int mem[16][16][32768];
int hash[65536];
int sc = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int isvalid(int l, char* s, int c) {
    //�� ���� ���°� ���� �� �ִ� �������� Ȯ���Ѵ�. c: ���� �ٲ�� ĭ
    int cnt = 0;
    for (int j = 0; j < l; j++) {
        //printf("%d ", s[j]);
        if (j > 0 && ((s[j] == 0 && s[j - 1] == 0) || (s[j] > 1 && s[j - 1] > 1 && s[j] != s[j - 1])) && j != c) cnt++;
    }
    if ((c >= 0 && cnt) || (c < 0 && cnt > 1)) return 0;
    else return 1;
}

void track(int w, int x, int st, int cut, int cnt) {
    //��Ʈ��ŷ�� ���� ������ ��� ���� ���¸� ��ó���Ѵ�.
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
    //���� ���¸� �ؽ� ���̺� �߰��Ѵ�.
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
    //�־��� ���� ���¿� �´� ���� ��ȣ�� �����´�.
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
    //������ ��� ���� ���µ��� ��ó���Ѵ�.


    memset(mem, -127, sizeof(mem));
    for (int i = 0; i < (1 << w); i++) {
        //ù �ٷ� ������ ��� ���� ���µ��� Ȯ���ϰ� �� ��° ���� ù ĭ�� ����ִ´�.
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
            //�� ĭ�� ��� ���� ���¿� ���� �ִ��� ���س�����.
            hn = i + (j == w - 1); //���� ĭ�� ��
            wn = (j == w - 1) ? 0 : j + 1; //���� ĭ�� ��
            for (int k = 0; k < sc; k++) {
                if (mem[i][j][k] < 0) continue; //��ϵ��� ���� ��� Ȯ���� �ʿ䰡 ����.
                for (int l = 0; l < w; l++) {
                    tstate[l] = state[k][l]; //������ ���� ���¸� �����´�.
                }
                if (!isvalid(w, tstate, j)) {
                    return 3;
                }

                if (scrib[i][j] != '#' && tstate[j] != 0 && (j == 0 || tstate[j - 1] != 0)) {
                    //'.'�� ������ ���
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
                        //��ĭ�� ������ ���� ��Ұ� �ƴϾ�� �Ѵ�.
                        ha = gethash(w, thstate);
                        if (ha < 0) {
                            return 1;
                        }
                        mem[hn][wn][ha] = big(mem[hn][wn][ha], mem[i][j][k]);
                    }
                }
                if (scrib[i][j] != '.' && (j == 0 || (tstate[j - 1] != tstate[j] || tstate[j] == 0))) {
                    //'#'�� ������ ���
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
                    //��츦 ������ ���� ���¸� �ٲ۴�.

                    memset(thstate, 0, sizeof(thstate));
                    for (int l = 0; l < w; l++) {
                        if (ttstate[l] == 0 || thstate[l]) continue;
                        if (ttstate[l] && (l == 0 || ttstate[l - 1] != ttstate[l])) cnt++;
                        for (int m = l; m < w; m++) {
                            if (ttstate[l] == ttstate[m]) thstate[m] = cnt;
                        }
                    }
                    //���� ������ ���� ��ó���Ѵ�.
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

    //������ ĭ�� ���� ĭ���� ���� ��Ұ� 1�� ������ ���� ��� ���� '#'�� ���� ���� �����Ѵ�.
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