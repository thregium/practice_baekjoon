#include <stdio.h>

/*
문제 : X(X <= 25000)을 피보나치 진법으로 바꾼 다음 1칸씩 오른쪽으로 시프트한 수를 구한다.

해결 방법 : 1번째부터 32번째까지의 피보나치 수열을 구한 다음, 큰 수부터 차례로 수를 확인하며 큰 수부터 비트를 채워나간다.
비트가 모두 채워지면 1비트씩 민 수를 계산하고, 그 수를 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : Ulm 2008 C번
*/

int bp[32], bt[32];

int main(void) {
    int t, x, r;
    bp[0] = 1, bp[1] = 2;
    for (int i = 2; i < 32; i++) bp[i] = bp[i - 1] + bp[i - 2];
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &x);
        for (int i = 31; i >= 0; i--) {
            if (x >= bp[i]) {
                x -= bp[i];
                bt[i] = 1;
            }
            else bt[i] = 0;
        }
        r = 0;
        for (int i = 1; i < 32; i++) {
            r += bp[i - 1] * bt[i];
        }
        printf("%d\n", r);
    }
    return 0;
}