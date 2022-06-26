#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)명의 사람들이 산에 올라온다. 각 사람은 물을 오염시킬 때 p_i만큼 물을 오염시키고,
c_i(p_i, c_i <= 3000) 이상 물이 오염되면 마시지 않는다. 이때, 초기 오염도가 0인 경우
물을 마실 수 있는 사람의 최대 수를 구한다.

해결 방법 : ci + pi 순서대로 각 사람이 오는 순서를 정렬한 다음(마시고 난 후 물의 오염도의 오름차순),
그 순서를 바탕으로 다이나믹 프로그래밍을 통해 N명의 사람이 왔을 때의 각 오염도에 따른
최대 인원수를 구하고 그 가운데 최댓값을 출력하면 된다. p_i + c_i의 최댓값 - 1까지
답이 나올 수 있다는 점에 유의한다.

주요 알고리즘 : 그리디 알고리즘, DP, 냅색

출처 : 서강대 2022H H번
*/

int pc[1024][2], mem[1024][6144];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1) + *((int*)a);
    int bi = *((int*)b + 1) + *((int*)b);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, res = -INF, rn = -1;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 6000; j++) mem[i][j] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pc[i][0], &pc[i][1]);
    }
    qsort(pc + 1, n, sizeof(int) * 2, cmp1);
    mem[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 6000; j++) {
            if (mem[i][j] < 0) continue;
            if (mem[i][j] > mem[i + 1][j]) mem[i + 1][j] = mem[i][j];
            if (j < pc[i + 1][1] && j + pc[i + 1][0] <= 6000 &&
                mem[i][j] + 1 > mem[i + 1][j + pc[i + 1][0]]) {
                mem[i + 1][j + pc[i + 1][0]] = mem[i][j] + 1;
            }
        }
    }
    for (int i = 0; i <= 6000; i++) {
        if (mem[n][i] > res) {
            res = mem[n][i];
            rn = i;
        }
    }
    if (res < 0) return 1;
    printf("%d %d", res, rn);
    return 0;
}