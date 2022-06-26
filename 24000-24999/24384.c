#include <stdio.h>

/*
문제 : 자연수 K(K <= 10^6)가 주어질 때, 1부터 각 자연수의 세제곱을 이어붙인 문자열의 K번째 문자를 구한다.

해결 방법 : 직접 이 문자열을 만든 다음, k번째 문자의 값을 찾으면 된다.
단, strcat을 사용하지 않고 직접 다음 문자열에 붙여야 시간을 절약할 수 있다.

주요 알고리즘 : 구현, 시뮬레이션, 문자열

출처 : IATI 2013D 2번
*/

char s[1048576];

int main(void) {
    int k, l = 0;
    long long n = 1;
    scanf("%d", &k);
    while (l < k) {
        sprintf(s + l, "%lld", n * n * n);
        while (s[l] != '\0') l++;
        n++;
    }
    printf("%c", s[k - 1]);
    return 0;
}