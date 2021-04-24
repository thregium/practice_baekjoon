#include <stdio.h>
#define MOD 1000000007

/*
문제 : N*M 크기의 지도에서 갈 수 있는 부분과 갈 수 없는 부분이 주어질 때,
최단거리로 왼쪽 위에서 오른쪽 아래로 가능 방법의 가짓수를 구한다.

해결 방법 : 가장 왼쪽 윗 칸을 1로 하고 이후로는 자신의 윗칸과 왼쪽 칸을 더한 값이 해당 칸으로 가는 가짓수이다.
단, 갈 수 없는 칸인 경우 0으로 바꿔놓아야 한다.

주요 알고리즘 : 다이나믹 프로그래밍

출처 : AIPO 2017F 4번
*/

char s[256][256];
int mem[256][256];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &(s[i][1]));
    }
    mem[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'X') continue;
            mem[i][j] = (mem[i - 1][j] + mem[i][j - 1]) % MOD;
        }
    }
    printf("%d", mem[n][m]);
    return 0;
}
