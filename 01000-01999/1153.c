#include <stdio.h>

/*
���� : �ڿ��� N(N <= 1000000)�� �־��� ��, �� ���� �� �Ҽ��� ������ ���� �� �ִ��� ���ϰ� �ִٸ� �� ��� �� �ϳ��� ����Ѵ�.

�ذ� ��� : 4 �̻��� ��� ¦���� �� �Ҽ��� ������ ���� �� �ִٴ� �������� ������ �̿��Ѵ�. ���������� �ʾ�����,
�ּ��� long long ���� �������� �׻� ������ �˷��� �ִ�. N�� Ȧ���� ��� 2, 3�� �Ͽ� ¦���� �����, ¦���� ���
2, 2�� �Ͽ� ¦���� �����ϸ� �ȴ�. �� �������� �ݵ�� N - 4 �Ǵ� 5�� ��� �Ҽ��� ���� �����ϴ� ���� �ݵ�� �Ҽ��� �� ���� ���� ���̴�.

�ֿ� �˰����� : ����, ������, �������� ����
*/

char sieve[1048576];

int main(void) {
    int n;
    scanf("%d", &n);
    if (n < 10) {
        if (n < 8) printf("-1");
        else if (n == 8) printf("2 2 2 2");
        else printf("2 2 2 3");
        return 0;
    }

    if (n & 1) {
        printf("2 3 ");
        n -= 5;
    }
    else {
        printf("2 2 ");
        n -= 4;
    }
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    for (int i = 3; i * 2 <= n; i += 2) {
        if (sieve[i] == 0 && sieve[n - i] == 0) {
            printf("%d %d", i, n - i);
            break;
        }
    }
    return 0;
}