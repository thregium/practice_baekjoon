#include <stdio.h>
#define INF 1234567890987654321

/*
���� : N * N(N <= 18) ũ�� ��Ŀ� ���� 10^9 ���� �������� �����ִ�.
�� ���� ���� ����� �����ϰ� �ٸ� �� ���� ������ �����Ѵ�. �� ���� ������ ĭ����
���� ������ ����� ������ �ǰ�, �� �� ĭ�� ���� ������ ����� ������ �ȴٰ� �� ��,
���� �����ϴ� ����� �ִ� ������ ���Ѵ�. �θ��� ������ �ǵ��� ��� ���� �����Ѵ�.

�ذ� ��� : ������ �� ���� ��� ����� ���� ������ ����, ���� �����ϴ� ������ �ּ����� �Ǵ� ���
(�� �ٿ� ���� ������ ���� �������� ���� �� ��� �ּڰ��� ��)�� ������ ���Ѵ�.
�� ������ ��� �ִ��� ���ϸ� ���� �ȴ�. �������� ������ �ؾ� �Կ� �����Ѵ�.

�ֿ� �˰����� : ���Ʈ ����, �׸��� �˰�����

��ó : DGIST 2022 D��
*/

long long a[32][32];

int main(void) {
    int n;
    long long sum, ssum, usum, res = -INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            ssum = 0, usum = 0;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) ssum += a[k][j];
                else usum += a[k][j];
            }
            if (ssum < usum) sum += ssum;
            else sum += usum;
        }
        if (sum > res) res = sum;
    }
    printf("%lld", res);
    return 0;
}