#include <stdio.h>

/*
문제 : N(N <= 10^9)!의 끝에 붙는 0의 개수를 구한다.

해결 방법 : N!를 소인수분해한 값에서 인수 5의 개수와 같다. 이를 구하려면 N을 5로 나눈 값과, 그를 5로 나눈 값, ...
를 반복하여 0이 될 때 까지 더한 값을 구하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : CERC 2000 F번
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = n; i; i /= 5) r += i / 5;
        printf("%d\n", r);
    }
    return 0;
}