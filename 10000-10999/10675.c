#include <stdio.h>
#define INF 1012345678

/*
���� : �־��� N(N <= 100)���� ��Ʈ �� A���� B�� �� �� �ִ� ���� ������ �� ��Ʈ�� ã�´�.
�� ��Ʈ������ �� �������� �湮�ϸ�, �ѹ� �湮�ߴ� ������ �湮���� �ʴ´�.

�ذ� ��� : �� ��Ʈ���� �ѹ� �湮�ߴ� ������ �ٽ� �湮���� �ʱ� ������ A�� �湮�� �� B�� �湮�� ��Ʈ�� ����
���� �� ��Ʈ�� ã���� �ȴ�.

�ֿ� �˰��� : ����

��ó : USACO 2015J B1��
*/

int main(void) {
    int a, b, n, best = INF, c, cn, x, fa, fb;
    scanf("%d %d %d", &a, &b, &n);
    if (a == b) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &cn);
        fa = 0, fb = 0;
        for (int j = 0; j < cn; j++) {
            scanf("%d", &x);
            if (x == a) fa = 1;
            if (x == b && fa) fb = 1;
        }
        if (fb && c < best) best = c;
    }
    if (best == INF) printf("-1");
    else printf("%d", best);
    return 0;
}