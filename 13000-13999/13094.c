#include <stdio.h>
#include <assert.h>

/*
문제 : N(N <= 36)개의 스위치와 M(M <= 1024)개의 전구가 있다. 처음에 모든 스위치는 내려간 상태이다.
각 전구는 1개의 스위치에만 전원이 연결되어 있으며, 그 스위치가 올라간 상태에서만 켜진다.
Q(Q <= 1000)번 스위치 일부(또는 전부)의 상태를 반전시킨 후 각 전구의 전원 상태가 매번 주어진다.
이때, 각 전구마다 연결된 스위치를 유일하게 찾아낼 수 있는 지 구하고 그러하다면
연결된 스위치를 출력한다.

해결 방법 : 각 전구를 키고 끄는 스위치가 될 수 있는 지 여부를 배열에 저장한다.
그리고 각 전원 상태가 주어질 때 마다 각 스위치에 대해 상태가 반대인 스위치들을 후보에서 배제시켜 나간다.
이를 매번 반복한 다음, Q번이 끝나면 각 전구마다 스위치가 유일하게 결정되는 지 확인한다.
유일하다면 다시 한번 그 유일한 스위치의 번호를 찾아 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JAG 2014P B번
*/

char swc[1024][48], bulb[1024][1024];
int avail[1024][48];

int main(void) {
    int n, m, q, c;
    while (1) {
        scanf("%d %d %d", &n, &m, &q);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) avail[i][j] = 1;
        }
        for (int i = 0; i < q; i++) {
            scanf("%s %s", swc[i], bulb[i]);
            if (i > 0) {
                for (int j = 0; j < n; j++) {
                    if (swc[i][j] == '1') swc[i][j] = (!(swc[i - 1][j] - '0')) + '0';
                    else swc[i][j] = swc[i - 1][j];
                }
            }
        }
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if (bulb[i][j] != swc[i][k]) avail[j][k] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            c = 0;
            for (int j = 0; j < n; j++) c += avail[i][j];
            assert(c);
            if (c > 1) {
                printf("?");
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (avail[i][j]) printf("%c", j < 10 ? j + '0' : j + 'A' - 10);
            }
        }
        printf("\n");
    }
    return 0;
}