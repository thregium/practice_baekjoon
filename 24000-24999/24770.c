#include <stdio.h>

/*
���� : N(N <= 10)������ Ƽ���� ��� ��� ��� ���� ���� ���� ����.
Ƽ���� M(M <= 20)�� �Ѱ� ���� �ʴ´�.
�� ��� ����� A$�� B���� Ƽ���� ��� ���̴�. ���� ���� �� ���� ��� ���� Ƽ���� ��� ���̰�,
�� ���� ���ٸ� �� ���� Ƽ���� ��� ���̴�.

�ذ� ��� : �м��� ���·� �����Ͽ� �� ���� / �и� ū ���� ã�Ƴ����� �ȴ�.
�� �񱳴� �и�� ���ڸ� ����� ���Ͽ� ���ϴ� ������� �� �� �ִ�.

�ֿ� �˰��� : ����

��ó : VTH 2014 F��
*/

int main(void) {
    int n, m, bu, bd, u, d;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        bu = -1, bd = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &u, &d);
            if (u > m) continue;
            if (u * bd > bu * d || (u * bd == bu * d && u > bu)) {
                bu = u;
                bd = d;
            }
        }
        if (bu < 0) printf("No suitable tickets offered\n");
        else printf("Buy %d tickets for $%d\n", bu, bd);
    }
    return 0;
}
