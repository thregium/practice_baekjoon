#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100000)���� ������ 10000 ������ ������ �̷���� �迭��
���ӵ� K(K <= N)���� ���� �� ��� ���� ū ���� ���Ѵ�.

�ذ� ��� : ù K�� ������ ���� ���ϰ� �� ���ķδ� �� �� ���� ���� ���ϰ� �� �� ���� ���� ���� �ݺ��ϸ�
���� ���� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �����̵� ������

��ó : JOI 2007 1��
*/

int a[103000];

int main(void) {
    int n, k, s, r;
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d %d", &n, &k);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = -INF, s = 0;
        for (int i = 0; i < k; i++) s += a[i];
        if (s > r) r = s;
        for (int i = k; i < n; i++) {
            s += a[i] - a[i - k];
            if (s > r) r = s;
        }
        printf("%d\n", r);
    }
    return 0;
}