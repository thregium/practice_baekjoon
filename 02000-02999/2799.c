#include <stdio.h>

/*
문제 : M * N(M, N <= 100) 크기의 창문 형태가 주어질 때, 블라인드의 닫힌 정도에 따른 각 분류의 개수를 출력한다.

해결 방법 : 각 창문마다 닫힌 높이를 확인하고, 그 값을 배열에 더한다. 모든 창문을 확인하고 배열의 값들을 출력하면 된다.

주요 알고리즘 : 구현

출처 : COCI 11/12#6 2번
*/

char blind[512][512];
int cnt[5];

int main(void) {
    int m, n, t;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m * 5 + 1; i++) {
        scanf("%s", blind[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t = 0;
            for (int k = 0; k < 4; k++) {
                if (blind[i * 5 + 1 + k][j * 5 + 1] == '*') t++;
            }
            cnt[t]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}