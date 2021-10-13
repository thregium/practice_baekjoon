#include <stdio.h>

/*
문제 : 5 * 7 크기의 그림이 N(N <= 50)개 주어진다. 이때, 가장 차이(다른 칸)가 적은 그림의 쌍을 구한다.
이러한 쌍은 유일하다.

해결 방법 : 차이를 35보다 큰 수로 초기화한 다음, 모든 쌍을 돌며 현재의 차이 값보다 차이가 적은 그림 쌍을 만나면
차이를 해당 수로 갱신하고 그때의 쌍을 저장한다. 마지막에 저장된 쌍이 답이 된다.

주요 알고리즘 : 브루트 포스, 구현
*/

char pict[64][8][8];

int main(void) {
    int n, d, b1 = -1, b2 = -1, bn = 103000;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%s", pict[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            d = 0;
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 7; l++) {
                    d += (pict[i][k][l] != pict[j][k][l]);
                }
            }
            if (d < bn) {
                b1 = i;
                b2 = j;
                bn = d;
            }
        }
    }
    printf("%d %d", b1, b2);
    return 0;
}