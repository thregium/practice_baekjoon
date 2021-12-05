#include <stdio.h>
#define INF 103001

/*
문제 : N * N(N <= 15) 크기의 행렬이 주어진다. 이 행렬은 상인 i가 상인 j에게 그림을 팔 때의 가격과 같다.
각 상인들은 자신이 산 가격 이상으로 다른 상인에게 팔 수 있고, 한 번 그림을 산 상인은 다시 그림을 사지 않는다면,
그림을 가졌던 사람이 최대인 경우 몇 명 까지 가능한지 구한다. 처음에는 상인 1이 가격 0에 외부에서 그림을 샀다.

해결 방법 : 비트마스킹 DP를 이용한다. 각 가격 순서대로 해당 가격에서 팔 수 있는 상인들에게 모두 팔아보는 것이다.
이때, 같은 가격으로 팔 수 있기 때문에 비트마스킹 순서대로 팔아야 제대로 값이 나오게 된다. 비트마스킹은
샀던 상인들을 저장해 두면 된다.

주요 알고리즘 : DP, 비트마스킹 DP

출처 : SRM 430 D2C번
*/

int mem[12][16][32768];
char arr[16][16];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    mem[0][0][1] = 1;
    for (int i = 0; i <= 9; i++) {
        for (int k = 0; k < (1 << n); k++) {
            for (int j = 0; j < n; j++) {
                if (~k & (1 << j)) continue;
                if (mem[i][j][k] == 0) continue;
                for (int l = 0; l < n; l++) {
                    if (arr[j][l] - '0' < i) continue;
                    if (k & (1 << l)) continue;
                    if (mem[i][j][k] + 1 > mem[arr[j][l] - '0'][l][k | (1 << l)]) {
                        mem[arr[j][l] - '0'][l][k | (1 << l)] = mem[i][j][k] + 1;
                        if (mem[i][j][k] + 1 > r) r = mem[i][j][k] + 1;
                    }
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}