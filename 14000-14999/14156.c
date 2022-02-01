#include <stdio.h>

/*
문제 : N(N <= 16) 길이의 비트 문자열을 1글자씩만 바꾸며 모든 비트 문자열을 나열하는 방법을 출력한다.
같은 문자열이 나와서는 안 된다.

해결 방법 : 0에서 시작해 해당 번째의 LSB를 뒤집어 나가면 1씩 더하는 것과 비슷한 원리로
모든 비트 문자열을 나열할 수 있다.

주요 알고리즘 : 수학, 비트마스킹, 구성적

출처 : CPC 2007 B번
*/

char r[32];

int main(void) {
    int n, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) r[i] = '0';
    for (int i = 1; i < (1 << n); i++) {
        printf("%s\n", r);
        p = 0;
        for (int j = i; ~j & 1; j >>= 1) p++;
        r[p] = (!(r[p] - '0')) + '0';
    }
    printf("%s\n", r);
    return 0;
}