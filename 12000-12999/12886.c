#include <stdio.h>

/*
문제 : 3개의 돌 그룸에 있는 돌 수 A, B, C(0 <= A, B, C <= 500)가 주어질 때, 서로 개수가 같지 않은 그룹의 돌을 골라
많은 쪽의 돌을 적은 쪽의 돌 개수만큼 적은 쪽으로 옮긴다. 이때, 이 연산을 반복하여 모든 돌 수를 같도록 하는
방법이 있는지 구한다.

해결 방법 : 모든 경우 전체 돌 수는 같음을 알 수 있다. 또한, 어느 한 그룹의 돌이 아무리 많아지더라도
전체 돌 수를 넘어설 수는 없다. 따라서 돌 A의 개수와 돌 B의 개수를 변수로 두고 플러드필을 진행할 수 있다.
플러드필을 진행한 후 모든 돌의 수가 같은 경우가 방문되었는지 확인해서 방문된 경우 그러한 방법이 있는 것이고,
방문되지 않았다면 방법이 없는 것이다.

주요 알고리즘 : 그래프 이론, 플러드필
*/

char vis[1536][1536];

void dfs(int n, int x, int y) {
    vis[x][y] = 1;
    int z = n - x - y;
    if (x < y) {
        if (!vis[x + x][y - x]) dfs(n, x + x, y - x);
    }
    if (y < x) {
        if (!vis[x - y][y + y]) dfs(n, x - y, y + y);
    }
    if (x < z) {
        if (!vis[x + x][y]) dfs(n, x + x, y);
    }
    if (z < x) {
        if (!vis[x - z][y]) dfs(n, x - z, y);
    }
    if (y < z) {
        if (!vis[x][y + y]) dfs(n, x, y + y);
    }
    if (z < y) {
        if (!vis[x][y - z]) dfs(n, x, y - z);
    }
}

int main(void) {
    int n, a, b, c, r = 0;
    scanf("%d %d %d", &a, &b, &c);
    n = a + b + c;
    if (n % 3) {
        printf("0");
        return 0;
    }
    dfs(n, a, b);
    printf("%d", (int)vis[n / 3][n / 3]);
    return 0;
}