#include <stdio.h>

/*
문제 : N * N(N <= 1000) 크기의 배열에 문자들을 적어두고 구멍이 난 판을 시계방향으로 돌려가며 문자들을 읽었다.
이때, 읽은 문자들을 순서대로 출력한다.

해결 방법 : 판을 4개의 방향으로 돌려가며 구멍이 있는 칸들을 저장해둔다. 각 방향마다 읽기 방향대로 구멍을 찾아가며
구멍이 있는 칸마다의 문자들을 출력하면 된다.

주요 알고리즘 : 구현

출처 : CERC 2011 H번
*/

char hole[4][1024][1024], ciph[1024][1024];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", hole[0][i]);
        }
        for (int i = 1; i <= 3; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    hole[i][j][k] = hole[i - 1][n - k - 1][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", ciph[i]);
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (hole[i][j][k] == 'O') printf("%c", ciph[j][k]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}