#include <stdio.h>

/*
문제 : T(T < 100)개의 (자연수(< 10^16)와 체크 비트)가 주어질 때, 체크 비트가 유효한지(비트 개수와 패리티가 맞는지) 구한다.

해결 방법 : 자연수에서 1인 비트의 수는 2로 나누어 가며 2로 나눈 나머지를 더하면 된다.
이 값을 2로 나눈 나머지를 취하고, 체크 비트와 같은지 확인하면 된다.

주요 알고리즘 : 수학, 구현

출처 : HSPCM 2012 1번
*/

int main(void) {
    int t, n, b, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &b);
        s = 0;
        while (n) {
            s += (n & 1);
            n >>= 1;
        }
        s &= 1;
        if (b == s) printf("Valid\n");
        else printf("Corrupt\n");
    }
    return 0;
}