#include <stdio.h>

/*
문제 : D * W(3 <= D, W <= 10) 크기 땅의 지형이 주어질 때, 만들 수 있는 가장 수량이 많은 연못의 수량을 구한다.
연못은 직사각형의 형태여야 하며, 테두리 지역의 모든 땅이 내부 지역의 모든 땅보다 높은 지대에 있어야 한다.
연못의 수량은 안의 모든 땅에 대해 테두리 지역의 가장 낮은 높이와의 차의 합이다.

해결 방법 : 연못을 만들 수 있는 모든 범위의 땅에 대해 연못을 만들 수 있는 지 먼저 검사한다.
내부 지역의 가장 높은 땅과 외부 지역의 가장 낮은 땅의 높이를 확인하고, 외부의 가장 낮은 땅이 더 높은 지 확인하면 된다.
연못을 만들 수 있다면 수량을 확인한다. 수량은 문제에 설명된 대로 확인한다. 그 수량이 가장 큰 것을 찾으면 답이 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : JDC 2017 C번
*/

int elev[16][16];

int main(void) {
    int d, w, r, ih, ol, cap;
    while (1) {
        scanf("%d %d", &d, &w);
        if (d == 0) break;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &elev[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                for (int ii = i + 2; ii < d; ii++) {
                    for (int jj = j + 2; jj < w; jj++) {
                        ol = 100, ih = -100;
                        for (int x = i; x <= ii; x++) {
                            for (int y = j; y <= jj; y++) {
                                if ((x == i || x == ii || y == j || y == jj) && elev[x][y] < ol) ol = elev[x][y];
                                else if ((x != i && x != ii && y != j && y != jj) && elev[x][y] > ih) ih = elev[x][y];
                            }
                        }
                        if (ol > ih) {
                            cap = 0;
                            for (int x = i + 1; x < ii; x++) {
                                for (int y = j + 1; y < jj; y++) {
                                    cap += ol - elev[x][y];
                                }
                            }
                            if (cap > r) r = cap;
                        }
                    }
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}