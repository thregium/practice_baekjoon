#include <stdio.h>

/*
���� : ���� N(N <= 10000)�� 0���� �ʱ�ȭ�� �迭�� ���� ��, Q(Q <= 1000)���� ������ �����Ѵ�.
1. P��° ���� X�� ���Ѵ�.
2. P���� Q������ �������� ����Ѵ�.

�ذ� ��� : N�� Q�� ũ�� �ʱ� ������ ���� ���� ������Ʈ�ϰ� �������� ���ص� �ȴ�.

�ֿ� �˰��� : ����
*/

long long days[10240];

int main(void) {
    int n, q, o, p, x;
    long long s = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &p, &x);
        if (o == 1) days[p] += x;
        else {
            s = 0;
            for (int j = p; j <= x; j++) s += days[j];
            printf("%lld\n", s);
        }
    }
    return 0;
}