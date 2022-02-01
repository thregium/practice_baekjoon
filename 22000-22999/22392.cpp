#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 1000)개의 간선으로 이루어진 무향 연결 그래프에서
다음 조건을 만족하며 정점을 세 그룹으로 나눌 때, A(또는 B) 그룹에 속할 수 있는 정점의 개수 목록을 구한다.
1. 같은 그룹의 정점끼리는 간선으로 이어질 수 없다.
2. A와 B 그룹의 정점끼리는 간선으로 이어질 수 없다.
3. A와 B 그룹에 속하는 정점의 개수는 같아야 한다.

해결 방법 : A와 B 그룹을 하나로 묶으면 이분 그래프의 형태가 됨을 알 수 있다.
따라서, 우선 이렇게 나누기 위해서는 이 그래프가 이분 그래프가 되어야 한다. 이분 그래프임을 확인하였다면
A 그룹의 정점 개수가 될 수 있는 경우는 양쪽 그룹 가운데 정점 개수가 짝수인 것의 절반일 때 뿐이다.
양쪽 그룹에 대해 정점 개수가 짝수인지 살피고 짝수인 것의 절반을 모두 출력하면 된다.
양쪽 정점의 개수가 짝수로 같은 경우와 출력 순서에 유의한다.

주요 알고리즘 : 그래프 이론, 이분 그래프

출처 : JAG 2018D E번
*/

int color[1024];
vector<int> ed[1024];
queue<int> q;

int bfs(int n, int x) {
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) color[i] = 0;
    int c = 1;
    color[x] = c;
    q.push(x);
    while (q.size()) {
        x = q.front();
        c = color[x];
        q.pop();
        for (int i : ed[x]) {
            if (color[i] == c) return -1;
            else if (color[i] == 0) {
                color[i] = (!(c - 1)) + 1;
                q.push(i);
            }
        }
    }
    x = 0;
    for (int i = 1; i <= n; i++) {
        x += (color[i] == 1);
    }
    return x;
}

int main(void) {
    int n, m, u, v, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        r = bfs(n, 1);
        if (r < 0) {
            printf("0\n");
        }
        else {
            if ((r & 1) && ((n - r) & 1)) printf("0\n");
            else if (r & 1) printf("1\n%d\n", (n - r) >> 1);
            else if ((n - r) & 1) printf("1\n%d\n", r >> 1);
            else {
                if (r < n - r) printf("2\n%d\n%d\n", r >> 1, (n - r) >> 1);
                else if (r == n - r) printf("1\n%d\n", r >> 1);
                else printf("2\n%d\n%d\n", (n - r) >> 1, r >> 1);
            }
        }
        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}