#include <stdio.h>

/*
문제 : N(N <= 200)까지의 자연수들 가운데 M(M <= 10000)가지의 같이 있을 수 없는 조합을 제외하고 3개를 뽑는 조합의 가짓수를 구한다.

해결 방법 : 3개를 직접 뽑아보며 같이 있을 수 없는 조합을 제외하고 개수를 세면 된다.

주요 알고리즘 : 브루트 포스

출처 : BtOI 2011 2번
*/

int mix[256][256];

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        mix[a][b] = 1;
        mix[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (mix[i][j]) continue;
            for (int k = j + 1; k <= n; k++) {
                if (mix[i][k] || mix[j][k]) continue;
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}