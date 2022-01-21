#include <stdio.h>

/*
���� : H * W(H, W <= 50) ũ���� ���ڿ� '.'��� ���ĺ����� �ִ�. �� ���ĺ����� ��� ���簢�� �������
�׿��ִ� ������ �� �ִ� �� ���Ѵ�. '.'���� �� ĭ�� �ǹ��Ѵ�.

�ذ� ��� : �켱 �� ���ĺ����� ���簢�� ������������ Ȯ���Ѵ�. ���� X��ǥ�� Y��ǥ ������ ���� ������ ���ϰ�
�� �ȿ� '.'�� �ִ� �� Ȯ���Ѵ�. '.'�� �ִٸ� ���簢���� �ƴϴ�. '.'�� ���ٸ� �� ���� ���� �ִ�
�ٸ� ���ĺ����� ���� ���ĺ��� �������� �����Ѵ�. ��� ������ ������ ����, ���� ������ �õ��Ѵ�.
���� ���� ������ �Ұ����� ���(����Ŭ�� ������ ���)�� �ִٸ� ���簢���� �ƴ� ���� �־��
�׿��ִ� �����̹Ƿ� ������ ������ �� ����. �� �ܿ��� ������ ���� �����ϴ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����

��ó : JAG 2006D C��
*/

char s[64][64];
int ed[32][32], vis[32], cnt[32];

int main(void) {
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\C1", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\C1_t.out", "w", stdout);
    int t, h, w, xl, xh, yl, yh, r, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) ed[i][j] = 0;
            vis[i] = 0;
        }

        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", s[i]);
        }
        r = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            xl = 99, xh = -1, yl = 99, yh = -1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == c) {
                        if (i < xl) xl = i;
                        if (i > xh) xh = i;
                        if (j < yl) yl = j;
                        if (j > yh) yh = j;
                    }
                }
            }

            for (int i = xl; i <= xh; i++) {
                for (int j = yl; j <= yh; j++) {
                    if (s[i][j] == '.') r = 1;
                    else if (s[i][j] != c) ed[c - 'A'][s[i][j] - 'A'] = 1;
                }
            }
        }
        if (r) {
            printf("SUSPICIOUS\n");
            continue;
        }

        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
            for (int j = 0; j < 26; j++) cnt[i] += ed[j][i];
        }
        while (1) {
            tmp = 0;
            for (int i = 0; i < 26; i++) {
                if (!vis[i] && cnt[i] == 0) {
                    vis[i] = 1;
                    for (int j = 0; j < 26; j++) {
                        cnt[j] -= ed[i][j];
                        tmp += ed[i][j];
                    }
                }
            }
            if (tmp == 0) break;
        }
        for (int i = 0; i < 26; i++) r |= (!vis[i]);
        printf("%s\n", r ? "SUSPICIOUS" : "SAFE");
    }
    return 0;
}
