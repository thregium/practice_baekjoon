#include <stdio.h>
#include <string.h>

/*
문제 : N * M(N, M <= 100) 크기의 벽에 높이 1인 벽돌들을 쌓았다. 벽돌 하나를 뺐을 때
벽에서 사라지는 부분의 넓이 가운데 가장 넓은 것을 구한다.
벽돌 밑에 벽돌이 하나라도 있는 경우 그 벽돌은 떨어지지 않는다.

해결 방법 : 뺄 수 있는 모든 블록을 빼 보면서 그 블록으로 인해 떨어지는 블록의 크기 합을 매번 확인하고,
그 가운데 가장 큰 값을 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 브루트 포스

출처 : Tehran 2008 C번
*/

char brick[128][128], bcpy[128][128];

void cpybrick(int n, int m) {
    for (int i = 0; i < n; i++) {
        strcpy(bcpy[i], brick[i]);
    }
}

int fallbrick(int n, int m, int x, int yl, int yh) {
    int r = 0, fallen = 1, bln, az, y;
    for (int i = yl; i <= yh; i++) {
        bcpy[x][i] = '0';
        r++;
    }
    while (fallen) {
        fallen = 0;
        for (int i = n - 2; i >= 0; i--) {
            y = 0;
            while (y < m) {
                if (bcpy[i][y] == '0') {
                    y++;
                    continue;
                }
                bln = bcpy[i][y] - '0', az = 1;
                for (int j = y; j < y + bln; j++) {
                    if (bcpy[i + 1][j] != '0') az = 0;
                }
                if (az) {
                    for (int j = y; j < y + bln; j++) {
                        bcpy[i][j] = '0';
                    }
                    r += bln;
                    fallen = 1;
                }
                y += bln;
            }
        }
    }

    return r;
}

int main(void) {
    int n, m, x, cnt, res;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", brick[i]);
        }

        res = 0;
        for (int i = 0; i < n; i++) {
            x = 0;
            while (x < m) {
                if (brick[i][x] == '0') {
                    x++;
                    continue;
                }
                cpybrick(n, m);
                cnt = fallbrick(n, m, i, x, x + brick[i][x] - '0' - 1);
                if (cnt > res) res = cnt;
                x = x + brick[i][x] - '0';
            }
        }
        printf("%d\n", res);
    }
    return 0;
}