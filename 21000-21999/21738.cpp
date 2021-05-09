#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 328000)개의 얼음이 있고, 각각의 연결 상태가 주어진다. 얼음들의 연결 상태는 트리 형태이다.
이때, 얼음들은 지지대 역할을 하는 얼음 S개와 그렇지 않은 나머지 얼음들로 나뉜다. 나머지 얼음들은 적어도 하나의 지지대 얼음과 연결되어야 한다.
이때, 지지대 얼음이 아닌 한 얼음에 펭귄이 있는데, 펭귄이 있는 얼음은 적어도 2개의 지지대 얼음과 연결되어야 한다고 할 때,
최대한으로 제거할 수 있는 얼음의 수를 구한다. 이때, 지지대 얼음들끼리 직접 연결되어있는 경우는 없다고 가정한다.

해결 방법 : 펭귄에게서 가장 가까운 2개의 지지대 얼음으로 가는 경로만 남기고 나머지는 전부 제거하면 된다.
펭귄에서 가장 가까운 지지대 얼음은 BFS를 이용하면 쉽게 구할 수 있다.

주요 알고리즘 : 그래프 이론, 트리, BFS

출처 : 숙명여대 1회 E번
*/

int vis[384000];
int s;
vector<int> link[384000];
queue<pair<int, int>> q;

int bfs(int x) {
    int d, r = 1, post = 0; //d : 현재 얼음의 거리 r : 남겨야 하는 얼음의 수, 현재 펭귄이 있는 얼음 1개에서 시작한다. post : 확인한 지지대 수 
    q.push(pair<int, int>(x, 0));
    vis[x] = 1;
    while (q.size()) {
        x = q.front().first;
        d = q.front().second;
        q.pop();
        if (x <= s) {
            //현재 얼음이 지지대 얼음인 경우
            post++;
            r += d; //지지대 얼음까지의 거리를 구한다.
            if (post == 2) break; //2개의 지지대 얼음을 전부 찾았으면 확인 종료
        }
        for (int i = 0; i < link[x].size(); i++) {
            if (vis[link[x][i]]) continue;
            q.push(pair<int, int>(link[x][i], d + 1));
            vis[link[x][i]] = 1;
        }
    }
    return r;
}

int main(void) {
    int n, p, a, b;
    scanf("%d %d %d", &n, &s, &p);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    printf("%d", n - bfs(p));
    return 0;
}