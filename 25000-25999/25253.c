#include <stdio.h>

/*
문제 : N(N <= 200)개의 수와 M(M <= 100)개의 상태로 이루어진 선형 자동자가 있다.
다음 상태는 인접한 3개의 수에 대한 함수로 진행된다고 할 때, 함수와 상태가 주어지면
그 상태의 이전 상태로 가능한 것이 있는 지 확인한다.

해결 방법 : 시작점의 왼쪽과 앞에 있는 두 수, 그리고 최근의 두 수를 저장해 나가면서
다이나믹 프로그래밍을 진행한다. 시작할 때에는 세 수가 첫 수를 만드는 경우를 확인해서 그 경우들만
1로 바꾸어 주고, 이후로 진행시에는 첫 두 수와 최근 3개의 수를 하나씩 확인해 나가면서
가능한 경우에 대해 다이나믹 프로그래밍을 진행한다.
최종적으로 마지막 칸에서 최근 2개의 수가 첫 두 수와 같은 경우가 있는 지 확인하면 된다.

주요 알고리즘 : DP

출처 : GCPC 2021 I번
*/

int func[16][16][16], nxt[256];
char mem[216][12][12][12][12];

int main(void) {
    int n, m, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                scanf("%d", &func[i][j][k]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &nxt[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                if (func[i][j][k] == nxt[0]) mem[0][i][j][j][k] = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= m; y++) {
                for (int ii = 1; ii <= m; ii++) {
                    for (int jj = 1; jj <= m; jj++) {
                        for (int kk = 1; kk <= m; kk++) {
                            if (func[ii][jj][kk] == nxt[i]) {
                                mem[i][x][y][jj][kk] |= mem[i - 1][x][y][ii][jj];
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (mem[n - 1][i][j][i][j]) res = 1;
        }
    }
    printf("%s", res ? "yes" : "no");
    return 0;
}