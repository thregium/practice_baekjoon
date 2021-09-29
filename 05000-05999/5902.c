#include <stdio.h>

/*
문제 : 길이 L(L <= 10000)인 밧줄에 N(N <= 100)개의 매듭이 자연수 위치에 주어진다. 각 매듭 중 2개는 반드시 밧줄의 양 끝에 있다.
이때, 밧줄을 반으로 접었을 때, 한 쪽이 매듭이고 다른 쪽은 매듭이 없는 줄인 경우가 없도록 하는 위치의 개수를 구한다.
단, 줄의 양 끝부분은 접을 수 없다.

해결 방법 : 줄에서 매듭이 있는 위치를 표시한 다음 줄의 모든 부분을 접어본다. 이때, 자연수 + 1/2 위치도 접어야 함에 주의한다.
각 부분을 접을 때, 모든 매듭들에 대해 접은 위치와 대칭인 부분에 밧줄이 있다면 매듭이 있는지 살피고
모든 매듭에 대해 대응하는 매듭이 있다면 그 부분은 접을 수 있는 것이다. 이러한 곳의 개수를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2012F B1번
*/

int knot[128], chk[10240];

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2012_02\\folding\\10.in", "r", stdin);
    int n, l, r = 0, t;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &knot[i]);
        chk[knot[i]] = 1;
    }
    for (int i = 0; i < l; i++) {
        t = 1;
        for (int j = 0; j < n; j++) {
            if ((i * 2 - knot[j] + 1) >= 0 && (i * 2 - knot[j] + 1) <= l && !chk[i * 2 - knot[j] + 1]) {
                t = 0;
                break;
            }
        }
        r += t;
        if (i == 0) continue;

        t = 1;
        for (int j = 0; j < n; j++) {
            if ((i * 2 - knot[j]) >= 0 && (i * 2 - knot[j]) <= l && !chk[i * 2 - knot[j]]) {
                t = 0;
                break;
            }
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}