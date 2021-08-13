#include <stdio.h>
#include <string.h>

/*
문제 : 길이 1000 이하의 숫자로 이루어진 문자열이 있다. 이 문자열의 부분 문자열 가운데 길이가 짝수이고 앞쪽 절반의 숫자 합과
뒤쪽 절반의 숫자 합이 같은 가장 긴 문자열의 길이를 구한다. 이러한 문자열을 항상 찾을 수 있다.

해결 방법 : 나올 수 있는 가장 긴 문자열부터 차례로 확인하며 길이가 짧아지는 순서로 조건을 만족하는지 확인한다.
조건을 만족하는 문자열이 나오면 해당 문자열의 길이를 출력하고 프로그램을 종료한다.

주요 알고리즘 : 브루트 포스, 문자열
*/

char s[1024];

int main(void) {
    int l, f, b;
    scanf("%s", s);
    l = strlen(s);
    for (int i = (l & 1) ? l - 1 : l; i; i -= 2) {
        for (int j = 0; j <= l - i; j++) {
            f = 0, b = 0;
            for (int k = 0; k < (i >> 1); k++) {
                f += s[j + k] - '0';
                b += s[j + k + (i >> 1)] - '0';
            }
            if (f == b) {
                printf("%d", i);
                return 0;
            }
        }
    }
    return 0;
}