#include <stdio.h>

/*
���� : �� ������ ��ġ�� �־��� ��, ��� ������ �ϳ��� ���� �������� ���� ��������� ������ ��,
�������� ���̰� �ּҰ� �Ǵ� ���� �������� ��ġ�� ã��, �׶��� ������ ����Ѵ�.
��, ������ �ʹ� ū ��� ���� �������� ��ġ�� ����Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� ���� �������� ��ġ�� ���, �� ���� �̿��� ������ �����.
������ ����� �ڼ��� ������ �ڵ带 �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : MidC 2002 E��
*/

char res[128][128];
int pos[1024][2], lohi[128][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int end = 0, n, dist, best, by, xl, yl, xh, yh;
    for (int tt = 1;; tt++) {
        n = 0;
        xl = 128, yl = 128, xh = -1, yh = -1;
        while (1) {
            scanf("%d %d", &pos[n][0], &pos[n][1]);
            if (pos[n][0] > 94 || pos[n][1] > 73) return 1;
            if (pos[n][0] == 0) end = 1;
            if (pos[n][0] <= 0) break;
            if (pos[n][0] < xl) xl = pos[n][0];
            if (pos[n][0] > xh) xh = pos[n][0];
            if (pos[n][1] < yl) yl = pos[n][1];
            if (pos[n][1] > yh) yh = pos[n][1];

            n++;
            if (n > 1000) return 1;
        }
        if (end) break;
        if (xh < 0) return 1;
        
        for (int i = 1; i <= 94; i++) {
            lohi[i][0] = 75;
            lohi[i][1] = -1;
        }
        for (int i = 0; i < n; i++) {
            if (pos[i][1] < lohi[pos[i][0]][0]) lohi[pos[i][0]][0] = pos[i][1];
            if (pos[i][1] > lohi[pos[i][0]][1]) lohi[pos[i][0]][1] = pos[i][1];
        }

        best = 103000, by = -1;
        for (int i = 1; i <= 73; i++) {
            dist = 0;
            for (int j = 1; j <= 94; j++) {
                if (lohi[j][1] < 0) continue;
                dist += big(0, i - lohi[j][0]);
                dist += big(0, lohi[j][1] - i);
            }
            if (dist < best) {
                best = dist;
                by = i;
            }
        }
        if (by < 0) return 2;

        while (xh % 5 != 4) xh++;
        while (yh % 5 != 4) yh++;
        while (xl % 5 != 1) xl--;
        while (yl % 5 != 1) yl--;
        if (xh - xl > 68 || yh - yl > 18) {
            printf("OIL FIELD %d\n", tt);
            printf("Map is too big to draw for pipeline at %d\n", by);
            continue;
        }

        for (int i = 1; i <= 74; i++) {
            for (int j = 1; j <= 94; j++) res[i][j] = '.';
        }
        for (int i = 1; i <= 94; i++) {
            res[by][i] = '*';
            if (lohi[i][0] < 0) continue;
            if (by < lohi[i][0]) lohi[i][0] = by;
            if (by > lohi[i][1]) lohi[i][1] = by;
            for (int j = lohi[i][0]; j <= lohi[i][1]; j++) res[j][i] = '*';
        }
        for (int i = 0; i < n; i++) {
            res[pos[i][1]][pos[i][0]] = '@';
        }

        printf("OIL FIELD %d\n", tt);
        for (int i = yh + 1; i >= yl - 1; i--) {
            if (i % 5 == 0) {
                if (yh + 1 >= 10) printf("%2d", i);
                else printf("%d", i);
            }
            else {
                if (yh + 1 >= 10) printf("  ");
                else printf(" ");
            }
            for (int j = xl - 1; j <= xh + 1; j++) {
                if (j < xl || j > xh || i < yl || i > yh) {
                    if (i % 5 == 0 && j % 5 == 0) printf("+");
                    else if (j < xl || j > xh) printf("|");
                    else printf("-");
                }
                else printf("%c", res[i][j]);
            }
            printf("\n");
        }
        if (yh + 1 >= 10) printf("  ");
        else printf(" ");
        for (int i = xl - 1; i <= xh + 1; i += 5) {
            printf("%d", i);
            if (i <= xh) {
                if (i < 10) printf("    ");
                else printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}