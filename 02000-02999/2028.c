#include <stdio.h>

/*
문제 : N(N <= 1000) 이하의 수가 주어질 때, 이 수의 제곱의 맨 뒷 자리가 이 수와 같은지 구한다.

해결 방법 : N을 자릿수별로 경우를 나누어 각 수의 제곱에서 마지막 자리들이 같은지 확인하면 된다.

주요 알고리즘 : 수학, 케이스 워크

출처 : Seoul 2006I B번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n >= 100 && n * n % 1000 == n) printf("YES\n");
        else if (n < 100 && n >= 10 && n * n % 100 == n) printf("YES\n");
        else if (n < 10 && n * n % 10 == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}