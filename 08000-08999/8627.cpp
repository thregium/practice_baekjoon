#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 1000)개의 점이 좌표평면상에 주어진다. P번째 점에서 출발하여 최대 거리 S만큼 단위로
좌표평면상의 다른 공간으로 이동 가능하다. 점으로 이동하면 다시 이동이 가능하고,
그 외 지점에서는 다시 이동이 불가능하다면 처음 지점에서 얼마나 멀리 이동 가능한 지 구한다.
점의 좌표는 절댓값 10^9 이하의 정수이다.

해결 방법 : 플러드필을 통해 이동 가능한 점들을 구하고 그 가운데 처음 지점에서 가장 먼 점까지의
거리를 찾은 다음 거기서 S를 더하면 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 기하학

출처 : JPOI 2009 3-3번
*/

char vis[1024];
long long pos[1024][2];
queue<int> q;

long long getdist(int a, int b) {
    return (pos[a][0] - pos[b][0]) * (pos[a][0] - pos[b][0]) +
        (pos[a][1] - pos[b][1]) * (pos[a][1] - pos[b][1]);
}

int main(void) {
    int n, p, s, x;
    double r = 0.0;
    scanf("%d %d %d", &n, &p, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &pos[i][0], &pos[i][1]);
    }
    q.push(p);
    vis[p] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (getdist(i, x) > (long long)s * s) continue;
            vis[i] = 1;
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) continue;
        if (sqrt(getdist(i, p)) > r) r = sqrt(getdist(i, p));
    }
    printf("%.3f", r + s);
    return 0;
}