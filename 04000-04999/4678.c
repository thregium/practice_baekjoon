#include <stdio.h>
#include <string.h>

/*
문제 : 치우친 이진수 문자열이 주어질 때, 이를 십진수로 바꾼 결과를 출력한다. 답은 2^31보다 작다.

해결 방법 : 맨 뒷 자리부터 차례로 자릿수를 더해나간다.

주요 알고리즘 : 수학, 구현, 문자열

출처 : MidC 1997 D번
*/

char s[64];

int main(void) {
    int l;
    long long n, d;
    while (1) {
        scanf("%s", s);
        l = strlen(s);
        if (l == 1 && s[0] == '0') break;

        d = 1;
        n = 0;
        for (int i = l - 1; i >= 0; i--) {
            n += (s[i] - '0') * d;
            d <<= 1;
            d++;
        }
        printf("%lld\n", n);
    }
    return 0;
}