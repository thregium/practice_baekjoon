#include <stdio.h>

/*
문제 : K(K <= 10^6)자리 이하의 모든 이진수의 합을 이진수로 출력한다.

해결 방법 : 그 값을 계산하면 1부터 2^K - 1까지의 합이고, 등차수열의 합을 계산하면 (2^K - 1)(2^(K - 1))이다.
이를 붙이면 앞쪽엔 1이 K개인 수 뒤에 0을 K - 1개 붙인 수가 된다.

주요 알고리즘 : 수학

출처 : ILOCAMP 2010I 4-3번
*/

int main(void) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) printf("1");
    for (int i = 1; i < k; i++) printf("0");
    return 0;
}