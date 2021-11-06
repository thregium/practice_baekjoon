#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200)개의 서로 다른 점들(|좌표 범위| <= 1000)이 주어진다. 이때, 각 점들을 이어서 만들 수 있는
평행하지 않은 선의 개수를 구한다.

해결 방법 : 각 점들의 쌍에 대해 좌표의 차이를 저장하고 X좌표가 늘어나는 방향으로 전부 바꿔둔다.
X좌표가 0인 경우 Y좌표가 늘어나는 방향으로 바꾼다. 그 후, 각 쌍들을 각도에 따라 정렬해둔 다음,
모든 쌍에 대해 각도가 같지 않은 쌍들을 세면 된다.

주요 알고리즘 : 수학, 정렬, 브루트 포스

출처 : USACO 2008F S1번
*/

int point[256][2], line[32768][2];

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int ay = *((int*)a + 1);
    int bx = *(int*)b;
    int by = *((int*)b + 1);
    return ax * by > bx * ay ? 1 : ax * by == bx * ay ? 0 : -1;
}

int main(void) {
    int n, lp = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            line[lp][0] = point[i][0] - point[j][0];
            line[lp][1] = point[i][1] - point[j][1];
            if (line[lp][0] < 0) {
                line[lp][0] *= -1;
                line[lp][1] *= -1;
            }
            else if (line[lp][0] == 0) line[lp][1] = 1;
            lp++;
        }
    }
    qsort(line, lp, sizeof(int) * 2, cmp1);

    for (int i = 0; i < lp; i++) {
        if (i > 0 && line[i][0] * line[i - 1][1] == line[i][1] * line[i - 1][0]) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}