#include <stdio.h>

/*
���� : N(N <= 1000)���� ����(|| <= 1000)�� �־�����.
K(K <= 1000)�� ������ ����(|| <= 10^18)�� �߰��Ͽ� ��� ������ ���� ������ ��� ������ ������ ����
������ �ϴ� ����� �ִ� �� ã�� �ִٸ� �׷��� ����� ���Ѵ�.

�ذ� ��� : ���� �����ϸ� K�� 2�� ��� �ݵ�� ����� ������ �� �� �ִ�.
���� K�� 1�� ���� 2 �̻��� ��츦 ������ �� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : GCJ 2022B B��
*/

int main(void) {
    int t, n, k, x;
    long long sum, sqsum, targ;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &k);
        sum = 0, sqsum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            sum += x;
            sqsum += x * x;
        }

        if ((sqsum - sum * sum) & 1) return 1;
        if (k == 1) {
            targ = ((sqsum - sum * sum) >> 1);
            if (sum == 0 && targ == 0) printf("Case #%d: 103000\n", tt);
            else if (sum == 0 || targ % sum) printf("Case #%d: IMPOSSIBLE\n", tt);
            else printf("Case #%d: %lld\n", tt, targ / sum);
        }
        else {
            targ = ((sqsum - sum * sum) >> 1) + sum * sum;
            printf("Case #%d: %lld %lld\n", tt, 1 - sum, targ - sum);
        }
    }
    return 0;
}