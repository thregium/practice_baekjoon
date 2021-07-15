#include <stdio.h>

/*
문제 : N * N 크기의 격자가 있다. 이 격자에서 어떠한 칸을 누르면 해당 칸과 상하좌우로 인접한 칸들의 색이 반전된다.
이 격자에서 처음 색칠된 칸을 모두 누르면 모든 칸이 색칠되지 않은 상태가 된다고 할 때,
맨 윗 줄의 색칠된 형태가 주어져 있을 때, 모든 줄의 형태를 출력한다. 이때 모든 경우에 대해 답은 하나임이 보장된다.

해결 방법 : 맨 윗 줄부터 차례로 색칠된 칸을 누르고 다음 줄에서 상태를 살펴본다. 만약 윗 줄이 필요한 상태와 다른 상태라면
해당 칸을 눌러서 필요한 상태와 같게 만들어야 한다. 누른 칸은 실제로 누른 다음 해당 칸을 칠한 채로 둔다.
이를 모든 줄에 대해 반복하면 모든 칸의 색칠 상태를 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 구현

출처 : 서울대 2017 D2C번
*/

char s[1024][1024], bit[1024][1024];
int dxy[5][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0} };
int n;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    return 1;
}

int main(void) {
    scanf("%d", &n);
    scanf("%s", s[0]);
    for (int i = 0; i < n; i++) {
        if (s[0][i] == '#') {
            for (int d = 0; d < 5; d++) {
                if (!isvalid(0 + dxy[d][0], i + dxy[d][1])) continue;
                bit[dxy[d][0]][i + dxy[d][1]] = !bit[dxy[d][0]][i + dxy[d][1]];
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((s[i - 1][j] == '#' && !bit[i - 1][j]) || (s[i - 1][j] == '.' && bit[i - 1][j])) {
                s[i][j] = '#';
                for (int d = 0; d < 5; d++) {
                    if (!isvalid(i + dxy[d][0], j + dxy[d][1])) continue;
                    bit[i + dxy[d][0]][j + dxy[d][1]] = !bit[i + dxy[d][0]][j + dxy[d][1]];
                }
            }
            else s[i][j] = '.';
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}