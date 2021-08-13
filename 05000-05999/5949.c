#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 2 * 10^9 이하의 자연수에 콤마를 찍는다.

해결 방법 : 주어진 수의 자릿수를 확인한 다음, 뒤에서 3의 배수번째마다 ,를 찍으면 된다. 마지막에는 찍지 않는다.

주요 알고리즘 : 문자열

출처 : USACO 2010D B3번
*/

char n[32];

int main(void) {
    int l;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; i < l; i++) {
        printf("%c", n[i]);
        if (i == l - 1) break;
        if ((l - i - 1) % 3 == 0) printf(",");
    }
    return 0;
}