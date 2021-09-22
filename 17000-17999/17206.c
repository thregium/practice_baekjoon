#include <stdio.h>

/*
���� : 1���� N(N <= 80000)������ ���� ��� 3�� ��� �Ǵ� 7�� ����� ���� T(T <= 100000)�� ���Ѵ�.

�ذ� ��� : �̸� 80000������ ���� ���س��� ����, N�� �Էµ� �� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : �߾Ӵ� 2019N F��
*/

long long mem[81920];

int main(void) {
    for (int i = 1; i <= 80000; i++) {
        mem[i] = mem[i - 1];
        if (i % 3 == 0 || i % 7 == 0) mem[i] += i;
    }
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", mem[n]);
    }
    return 0;
}