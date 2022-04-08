#include <stdio.h>

/*
문제 : N * N(N <= 10) 크기의 배열에 1부터 N * N까지의 수가 1개씩 쓰여있다.
위와 왼쪽에서 수들을 앞에서부터 증가하는 수들만 볼 때, 보는 수의 개수를 각 줄마다 구한다.

해결 방법 : 현재까지의 최댓값과 개수를 확인하면서 계산해나가면 된다.

주요 알고리즘 : 구현

출처 : INC 2020 A번
*/

int a[16][16];

int main(void) {
    int n, h, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        r = 0, h = -1;
        for (int j = 0; j < n; j++) {
            if (a[j][i] > h) {
                r++;
                h = a[j][i];
            }
        }
        printf("%d ", r);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        r = 0, h = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] > h) {
                r++;
                h = a[i][j];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}