#include <stdio.h>

/*
문제 : 1부터 N(N <= 100000)까지의 자연수에서 숫자 D가 몇 번 쓰였는지 구한다.

해결 방법 : 1부터 N까지의 모든 자연수를 확인해 가며 숫자가 D인 것을 세어 나간다.

주요 알고리즘 : 수학, 브루트 포스

출처 : 한양대 2017B D번
*/

int main(void) {
    int n, d, r = 0;
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j; j /= 10) r += (j % 10 == d);
    }
    printf("%d", r);
    return 0;
}