#include <stdio.h>

/*
���� : ���� N(N < 1000)�� �� ���� �����ϴ� ���� X, Y�� �ִ�. �̶�, X[i] >= Y[j]�̸� i > j�� �� �� ���� ������ �Ÿ���
i - j, �� �� ��� �Ÿ��� 0���� �����Ѵٸ� �� ������ ���ҵ� ������ �Ÿ� �� ���� ū ���� ã�´�.

�ذ� ��� : ���Ʈ ������ ���� �� ������ ��� ���� ���� ã�ƺ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : CCC 1996 5��
*/

int x[1024], y[1024];

int main(void) {
    int t, n, d;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        d = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &y[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (y[j] < x[i]) break;
                if (j - i > d) d = j - i;
            }
        }
        printf("The maximum distance is %d\n\n", d);
    }
    return 0;
}