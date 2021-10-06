#include <stdio.h>
#include <vector>
#include <queue>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
using namespace std;

/*
문제 : N(N < 50000)개의 정점과 M(M <= 100000)개의 양방향 간선을 가진 그래프가 있다. 이 그래프를 두 색으로 칠하되
간선으로 연결된 정점끼리는 서로 다른 색으로 칠하려고 한다. 칠하는 것이 가능한지 확인하고
가능하다면 한 가지 색을 최대 몇 개의 정점에 칠할 수 있는지 구한다.

해결 방법 : 만약 이 그래프가 이분 그래프인 경우 모든 정점을 칠하는 것이 가능하다. 이분 그래프 여부는
BFS를 통해 해결 가능하다. 각 이분 그래프마다 가장 많이 칠하는 방법은 이분 그래프의 나누어지는 두 집합 가운데
더 큰 것을 선택하는 것을 반복하면 된다. 단, 연결 그래프가 아닐 수 있음과
이분 그래프가 아닌 그래프가 하나라도 나오면 칠할 수 없음에 유의한다.

주요 알고리즘 : 그래프 이론, BFS, 이분 그래프

출처 : USACO 2014O B3번
*/

int vis[51200];
vector<int> ed[51200];
queue<pair<int, int>> q;

int bfs(int x) {
    int s = 1, c = 1, r = 1;
    q.push(pair<int, int>(x, s));
    vis[x] = s;
    while (q.size()) {
        x = q.front().first;
        s = q.front().second;
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) {
                if (vis[i] == s) return -1;
            }
            else {
                vis[i] = (!(s - 1)) + 1;
                q.push(pair<int, int>(i, (!(s - 1)) + 1));
                if (s == 2) r++;
                c++;
            }
        }
    }
    return r > c - r ? r : c - r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("decorate.in", "r");
        fo = fopen("decorate.out", "w");
    }
    int n, m, a, b, r = 0, earn;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        earn = bfs(i);
        if (earn < 0) {
            r = -1;
            break;
        }
        else r += earn;
    }
    printf("%d", r);
    return 0;
}