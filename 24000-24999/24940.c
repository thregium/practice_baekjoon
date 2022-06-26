#include <stdio.h>

/*
문제 : N(N <= 80)명의 사람들이 일렬로 있다. 인접한 사람끼리 그룹을 합쳐 나갈 때,
친밀도의 최솟값을 구한다. 각 그룹의 성향의 음양이 다른 경우 성향의 곱의 절댓값만큼 친밀도가 줄어든다.

해결 방법 : 각 구간의 성향은 항상 같으므로 이를 전처리하면 구간DP의 형태가 된다.
친밀도가 줄어든 양의 최댓값을 구한 다음, 거기에 -를 붙이면 된다. 답이 0일 때에 주의한다.

주요 알고리즘 : DP, 구간DP

출처 : 설곽 2022Q D번
*/

int a[96];
long long mem[96][96], alig[96][96];

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long getconflict(int as, int ae, int bs, int be) {
    if (alig[as][ae] >= 0 && alig[bs][be] >= 0) return 0;
    else if (alig[as][ae] <= 0 && alig[bs][be] <= 0) return 0;
    else return -(alig[as][ae] * alig[bs][be]);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) alig[i][j] += a[k];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            for (int k = j + 1; k <= j + i; k++) {
                mem[j][j + i] = big(mem[j][j + i], mem[j][k - 1] + mem[k][j + i] +
                    getconflict(j, k - 1, k, j + i));
            }
        }
    }
    if (mem[1][n] == 0) printf("0");
    else printf("-%lld", mem[1][n]);
    return 0;
}