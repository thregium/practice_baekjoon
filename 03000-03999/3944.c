#include <stdio.h>

/*
문제 : 10^7자 이하의 B(2 <= B <= 10)진법 수가 주어질 때, 이 수를 B - 1로 나눈 나머지를 구한다.

해결 방법 : 그 값은 모든 자릿수의 합을 B - 1로 나눈 나머지와 같다. 따라서 그 값을 구하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : GNY 2012 B번
*/

char s[10485760];

int main(void) {
    int t, b, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %s", &b, s);
        r = 0;
        for (int i = 0; s[i]; i++) r += s[i] - '0';
        printf("%d\n", r % (b - 1));
    }
    return 0;
}