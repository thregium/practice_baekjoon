#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 20)명을 두 팀으로 나누고 양 팀의 능력치 차이를 최소화하려고 한다. 각 팀에는 1명 이상 있어야 하며,
각 팀마다 i번, j번 인원이 모두 있을 때 그 팀의 능력치에 S_ij가 추가된다. S_ij는 100 이하의 정수이다.

해결 방법 : 비트마스킹을 이용한 브루트 포스로 N명 중 1명 이상 N - 1명 이하를 뽑는 모든 경우를 시도해본다.
뽑지 않은 나머지는 상대 팀으로 들어간다. 이 과정에서 비트마스킹상 2^(N - 1)이상인 수는 반대 수에 대해 대칭이므로
다시 살펴볼 필요가 없다는 점을 이용한 최적화가 가능하다.

주요 알고리즘 : 브루트 포스, 비트마스킹
*/

int s[32][32];

int main(void) {
    int n, best = INF, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    for (int i = 1; i <= (1 << n) - i; i++) {
        a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if ((i & (1 << j)) && (i & (1 << k))) a += s[j][k];
                if ((~i & (1 << j)) && (~i & (1 << k))) b += s[j][k];
            }
        }
        if (abs(a - b) < best) {
            best = abs(a - b);
        }
    }
    printf("%d", best);
    return 0;
}