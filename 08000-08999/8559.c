#include <stdio.h>
#include <string.h>

/*
문제 : 2^N(0 <= N <= 10^40)의 마지막 자리 값을 구한다.

해결 방법 : N이 0인 경우 답은 1이다. N이 1 이상인 경우는 답이 2, 4, 8, 6이 반복되는 것을 알 수 있고,
이는 4로 나눈 나머지를 통해 알 수 있다. 그런데 100은 4의 배수이기 때문에 마지막 2자리의 값만 보면 답을 구할 수 있다.
이때, N이 한 자리인 경우에 주의해야 한다.

주요 알고리즘 : 수학, 정수론, 문자열

출처 : PA 2001 1-1번
*/

char n[64];

int main(void) {
    int len, last;
    scanf("%s", n);
    len = strlen(n);
    if (len == 1 && n[0] == '0') printf("1");
    else {
        last = (len == 1 ? 0 : n[len - 2] - '0') * 10 + n[len - 1];
        if (last % 4 == 0) printf("6");
        else if (last % 4 == 1) printf("2");
        else if (last % 4 == 2) printf("4");
        else printf("8");
    }
    return 0;
}