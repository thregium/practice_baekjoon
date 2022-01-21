#include <stdio.h>
#include <math.h>

/*
문제 : N개의 1부터 M까지의 수로 이루어진 주사위가 있다. 주사위를 던진 수의 합 - K만큼이 상금이고,
상금으로 최소 1만큼은 보장된다고 할 때, 상금의 기댓값을 구한다. N은 1 이상, M은 2 이하의 정수이고,
K는 N * M보다 작은 음이 아닌 정수이며, N * M * M^N의 값은 10^8보다 작다.

해결 방법 : 주어진 제한상 M^N가지 모든 경우를 살펴보더라도 시간 초과가 일어나지 않는다.
따라서 각 경우에 대해 max(주사위의 합 - K, 1)에 1 / M^N을 곱한 것을 전부 더하면 된다.

주요 알고리즘 : 수학, 확률론, 브루트 포스

출처 : Aizu 2008 B번
*/

int dice[32];

int main(void) {
    int n, m, k, c, t;
    double x, r;
    while (1) {
        scanf("%d %d %d", &n, &m, &k);
        if (n == 0) break;
        x = 1.0 / pow(m, n);
        r = 0.0, c = n, t = 0;
        for (int i = 0; i < n; i++) dice[i] = 1;
        while (!t) {
            if (c <= k) r += x;
            else r += (c - k) * x;
            dice[0]++;
            c++;
            for (int i = 0; dice[i] > m; i++) {
                if (i == n - 1) {
                    t = 1;
                    break;
                }
                dice[i + 1]++;
                dice[i] = 1;
                c -= m - 1;
            }
        }
        printf("%.9f\n", r);
    }
    return 0;
}