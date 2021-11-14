#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선상에 N(N <= 5000)개의 점이 있고, 각 점들은 N번 이하의 색깔을 번호로 갖고 있다.
각 점에서 같은 색인 가장 가까운 점까지의 거리의 합을 구한다. 단, 모든 점들은 같은 색인 점이 반드시 존재한다.

해결 방법 : 점들을 색상별로 분류한 다음, 각각을 정렬한다. 그리고 양 옆 점 사이 거리 가운데 더 가까운 것을 매번 선택하고
그곳까지의 거리의 합을 구해나가면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 정올 2018 초2번
*/

int dot[5120][5120];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        dot[y][++dot[y][0]] = x;
    }
    for (int i = 1; i <= n; i++) {
        if (dot[i][0] == 1) return 1;
        else if (dot[i][0] == 0) continue;
        qsort(&dot[i][1], dot[i][0], sizeof(int), cmp1);
        for (int j = 1; j <= dot[i][0]; j++) {
            if (j == 1) r += dot[i][j + 1] - dot[i][j];
            else if (j == dot[i][0]) r += dot[i][j] - dot[i][j - 1];
            else {
                r += small(dot[i][j] - dot[i][j - 1], dot[i][j + 1] - dot[i][j]);
            }
        }
    }
    printf("%d", r);
    return 0;
}