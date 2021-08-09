#include <stdio.h>
#define INF 1012345678

/*
문제 : 부피가 N(N <= 10^6)이며 모든 변의 길이가 자연수인 직육면체 가운데 가장 겉넓이가 작은 것을 구한다.

해결 방법 : 겉넓이를 무한대로 초기화한 후 부피가 N인 직육면체 가운데 겉넓이가 더 작은 것이 나올 때 마다
세 변의 길이를 갱신해주면 된다. 직육면체를 탐색할 때에는 부피가 N을 넘을 것으로 확인되는 경우 바로 탈출해 주어야
시간 복잡도를 보장할 수 있다.

주요 알고리즘 : 수학, 브루트 포스

출처 : NWRRC 2007 B번
*/

int main(void) {
    int n, best = INF, a = 0, b = 0, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            for (int k = 1; i * j * k <= n; k++) {
                if (i * j * k != n) continue;
                if (i * j + i * k + j * k < best) {
                    best = i * j + i * k + j * k;
                    a = i;
                    b = j;
                    c = k;
                }
            }
        }
    }
    printf("%d %d %d", a, b, c);
    return 0;
}