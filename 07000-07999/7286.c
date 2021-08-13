#include <stdio.h>

/*
���� : N(N <= 26)���� �ڿ��� ���� [lo, hi)(hi <= 1000)�� ���� ���ԵǴ� ��� �ڿ����� ���� ���ԵǴ� ������ ������ ���ĺ� ���·� ����Ѵ�.

�ذ� ��� : 0���� ���ʷ� �� �ڿ����� ���� ��� �������� Ȯ���ϸ� ���ԵǴ� ���� �� ������ ���Ѵ�.

�ֿ� �˰��� : ����

��ó : Tehran 2005 A��
*/

int itvs[32][2];

int main(void) {
    int t, n, r;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c %d %d", &c, &itvs[i][0], &itvs[i][1]);
        }
        for (int i = 0; i <= 1000; i++) {
            r = 0;
            for (int j = 0; j < n; j++) {
                if (i >= itvs[j][0] && i < itvs[j][1]) r++;
            }
            if (r > 0) printf("%c", 'A' + r - 1);
        }
        printf("\n");
    }
    return 0;
}