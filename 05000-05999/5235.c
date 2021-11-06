#include <stdio.h>

/*
문제 : K(K < 100)개의 음이 아닌 정수(< 2^20)가 주어질 때, 홀수와 짝수 중 어느 쪽의 합이 더 큰지(또는 둘이 같은지) 구한다.
이를 T(T <= 50)번 반복한다.

해결 방법 : 홀수와 짝수의 합을 따로 0으로 초기화한 뒤, 받은 수가 홀수면 홀수의 합에, 짝수면 짝수의 합에 더한다.
전부 확인한 뒤에는 어느 쪽이 더 큰지 확인한 후 답을 구하면 된다.

주요 알고리즘 : 구현

출처 : MHSPC 2011 P1번
*/

int main(void) {
    int t, k, n, o, e;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        o = 0, e = 0;
        for (int i = 0; i < k; i++) {
            scanf("%d", &n);
            if (n & 1) o += n;
            else e += n;
        }
        if (o > e) printf("ODD\n");
        else if (e > o) printf("EVEN\n");
        else printf("TIE\n");
    }
    return 0;
}