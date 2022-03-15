#include <stdio.h>

/*
���� : Lm * Cm(Lm, Cm <= 32) ũ���� ���ڿ��� �־��� Li * Ci(Li, Ci <= 12) ũ���� �κа� ��ġ�ϴ� �κ���
�� �� ã�� �� �ִ� �� ���Ѵ�.

�ذ� ��� : Lm, Cm, Li, Ci�� ũ�Ⱑ �����Ƿ� 4�� for������ ��� ��츦 ã�ƺ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : NZPC 2012 F��
*/

char rig[16][16], map[48][48];

int main(void) {
    int t, li, ci, lm, cm, r, ok;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &li, &ci);
        for (int i = 0; i < li; i++) {
            scanf("%s", rig[i]);
        }
        scanf("%d %d", &lm, &cm);
        for (int i = 0; i < lm; i++) {
            scanf("%s", map[i]);
        }

        r = 0;
        for (int i = 0; i <= lm - li; i++) {
            for (int j = 0; j <= cm - ci; j++) {
                ok = 1;
                for (int ii = 0; ii < li; ii++) {
                    for (int jj = 0; jj < ci; jj++) {
                        if (rig[ii][jj] != map[i + ii][j + jj]) ok = 0;
                    }
                }
                r += ok;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}