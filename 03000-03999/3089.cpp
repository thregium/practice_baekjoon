#include <stdio.h>
#include <vector>
#include <algorithm>
#define ZERO 103000
using namespace std;

/*
문제 : N(N <= 100000)개의 점이 좌표평면상에 있다. (0, 0)에서 상하좌우로 가장 가까운 다음 점으로 이동하는
연산을 M(M <= 100000)회 한 이후 도착하는 위치를 출력한다. 점의 좌표는 절댓값 100000 이하의 정수이며,
다음 점은 반드시 존재한다.

해결 방법 : 좌표 범위가 작으므로 벡터에 각 좌표를 넣고 정렬한 다음 방향에 맞게 이분 탐색하면 된다.

주요 알고리즘 : 정렬, 이분 탐색, 시뮬레이션

출처 : CHCI 2012J2 3번
*/

char op[103000];
vector<int> xpos[204800], ypos[204800];

int main(void) {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        x += ZERO;
        y += ZERO;
        xpos[x].push_back(y);
        ypos[y].push_back(x);
    }
    for (int i = 0; i < 204800; i++) {
        sort(xpos[i].begin(), xpos[i].end());
        sort(ypos[i].begin(), ypos[i].end());
    }
    scanf("%s", op);

    x = ZERO, y = ZERO;
    for (int i = 0; i < m; i++) {
        if (op[i] == 'L') x = ypos[y][lower_bound(ypos[y].begin(), ypos[y].end(), x) - ypos[y].begin() - 1];
        else if(op[i] == 'R') x = ypos[y][upper_bound(ypos[y].begin(), ypos[y].end(), x) - ypos[y].begin()];
        else if (op[i] == 'D') y = xpos[x][lower_bound(xpos[x].begin(), xpos[x].end(), y) - xpos[x].begin() - 1];
        else if (op[i] == 'U') y = xpos[x][upper_bound(xpos[x].begin(), xpos[x].end(), y) - xpos[x].begin()];
    }
    printf("%d %d", x - ZERO, y - ZERO);
    return 0;
}