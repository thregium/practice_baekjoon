#include <stdio.h>
#include <string.h>

/*
문제 : 8자리 이하의 짝수 자리 수 N이 주어질 때, 이 수의 앞쪽 절반 자릿수의 합과 뒤쪽 절반 자릿수의 합이 같은지 확인한다.

해결 방법 : 자릿수를 확인하고 앞쪽 자릿수의 합과 뒤쪽 자릿수의 합을 구한 다음 같은지 보면 된다.

주요 알고리즘 : 문자열, 구현
*/

char n[16];

int main(void) {
    int l, sl = 0, sr = 0;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; i < l / 2; i++) sl += n[i] - '0';
    for (int i = l / 2; i < l; i++) sr += n[i] - '0';
    if (sl == sr) printf("LUCKY");
    else printf("READY");
    return 0;
}