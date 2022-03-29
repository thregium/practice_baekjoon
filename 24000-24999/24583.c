#include <stdio.h>
#include <math.h>

/*
문제 : R * C(R, C <= 50) 크기의 격자에 차들이 있거나 없다. 차가 있는 칸의 내부로 들어갈 수 없을 때
(모서리로는 이동 가능), 왼쪽 위 지점에서 오른쪽 아래 지점으로 이동하는 데 걸리는 최단거리를 구한다.
(시간제한 5초)

해결 방법 : 모든 왼쪽 / 위 지점에서 오른쪽 / 아래 지점으로 이동하는 쌍에 대해
이동 가능한지를 확인한다. 수학적으로 선이 지나는 범위에서만 차가 있는 지를 확인하는 방법을 쓴다.
이는 모든 쌍에서 O(R + C) 시간에 가능하고 쌍의 개수는 O(R^2C^2)이므로 시간 내에 모두 확인이 가능하다. 
모든 쌍에 대해 확인했으면 왼쪽 위 지점에서부터 순서대로 다이나믹 프로그래밍을 통해
최단 거리를 구해 나가고 최종적으로 오른쪽 아래 지점까지의 거리를 찾으면 된다.

주요 알고리즘 : DP, 기하학

출처 : MidAtl 2021 G번 // NCNA 2021 I번
*/

char car[64][64], cango[64][64][64][64];
double mem[64][64];

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", car[i]);
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            for (int ii = i; ii <= r; ii++) {
                for (int jj = j; jj <= c; jj++) {
                    if (i == ii || j == jj) {
                        cango[i][j][ii][jj] = 1;
                        continue;
                    }
                    cango[i][j][ii][jj] = 1;
                    for (int k = i; k < ii; k++) {
                        for (int l = j + (jj - j) * (k - i) / (ii - i);
                            l < j + ((jj - j) * (k - i + 1) + (ii - i - 1)) / (ii - i); l++) {
                            if (car[k][l] == '#') cango[i][j][ii][jj] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            if (i + j == 0) continue;
            mem[i][j] = 103000.0;
            for (int ii = 0; ii <= i; ii++) {
                for (int jj = 0; jj <= j; jj++) {
                    if (ii == i && jj == j) continue;
                    if (cango[ii][jj][i][j]) {
                        if (sqrt(pow(i - ii, 2) + pow(j - jj, 2)) + mem[ii][jj] < mem[i][j]) {
                            mem[i][j] = sqrt(pow(i - ii, 2) + pow(j - jj, 2)) + mem[ii][jj];
                        }
                    }
                }
            }
        }
    }
    printf("%.9f", mem[r][c]);
    return 0;
}