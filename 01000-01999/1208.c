#include <stdio.h>
#define SZ 2097152

/*
문제 : N(N <= 40)개의 수가 주어질 때, 합이 S(|S| <= 10^6)인 부분집합의 수를 구한다. 단, 공집합은 제외한다.
모든 수는 절댓값이 100000 이하이다.

해결 방법 : 수들을 절반으로 나누어 첫 번째 절반은 냅색을 통해 모든 부분집합의 경우의 수를 구해준다. 여러번 나오는 수는 등장 횟수를 저장한다.
두 번째 절반은 또다시 냅색을 한 다음 모든 부분집합에 대해 해당 집합의 합을 구한 다음 그 합과 더해서 S가 되는 부분집합의
등장 횟수를 첫 번째 절반에서 저장한 배열에서 찾아온 다음 결괏값에 더한다. 이를 반복하면 모든 경우에 대한 합이 S인 부분집합의 수가 된다.
그런데, 이때 공집합은 제외하기 때문에 S == 0인 경우에 대해서는 결괏값에서 1을 빼주어야 한다.
또한, 수들이 음수가 될 수 있으므로 실제로는 값을 더해서 음수가 되지 않도록 해야 한다.

주요 알고리즘 : DP, 냅색, MitM
*/

int a[64], sum[SZ << 1];

int main(void) {
    int n, s, tmp;
    long long r = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << (n >> 1)); i++) {
        tmp = 0;
        for (int j = 0; j < (n >> 1); j++) {
            tmp += ((i >> j) & 1) * a[j];
        }
        sum[tmp + SZ]++;
    }
    for (int i = 0; i < (1 << (n - (n >> 1))); i++) {
        tmp = 0;
        for (int j = 0; j < (n - (n >> 1)); j++) {
            tmp += ((i >> j) & 1) * a[j + (n >> 1)];
        }
        if (s - tmp >= SZ || s - tmp < SZ) continue;
        r += sum[s - tmp + SZ];
    }
    if (s == 0) r--;
    printf("%lld", r);
    return 0;
}