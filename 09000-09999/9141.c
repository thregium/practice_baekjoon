#include <stdio.h>

/*
문제 : N * N(N <= 15 * 10^8) 크기의 도넛 형태 체스판에서 N개의 퀸을 서로 공격하지 않게
배치하는 방법이 있는 지 구한다.

해결 방법 : 브루트 포스로 15 * 15까지 답이 있는 지 확인해 보면
6회 단위로 답이 반복됨을 알 수 있다. N이 2나 3으로 나누어 떨어지지 않으면 배치 가능하고,
그 외에는 배치 불가능하다.

주요 알고리즘 : 애드 혹?

출처 : CTU 2001 G번
*/

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("Kralovny %s.\n", (n % 2) && (n % 3) ? "lze umistit" : "se nevejdou");
    }
    return 0;
}