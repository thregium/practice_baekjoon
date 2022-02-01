#include <stdio.h>
#define HI 1234567890987654321

/*
문제 : 무한히 많은 정수들이 0부터 순서대로 있고, 각 수들 중 K(2 <= K <= 100000)의 배수 번호의 수들을
지운 다음, 남은 수들을 0부터 다시 번호를 붙이는 것을 반복했을 때, N(N <= 100000)번째 행동에서
0번에 있는 수는 원래 몇 번이었는지 구한다. 답이 10^18 이하인 경우만 주어진다.

해결 방법 : 매개 변수 탐색을 통해 N번 행동을 한 후 수가 남는 지 여부를 확인하면서
그러한 수 가운데 가장 작은 것을 구하면 답이 된다. 최솟값은 0, 최댓값은 10^18로 잡을 수 있다.

주요 알고리즘 : 수학, 파라메트릭

출처 : JAG 2015S2 B번
*/

long long living(long long n, long long k, long long x) {
    if (n == 0) return 1;
    for (int i = 1; i < n; i++) {
        x -= x / k + 1;
    }
    return (x > 0);
}

int main(void) {
    int n, k;
    long long hi = HI, lo = 0, mid;
    scanf("%d %d", &n, &k);
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (living(n - 1, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    while (lo == HI);
    printf("%lld\n", lo);
    return 0;
}