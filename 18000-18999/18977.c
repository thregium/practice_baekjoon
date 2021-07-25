#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^6)�� ���� ���� N�̰� ������ N�� ����� �� �ڿ����� �ִ��� Ȯ���ϰ� �ִٸ� �� �ڿ����� ��
���� ���� ū ���� ���Ѵ�.

�ذ� ��� : �ڿ��� N�� ���� N�̰� ������ N�� ����� �� �ڿ����� ��Ÿ���� ����� �� �� ���� ���̴�.
�� ���� ��� N / 3�̰ų� �� ���� N / 2, ������ �� ���� N / 4�� ����̴�. ���ڴ� N�� 3�� ������� �ϰ�,
���ڴ� N�� 4�� ������� �Ѵ�. ����, �� �� �ƴ� ��� ��Ÿ�� �� ����. ����, �� �� �ش��ϴ� ��쿡��
���ڰ� ���� ���� ũ�Ƿ� ���ڸ� �����ϸ� �ȴ�.

�ֿ� �˰����� : ����, �ֵ� Ȥ

��ó : Petro 2018S4 A��
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n % 3 == 0) printf("%lld\n", (long long)n * n * n / 27);
        else if ((n & 3) == 0) printf("%lld\n", (((long long)n * n * n) >> 5));
        else printf("-1\n");
    }
    return 0;
}