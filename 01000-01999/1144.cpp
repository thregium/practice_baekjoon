#include <stdio.h>
#include <string.h>
#define MOD 65423

/*
���� : N * M(N, M <= 9) ũ���� ���ڿ� �ִ� �� ĭ���� ���� 1000 ���� ������ ����� �־�����.
�ϳ��� �����Ҹ� �̷�� �κ����� ��� ���� ���� ����� ���� ����� ���Ѵ�.
�κ������� �������̾ ��� ����.

�ذ� ��� : Ŀ�ؼ� �������� DP�� �̿��Ѵ�. �ڼ��� ���� ����� �ڵ带 �����Ѵ�.

�ֿ� �˰��� : DP, Ŀ�ؼ� �������� DP

��ó : SRM 312D1 3��
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
        track(w, x + 1, st, cut, cnt);
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
    //������ ��� ���� ���µ��� ��ó���Ѵ�.


    memset(mem, 1, sizeof(mem));
    for (int i = 0; i < (1 << w); i++) {
        //ù �ٷ� ������ ��� ���� ���µ��� Ȯ���ϰ� �� ��° ���� ù ĭ�� ����ִ´�.
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
            //�� ĭ�� ��� ���� ���¿� ���� �ִ��� ���س�����.
            hn = i + (j == w - 1); //���� ĭ�� ��
            wn = (j == w - 1) ? 0 : j + 1; //���� ĭ�� ��
            for (int k = 0; k < sc; k++) {
                if (mem[i][j][k] > 103000) continue; //��ϵ��� ���� ��� Ȯ���� �ʿ䰡 ����.
                cnt = 0;
                for (int l = 0; l < w; l++) {
                    tstate[l] = state[k][l]; //������ ���� ���¸� �����´�.
                }

                if (1) {
                    //'.'�� ������ ���
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
                        //��ĭ�� ������ ���� ��Ұ� �ƴϾ�� �Ѵ�.
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
                    //'#'�� ������ ���(�׻�)
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
                    //��츦 ������ ���� ���¸� �ٲ۴�.

                    cnt = 0;
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