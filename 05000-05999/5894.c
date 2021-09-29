#include <stdio.h>

/*
문제 : N(N <= 10)개의 지점이 주어질 때, (0, 0)에서 각 지점들을 모두 돌아 (0, 0)으로 오는 경로의 가짓수를 구한다.
단, 각 지점들 사이를 갈 때에는 상하좌우 방향으로만 갈 수 있고, 각 지점들에서는 반드시 다른 방향으로 이동해야 한다.
각 지점의 좌표 범위는 +- 1000 이하며 경로가 같더라도 순서가 다르다면 서로 다른 경로로 처리한다.

해결 방법 : (0, 0)부터 시작해 백트래킹을 한다. X좌표와 Y좌표가 모두 다른 점은 상하좌우를 통해 이동 불가능하므로
이동할 수 없고, 둘 중 하나가 같은 점은 방향을 따져가며 직전으로 이동한 방향과 같은 경우를 제외하고 이동하면 된다.
물론 중간에 방문한 점 역시 이동 불가능하다. 모든 지점들에 도달했다면 (0, 0)으로 돌아가는 것이 가능할 때
결괏값에 1을 추가한다. 모든 경로를 탐색한 이후 결괏값을 출력하면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : USACO 2012M B2번
*/

int point[16][2], chk[16];
int res = 0;

int getdir(int a, int b) {
    if (point[a][0] != point[b][0] && point[a][1] != point[b][1]) return -1;
    else if (point[a][0] == point[b][0]) {
        if (point[a][1] > point[b][1]) return 0;
        else return 2;
    }
    else {
        if (point[a][0] > point[b][0]) return 1;
        else return 3;
    }
}

void track(int n, int r, int x, int d) {
    if (n == r) {
        if (getdir(x, 10) != d && getdir(x, 10) >= 0) res++;
        return;
    }

    chk[x] = 1;
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        if (getdir(x, i) != d && getdir(x, i) >= 0) track(n, r + 1, i, getdir(x, i));
    }
    chk[x] = 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    track(n, 0, 10, -1);
    printf("%d", res);
    return 0;
}