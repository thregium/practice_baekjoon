#include <stdio.h>
#include <stdlib.h>

/*
문제 : 3 * N(N <= 300)개의 점이 주어질 때, 서로 겹치지 않는 삼각형 N개를 만드는 방법을 출력한다.
단, 3개의 점이 일직선상에 있는 경우는 주어지지 않는다.

해결 방법 : 각 점들이 일적선상에 최대 2개만 있을 수 있기 때문에 X축을 기준으로 정렬하면 같은 X축에서
점이 2개까지만 있고, 3개씩 묶어서 삼각형을 만들 수 있다. X축 -> Y축 순서로 정렬하면 서로 겹치지 않도록 만들어지게 된다.

주요 알고리즘 : 그리디 알고리즘, 기하학, 구성적

출처 : kriii 1회 D번
*/

int point[1024][3];

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    if (ax != bx) return ax > bx ? 1 : -1;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    return ay > by ? 1 : ay == by ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 3; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
        point[i][2] = i + 1;
    }
    qsort(point, n * 3, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", point[i * 3][2], point[i * 3 + 1][2], point[i * 3 + 2][2]);
    }
    return 0;
}