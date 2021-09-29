#include <stdio.h>

/*
문제 : N(N <= 400)개의 원의 중심 좌표와 반지름이 주어질 때, 각 원마다 그 원과 겹치는 다른 원의 개수를 구한다.

해결 방법 : 각 원의 중심 좌표를 입력받은 다음, 모든 다른 원에 대해 중심 사이의 거리가
반지름의 합보다 작은 원의 개수를 구하면 된다. 이는 피타고라스의 정리를 이용해
X좌표 차이의 제곱과 Y좌표 차이의 제곱이 거리의 제곱이라는 사실을 알면 간단히 풀 수 있다.

주요 알고리즘 : 기하학, 브루트 포스

출처 : USACO 2011J B4번
*/

int circle[512][3];

int sqr(int x) {
    return x * x;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &circle[i][0], &circle[i][1], &circle[i][2]);
    }
    for (int i = 0; i < n; i++) {
        r = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (sqr(circle[i][0] - circle[j][0]) + sqr(circle[i][1] - circle[j][1]) < sqr(circle[i][2] + circle[j][2])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}