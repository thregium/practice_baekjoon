#include <stdio.h>

/*
문제 : 높이 N(N <= 10000)의 삼각형 내의 삼각형 개수를 구한다.

해결 방법 : 규칙을 찾아서 위와 아래 삼각형으로 나누어 풀면 된다.

주요 알고리즘 : 수학

출처 : 한양대E 2018 4번
*/

int main(void) {
    int n;
    long long r = 0, s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        s += i;
        r += s;
    }
    s = 0;
    for (int i = 1; i <= n - 1; i++) s += i;
    for (int i = n - 1; i > 0; i -= 2) {
        r += s;
        s -= 2 * i - 1;
    }
    printf("%lld", r);
    return 0;
}