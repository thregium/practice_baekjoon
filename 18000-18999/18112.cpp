#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : 길이 10 이하의 두 이진수가 주어질 때, 주어진 연산으로 첫 번째 이진수를
두 번째 이진수로 바꾸기 위해 필요한 연산의 최소 횟수를 구한다.
0 이상의 이진수에서 1을 감소시키는 연산, 이진수에서 1을 증가시키는 연산,
MSB가 아닌 비트를 반전시키는 연산이 가능하다.

해결 방법 : 각 연산들을 간선, 각 이진수를 정점으로 생각하여 BFS를 돌리면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 서강대 2019M D번
*/

char buff[16], vis[1024];
int dist[1024];
queue<int> q;

int bfs(int st, int ed) {
    int x = st, d;
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        d = dist[x];
        if (x == ed) return d;
        if (x < 1023 && !vis[x + 1]) {
            q.push(x + 1);
            dist[x + 1] = d + 1;
            vis[x + 1] = 1;
        }
        if (x > 0 && !vis[x - 1]) {
            q.push(x - 1);
            dist[x - 1] = d + 1;
            vis[x - 1] = 1;
        }
        for (int i = 1; (i << 1) <= x; i <<= 1) {
            if (!vis[x ^ i]) {
                q.push(x ^ i);
                dist[x ^ i] = d + 1;
                vis[x ^ i] = 1;
            }
        }
    }
}

int main(void) {
    int st, ed;
    scanf("%s", buff);
    st = strtoll(buff, NULL, 2);
    scanf("%s", buff);
    ed = strtoll(buff, NULL, 2);
    printf("%d", bfs(st, ed));
    return 0;
}