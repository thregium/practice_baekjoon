#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 잔디가 있다. 각 잔디들의 위치(0 <, <= 10^6)가 주어질 때, 시작점 L(0 < L <= 10^6)에서 시작하여
모든 잔디들을 먹었을 때의 잔디가 상한 정도 합의 최솟값을 구한다. 잔디가 상한 정도는 그 잔디를 먹기까지 이동한 거리와 같다.

해결 방법 : 먼저 모든 잔디에 대해 해당 지점까지 이동했을 때의 전체 잔디가 상한 정도(L과의 거리 * N)를 저장한다.
그 뒤로는 범위를 넓혀가며 해당 범위의 양쪽 끝 잔디에 도착했을 때의 먹지 않은 잔디가 상한 정도(이전 위치와 거리 * (N - 범위))를
구해서 이전 범위의 양쪽 끝 가운데 더 작은 값을 취한다. 그 값에 현재까지 먹은 잔디가 상한 정도의 합을 더하면
해당 경로에서 필수적으로 들어가는 잔디의 상한 정도 합이 된다.

이를 1부터 N까지로 반복한 다음, 1부터 N까지의 상한 정도 합 가운데 더 작은 것(1에 도착, N에 도착)을 찾으면 된다.

주요 알고리즘 : DP

출처 : USACO 2005N G2번
*/

int clump[1024], mem[1024][1024][2]; //clump: 잔디의 위치, mem: 해당 범위에서 왼쪽/오른쪽 끝에 있을 때
//그때까지 필수적으로 들어가는 잔디의 상한 정도(i: 범위의 왼쪽 끝, j: 오른쪽 끝, k: 0인 경우 왼쪽에 있음, 1인 경우 오른쪽)

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &clump[i]);
    }
    qsort(clump + 1, n, sizeof(int), cmp1);
    for (int i = 1; i <= n; i++) {
        mem[i][i][0] = abs(clump[i] - l) * n; //기저 사례: i번 잔디만 먹은 경우\
                                              (가장 가까운 곳이 아니더라도 최적값보다 멀어지므로 상관 없다)
        mem[i][i][1] = mem[i][i][0];
    }
    for (int i = 1; i < n; i++) {
        //구간의 범위를 넓혀 나간다.
        for (int j = 1; j <= n - i; j++) {
            mem[j][i + j][0] = small(mem[j + 1][i + j][0] + (n - i) * (clump[j + 1] - clump[j]),
                mem[j + 1][i + j][1] + (n - i) * (clump[i + j] - clump[j])); //왼쪽으로 넓힌 경우
            mem[j][i + j][1] = small(mem[j][i + j - 1][0] + (n - i) * (clump[i + j] - clump[j]),
                mem[j][i + j - 1][1] + (n - i) * (clump[i + j] - clump[i + j - 1])); //오른쪽으로 넓힌 경우
        }
    }
    printf("%d", small(mem[1][n][0], mem[1][n][1])); //결과 출력
    return 0;
}