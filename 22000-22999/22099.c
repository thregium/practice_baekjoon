#include <stdio.h>

/*
문제 : A * B(A, B <= 10^9) 크기의 직사각형을 잘라 넓이가 S(S <= 10^9)인 직사각형을
만들 수 있는 지 확인한다. 자르지 않는 것도 가능하다.

해결 방법 : 1부터 sqrt(S)까지 가능한 모든 넓이가 S인 직사각형의 높이와 너비를 하나씩 찾아나간다.
그 중 하나라도 A, B 범위 내에 들어오는 것이 있다면 그렇게 자르면 되고,
없는 경우 자르는 방법이 없는 것이다.

주요 알고리즘 : 수학, 소인수분해

출처 : RCC 2014Q3 B번
*/

int main(void) {
    int t, a, b, n, res;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &a, &b, &n);
        res = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= a && n / i <= b) res = 1;
                if (i <= b && n / i <= a) res = 1;
            }
        }
        printf("%s\n", res ? "YES" : "NO");
    }
    return 0;
}