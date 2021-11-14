#include <stdio.h>

/*
문제 : N(N <= 1000)개의 수에 대해 1 이상 N 이하의 수로 이루어진 수열이 주어진다. 이때, 수열의 수를 계속 따라갈 때,
나오는 수의 개수가 가장 많은 수 가운데 가장 작은 수를 구한다.

해결 방법 : 각 수마다 만날 수 있는 수의 개수를 이미 방문한 수가 나올 때 까지 센 다음 그러한 값이 가장 큰 수를 찾으면 된다.

주요 알고리즘 : 그래프 이론, 브루트 포스

출처 : CHCI 2005RJ 2번
*/

int a[1024], vis[1024];

int main(void) {
    int n, r = 0, rn = -1, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        t = 0;
        for (int j = i; !vis[j]; j = a[j]) vis[j] = 1;
        for (int j = 1; j <= n; j++) {
            t += vis[j];
            vis[j] = 0;
        }
        if (t > r) {
            r = t;
            rn = i;
        }
    }
    if (rn < 0) return 1;
    printf("%d", rn);
    return 0;
}