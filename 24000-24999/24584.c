#include <stdio.h>
#include <string.h>

/*
문제 : [L, H](L <= H <= 100000)번째 소수에서 6자리 이하의 P를 부분 문자열로 갖는 소수의 개수를 구한다.
모든 소수는 0으로 시작하지 않는다.

해결 방법 : 에라토스테네스의 체를 이용해 H개의 소수를 구한 다음, 모든 소수에 대해
sprintf 함수를 이용하여 문자열로 변환 후 strstr 함수를 이용해 P를 부분 문자열로 갖는 지 확인한다.
그러한 것의 개수를 세면 된다.

주요 알고리즘 : 수학, 에라토스테네스, 문자열

출처 : MidAtl 2021 H번 // NCNA 2021 C번
*/

char sieve[1572864], n[16], x[16];
int prime[103000];
int pp = 0;

int main(void) {
    int l, h, r = 0;
    for (int i = 2; i < 1300000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j < 1300000; j += i) sieve[j] = 1;
    }
    scanf("%d %d", &l, &h);
    scanf("%s", n);
    for (int i = l - 1; i < h; i++) {
        sprintf(x, "%d", prime[i]);
        if (strstr(x, n)) r++;
    }
    printf("%d", r);
    return 0;
}