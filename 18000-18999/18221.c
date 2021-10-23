#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * N(N <= 1000) 크기의 배열에 2가 1개, 5가 1개 있다. 이때, 2와 5 사이의 유클리드 거리가 5 이하고,
2와 5를 꼭짓점으로 하는 XY축에 평행한 직사각형 범위 안에 1이 3개 이상 있는지 구한다.

해결 방법 : 2와 5의 위치를 먼저 찾은 다음, 두 지점 사이 유클리드 거리를 피타고라스 정리를 이용해 찾는다.
이 거리가 5보다 작다면(거리의 제곱이 25보다 작다면) 조건을 만족하지 않는 것이다.
거리 조건을 만족한다면 직사각형 범위 안의 배열 값들을 탐색한다. 1을 3개 이상 발견하면 조건을 만족한 것이고,
발견하지 못했다면 조건을 만족한 것이다.

주요 알고리즘 : 구현, 기하학

출처 : 성균관대 2019 A번
*/

int desk[1024][1024];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, x2 = -1, y2 = -1, x5 = -1, y5 = -1, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &desk[i][j]);
            if (desk[i][j] == 2) {
                if (x2 >= 0) return 1;
                x2 = i;
                y2 = j;
            }
            else if (desk[i][j] == 5) {
                if (x5 >= 0) return 1;
                x5 = i;
                y5 = j;
            }
        }
    }
    if (x2 < 0 || x5 < 0) return 2;
    if (abs(x2 - x5) * abs(x2 - x5) + abs(y2 - y5) * abs(y2 - y5) < 25) {
        printf("0");
        return 0;
    }
    if (x2 > x5) swap(&x2, &x5);
    if (y2 > y5) swap(&y2, &y5);
    for (int i = x2; i <= x5; i++) {
        for (int j = y2; j <= y5; j++) {
            if (desk[i][j] == 1) cnt++;
        }
    }
    printf("%d", cnt >= 3);
    return 0;
}