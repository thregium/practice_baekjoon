#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 행렬이 주어질 때, 모든 칸이 1인 가장 큰 부분 정사각형의 한 변의 길이를 구한다.

해결 방법 : 행렬의 각 칸에 대해 해당 칸으로 끝나는 가장 큰 정사각형의 한 변의 길이를 저장하는 배열을 두고
다이나믹 프로그래밍을 한다. 만약 해당 칸이 비었다면 그 칸의 값은 0일 것이고, 1이라면 그 칸의 값은
근처 칸들의 값을 통해 알아낼 수 있다. 해당 칸의 위, 왼쪽, 왼쪽 위 값 가운데 가장 작은 것에서 1을 더하면 된다.
이를 반복하며 나온 값들 가운데 가장 큰 것을 찾으면 답이 된다.

주요 알고리즘 : DP

출처 : SEUSA 2010 E번
*/

int mem[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, x, r;
    //freopen("E:\\PS\\ICPC\\North America\\Southeast USA\\2010\\maximumsquare.judge", "r", stdin);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &x);
                if (x) mem[i][j] = small(mem[i - 1][j - 1], small(mem[i - 1][j], mem[i][j - 1])) + 1;
                else mem[i][j] = 0;
                if (mem[i][j] > r) r = mem[i][j];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}