#include <stdio.h>

/*
문제 : R * C(R <= 10000, C <= 500) 크기의 격자에 장애물들이 있다. 이 격자의 왼쪽부터 오른쪽까지 선들을 이어서
장애물들을 지나거나 다른 선이 있는 격자를 지나지 않고 오른쪽 위, 오른쪽, 오른쪽 아래 방향으로만 이동해 그을 수 있는 최대 개수를 구한다.

해결 방법 : 모든 행에 대해 가능한 한 위쪽 방향부터 순서대로 갈 수 있는지 탐색해본다. 먼저, 지나온 칸들을 갈 수 없게 처리한 다음
갈 수 있는 칸이면 그 방향으로 한칸 전진한다. 만약 모든 방향으로 갈 수 없다면 다시 이전 칸으로 돌아가되, 지나온 칸들을 다시 바꾸지는 않는다.
만약 오른쪽 끝에 도착했다면 즉시 탐색을 종료한다. 이를 반복해 모든 행에 대해 선을 긋는 것을 시도해 볼 수 있고, 성공한 행의 수가 최대 개수가 된다.

주요 알고리즘 : 그리디 알고리즘, DFS

출처 : CHCI 2009 N1J 3번
*/

char field[10240][512];
int r, c;

int dfs(int x, int y) {
    int res = 0;
    field[x][y] = 'x';
    if (y == c - 1) return 1;
    if (x > 0 && field[x - 1][y + 1] != 'x') res |= dfs(x - 1, y + 1);
    if (res) return 1;
    if (field[x][y + 1] != 'x') res |= dfs(x, y + 1);
    if (res) return 1;
    if (x < r - 1 && field[x + 1][y + 1] != 'x') res |= dfs(x + 1, y + 1);
    //if (res == 0) field[x][y] = '.';
    return res;
}

int main(void) {
    int x, res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", field[i]);
    }
    for (int i = 0; i < r; i++) {
        x = i;
        res += dfs(i, 0);
    }
    printf("%d", res);
    return 0;
}