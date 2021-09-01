#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10)개의 수 가운데 T(T <= 3000)를 나누어 가장 나머지가 적은 수(<= 500) 중 하나를 찾는다.

해결 방법 : 각 수들의 나머지 최솟값과 그 수를 저장해가며 풀면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : UKIEPC 2017 I번
*/

int height[16];

int main(void) {
    int n, t, best = INF, bestnum = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < n; i++) {
        if (t % height[i] < best) {
            best = t % height[i];
            bestnum = i;
        }
    }
    if (bestnum < 0) return 1;
    printf("%d", height[bestnum]);
    return 0;
}