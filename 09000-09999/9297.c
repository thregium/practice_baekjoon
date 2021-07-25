#include <stdio.h>

/*
문제 : 주어진 분수를 대분수로 고친다.

해결 방법 : 자연수 부분은 분자 / 분모이고, 분수의 분자 부분은 분자 % 분모이다. 분자 부분이 0이라면 자연수만 출력하고,
자연수 부분이 0이라면 분수만 출력, 그 외에는 전부 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : UVa 2012 B번
*/

int main(void) {
    int t, n, d;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &d);
        printf("Case %d: ", tt);
        if (n % d == 0) printf("%d\n", n / d);
        else if (n / d == 0) printf("%d/%d\n", n, d);
        else printf("%d %d/%d\n", n / d, n % d, d);
    }
    return 0;
}