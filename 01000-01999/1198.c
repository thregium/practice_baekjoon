#include <stdio.h>
#include <stdlib.h>

/*
문제 : 볼록 N(N <= 35)각형의 꼭짓점의 좌표가 주어질 때, 이 도형에서 인접한 3개의 점을 삼각형으로 잘라내는 것을
반복해 만들어진 삼각형 가운데 가장 큰 것을 구한다.

해결 방법 : 어떠한 세 점을 선택하더라도 그 세 개의 점을 남기고 삼각형을 잘라낼 수 있음을 알 수 있다.
따라서, 모든 세 점을 남기는 방법을 한 번씩 해보며 삼각형의 넓이를 구해서 가장 큰 것을 찾으면 된다.

주요 알고리즘 : 기하학, 브루트 포스
*/

int point[64][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int n, r = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                r = big(r, abs(ccw(point[i][0], point[i][1], point[j][0], point[j][1], point[k][0], point[k][1])));
            }
        }
    }
    printf("%d.%d", r / 2, r % 2 * 5);
    return 0;
}
