#include <stdio.h>

/*
���� : N(N <= 25 * 10^8)���� ���� ��Ģ�� �°� ���� ����� ���Ѵ�. ���ٸ� Love is open door�� ����Ѵ�. (��Ģ ����)

�ذ� ��� : N�� 6 �̻��� ��쿡�� ��Ģ�� �°� ���� ����� �������� �ʴ´�. �� �ܿ��� ������׷� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : �Ѿ��E 2019R A��
*/

int main(void) {
    long long n, x;
    scanf("%lld %lld", &n, &x);
    if (n > 5) printf("Love is open door");
    else {
        for (int i = 1; i < n; i++) {
            x = !x;
            printf("%lld\n", x);
        }
    }
    return 0;
}