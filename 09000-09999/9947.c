#include <stdio.h>

/*
���� : N(N <= 1000)�� ���������⸦ ���� ��, ������ ���� Ƚ���� Ʋ�� Ƚ���� ���Ѵ�.

�ذ� ��� : ����� ����� ������ ���� ����̰� �ٸ��� Ʋ�� ����̴�. �� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2007 A��
*/

char p1[32], p2[32];

int main(void) {
    int n, r1, r2;
    char c1, c2;
    while (1) {
        scanf("%s %s", p1, p2);
        if (p1[0] == '#') break;
        scanf("%d", &n);
        r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %c %c", &c1, &c2);
            if (c1 == c2) r1++;
            else r2++;
        }
        printf("%s %d %s %d\n", p1, r1, p2, r2);
    }
    return 0;
}