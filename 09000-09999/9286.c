#include <stdio.h>

/*
���� : M(M <= 500)���� �г��� �־��� ��, ���⿡ �� �г��� �Ǵ��� ���Ѵ�. ��, �����ϴ� ���(6�г�)�� ������� �ʴ´�.

�ذ� ��� : 6�� ������ ������� �ʰ�, ���������� 1�� �÷��ָ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Uva 2013 A��
*/

int main(void) {
    int n, m, g;
    scanf("%d", &n);
    for (int nn = 1; nn <= n; nn++) {
        scanf("%d", &m);
        printf("Case %d:\n", nn);
        for (int i = 0; i < m; i++) {
            scanf("%d", &g);
            if (g >= 6) continue;
            else printf("%d\n", g + 1);
        }
    }
    return 0;
}
