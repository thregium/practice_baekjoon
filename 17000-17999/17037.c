#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 직사각형을 좌표평면상에 칠한다. 모두 칠한 다음 직사각형이 정확히 K개 겹쳐진 부분의 넓이를 구한다.
칠하는 직사각형의 좌표는 모두 0 이상 1000 이하의 정수이다.

해결 방법 : 좌표의 범위에 비해 직사각형의 개수가 많으므로 누적 합을 이용해 직사각형의 개수를 구한다.
2차원 누적합을 통해 왼쪽 위, 오른쪽 아래의 값을 1 늘이고 오른쪽 위, 왼쪽 아래의 값을 1 줄인 다음,
2차원 누적합을 구하면 모든 좌표에서 직사각형의 개수가 나오게 된다. 이제 여기서 수가 K인 부분만 찾으면 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2019F S2번
*/

int diff[1024][1024], sums[1024][1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("paintbarn.in", "r");
        fo = fopen("paintbarn.out", "w");
    }
    int n, k, x1, y1, x2, y2, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        diff[x1 + 1][y1 + 1]++;
        diff[x1 + 1][y2 + 1]--;
        diff[x2 + 1][y1 + 1]--;
        diff[x2 + 1][y2 + 1]++;
    }
    for (int i = 0; i <= 1013; i++) {
        for (int j = 1; j <= 1013; j++) {
            sums[i][j] = sums[i][j - 1] + diff[i][j];
        }
    }
    for (int i = 0; i <= 1013; i++) {
        for (int j = 1; j <= 1013; j++) {
            sums[j][i] = sums[j - 1][i] + sums[j][i];
            if (sums[j][i] == k) r++;
        }
    }
    printf("%d", r);
    return 0;
}