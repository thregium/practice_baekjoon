#include <stdio.h>
#include <ctype.h>

/*
문제 : N * N(N <= 1000) 크기의 격자에 지뢰의 정보가 주어질 때, 주변 칸에 있는 지뢰의 수를 출력하는 프로그램을 만든다.

해결 방법 : 문제에 주어진대로 구현한다. 방향 배열을 이용하면 주변 칸들을 빠르게 탐색할 수 있고,
배열을 1칸 띄어두고 입력받으면 배열 범위를 벗어나지 않고 주변 칸들을 탐색할 수 있다.

주요 알고리즘 : 구현
*/

char mf[1024][1024];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mf[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r = 0;
            for (int d = 0; d < 8; d++) {
                if (isdigit(mf[i + dxy[d][0]][j + dxy[d][1]])) {
                    r += mf[i + dxy[d][0]][j + dxy[d][1]] - '0';
                }
            }
            if (isdigit(mf[i][j])) printf("*");
            else if (r >= 10) printf("M");
            else printf("%d", r);
        }
        printf("\n");
    }
    return 0;
}