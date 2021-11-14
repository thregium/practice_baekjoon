#include <stdio.h>

/*
문제 : N * N(N <= 10000) 범위의 좌표 안에 M(M <= 100)마리의 물고기가 있다. 이때, 둘레가 L(L <= 100) 이하인
그물을 칠 수 있다면 물고기를 최대 몇 마리 잡을 수 있는지 구한다.

해결 방법 : 각 물고기가 있는 좌표의 X좌표와 Y좌표에 대해 해당 좌표에서 시작하는 가능한 모든 그물을 쳐보면서
물고기가 가장 많이 들어갈 수 있는 경우를 찾으면 된다.

주요 알고리즘 : 브루트 포스

출처 : 정올 2013지 중2번
*/

int fish[128][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, l, m, r = 0, c, tx, ty;
    scanf("%d %d %d", &n, &l, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &fish[i][0], &fish[i][1]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            for (int k = 1; k < (l >> 1); k++) {
                c = 0;
                tx = small(fish[i][0], fish[j][0]);
                ty = small(fish[i][1], fish[j][1]);
                for (int p = 0; p < m; p++) {
                    if (fish[p][0] >= tx && fish[p][1] >= ty && fish[p][0] <= tx + k && fish[p][1] <= ty + (l >> 1) - k) c++;
                }
                if (c > r) r = c;
            }
        }
    }
    printf("%d", r);
    return 0;
}