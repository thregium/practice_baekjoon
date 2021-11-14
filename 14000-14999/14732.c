#include <stdio.h>

/*
문제 : N(N <= 100)개의 직사각형에 대해 합집합의 면적을 구한다. 각 직사각형의 좌표는 0 이상 500 이하의 정수로 주어진다.

해결 방법 : 500 * 500 크기의 배열에 직사각형이 나올 때 마다 직사각형 범위를 체크하고,
모든 직사각형의 체크가 끝나고 난 후 체크된 칸의 수를 세면 된다.

주요 알고리즘 : 구현

출처 : 중앙대 2017P G번
*/

char chk[512][512];

int main(void) {
    int n, x1, y1, x2, y2, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) chk[j][k] = 1;
        }
    }
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) r += chk[i][j];
    }
    printf("%d", r);
    return 0;
}