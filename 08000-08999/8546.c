#include <stdio.h>

/*
문제 : N번째부터 M(N < M <= 10^7)번째까지의 피보나치 수의 마지막 자리를 전부 출력한다.

해결 방법 : 피보나치 수의 마지막 자리는 60회를 주기로 순환함을 알 수 있다. 따라서, N - 1과 M - 1의 60으로 나눈
몫과 나머지를 통해 해당 수를 반복시키면 된다.

주요 알고리즘 : 수학

출처 : PA 2002.11 1-1번
*/

char* rep = "112358314594370774156178538190998752796516730336954932572910";

int main(void) {
    int n, m, rp;
    scanf("%d %d", &n, &m);
    n--, m--;
    if (n / 60 == m / 60) {
        for (int i = n % 60; i <= m % 60; i++) printf("%c", rep[i]);
    }
    else {
        for (int i = n % 60; i < 60; i++) printf("%c", rep[i]);
        rp = m / 60 - n / 60;
        for (int i = 1; i < rp; i++) printf("%s", rep);
        for (int i = 0; i <= m % 60; i++) printf("%c", rep[i]);
    }
    return 0;
}