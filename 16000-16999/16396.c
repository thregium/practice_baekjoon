#include <stdio.h>

/*
문제 : 수평선상에 N(N <= 10000)개의 직선의 시작점과 끝점이 주어진다. 이때, 직선이 1개 이상 있는 구간의 길이를 구한다.
좌표의 범위는 1 이상 10000 이하이다.

해결 방법 : 좌표의 범위가 작기 때문에 직접 직선이 있는 구간을 그려보면 된다.

주요 알고리즘 : 구현

출처 : 홍익대 2018 C번
*/

int lines[10240];

int main(void) {
    int n, x, y, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        for (int j = x; j < y; j++) {
            lines[j] = 1;
        }
    }
    for (int i = 0; i < 10130; i++) {
        r += lines[i];
    }
    printf("%d", r);
    return 0;
}