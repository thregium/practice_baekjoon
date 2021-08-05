#include <stdio.h>

/*
문제 : 1부터 N(N <= 100)까지의 수를 출력하되, X로 나누어 떨어지는 경우에는 Fizz, Y(X < Y <= N)로 나누어 떨어지는 경우에는 Buzz,
둘 다로 나누어 떨어지는 경우에는 FizzBuzz를 대신 출력한다.

해결 방법 : 1부터 N까지의 수를 for문을 이용해 돌며 x와 y로 나누어 떨어지면 FizzBuzz, 그 외에 X로 나누어 떨어지면 Fizz,
Y로 나누어 떨어지면 Buzz, 그 외에는 i를 출력하면 된다.

주요 알고리즘 : 구현

출처 : Rocky 2016 A번
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