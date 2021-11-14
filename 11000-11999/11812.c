#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^15)개의 노드가 있는 완전 K(1 <= K <= 1000)진 트리에서 두 노드 X, Y 사이의 거리를 Q(Q <= 100000)번 구한다.

해결 방법 : 노드 번호를 x라 했을 때, 각 노드에서 (x + k - 2) / k를 구하면 부모 노드가 된다.
이를 반복해서 더 큰 번호의 노드에서 부모 노드로 가는 것을 반복하면 언젠가 두 노드가 만날 것이고,
그때까지 움직인 횟수를 구하면 된다. K >= 2에서 시간 복잡도가 logN이 되므로 대부분의 경우 괜찮지만
K = 1인 경우 시간 복잡도가 N이므로 다르게 풀어야 한다.
그러나 1진 트리는 일직선이므로 단순히 X와 Y의 차를 출력하면 간단히 풀 수 있다.

주요 알고리즘 : 수학, 트리, LCA

출처 : COCI 15/16#4 4번
*/

int main(void) {
    long long n, x, y, r = 0;
    int k, q;
    scanf("%lld %d %d", &n, &k, &q);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &x, &y);
        if (k == 1) {
            printf("%lld\n", llabs(x - y));
            continue;
        }
        r = 0;
        while (x != y) {
            if (x > y) x = (x + k - 2) / k;
            else y = (y + k - 2) / k;
            r++;
        }
        printf("%lld\n", r);
    }
    return 0;
}