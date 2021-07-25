#include <stdio.h>

/*
문제 : 파스칼의 삼각형에서 N(N <= 2 * 10^9)번째 줄의 홀수 개수를 구한다.

해결 방법 : 파스칼의 삼각형을 그려나가다 보면 2^(N에서 1인 비트 개수)와 같다는 것을 알 수 있다.

주요 알고리즘 : 수학, 정수론

출처 : ROI 2004H G번
*/

int main(void) {
    long long n, r = 0;
    scanf("%lld", &n);
    for (int i = 0; i < 32; i++) {
        if ((n >> i) & 1) r++;
    }
    printf("%lld", 1LL << r);
    return 0;
}