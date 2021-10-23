#include <stdio.h>
#define INF 1012345678

/*
���� : ���� N(N <= 100)�� �迭���� ������ K(K <= N)�� ���� �� ��� ���� ū ���� ����.
�迭�� �ִ� ������ -100 �̻� 100 ������ �����̴�.

�ذ� ��� : �ִ��� -���Ѵ�� ������ �� ������ K���� ������ ���ʷ� Ȯ���ϸ� ���� ū ���� ã�ư��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����
*/

int tem[128];

int main(void) {
    int n, k, s, best = -INF;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tem[i]);
    }
    for (int i = 0; i < n - k + 1; i++) {
        s = 0;
        for (int j = 0; j < k; j++) {
            s += tem[i + j];
        }
        if (s > best) best = s;
    }
    if (best == -INF) return 1;
    printf("%d", best);
    return 0;
}