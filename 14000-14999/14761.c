#include <stdio.h>

/*
���� : 1���� N(N <= 100)������ ���� ����ϵ�, X�� ������ �������� ��쿡�� Fizz, Y(X < Y <= N)�� ������ �������� ��쿡�� Buzz,
�� �ٷ� ������ �������� ��쿡�� FizzBuzz�� ��� ����Ѵ�.

�ذ� ��� : 1���� N������ ���� for���� �̿��� ���� x�� y�� ������ �������� FizzBuzz, �� �ܿ� X�� ������ �������� Fizz,
Y�� ������ �������� Buzz, �� �ܿ��� i�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Rocky 2016 A��
*/

int main(void) {
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    for (int i = 1; i <= n; i++) {
        if (i % x == 0 && i % y == 0) printf("FizzBuzz\n");
        else if (i % x == 0) printf("Fizz\n");
        else if (i % y == 0) printf("Buzz\n");
        else printf("%d\n", i);
    }
    return 0;
}