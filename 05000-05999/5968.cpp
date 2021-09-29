#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

/*
문제 : 한 변이 K(K <= 50)인 육각형 형태로 지점들이 있다. 각 지점들은 왼쪽 아래부터 위 -> 오른쪽으로 올라가며 번호가 붙는다.
이때, H번인 지점에서 거리가 L인 지점을 오름차순으로 출력한다.

해결 방법 : 모든 지점들에 대해 인접한 지점들을 계산을 통해 연결해준다. (자세한 내용은 코드 참조)
그 다음, H번 지점에서 BFS를 돌린 뒤, 거리가 L인 지점들을 모두 찾으면 된다.

주요 알고리즘 : 그래프 이론, BFS, 구현

출처 : USACO 2011F B3번
*/

int vis[8192], dist[8192];
vector<int> adj[8192], res;
queue<int> q;

void bfs(int x) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : adj[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    int k, h, l, x = 1;
    scanf("%d %d %d", &k, &h, &l);
    //왼쪽 줄들의 연결 추가
    for (int i = k; i < k * 2 - 1; i++) {
        //x는 이번 줄의 첫 수
        for (int j = x; j < x + i; j++) {
            if (j > x) {
                adj[j].push_back(j - 1); // |방향
                adj[j - 1].push_back(j);
            }
            adj[j].push_back(j + i); // /방향
            adj[j + i].push_back(j);
            adj[j].push_back(j + i + 1); // \방향
            adj[j + i + 1].push_back(j);
        }
        x += i;
    }

    //오른쪽 줄들의 연결 추가
    x = k * (k - 1) * 3 + 1;
    for (int i = k; i < k * 2 - 1; i++) {
        //x는 이번 줄의 마지막 수
        for (int j = x; j > x - i; j--) {
            if (j < x) {
                adj[j].push_back(j + 1); // |방향
                adj[j + 1].push_back(j);
            }
            adj[j].push_back(j - i); // /방향
            adj[j - i].push_back(j);
            adj[j].push_back(j - i - 1); // \방향
            adj[j - i - 1].push_back(j);
        }
        x -= i;
    }

    //가운데 줄 연결 추가
    for (int i = 2; i < k * 2; i++) {
        adj[x - 1].push_back(x); // |방향
        adj[x].push_back(x - 1);
        x--;
    }

    //BFS후 결과 확인
    bfs(h);
    for (int i = 1; i <= (k * (k - 1) * 3 + 1); i++) {
        if (dist[i] == l) res.push_back(i);
    }
    printf("%d\n", res.size());
    for (int i : res) {
        printf("%d\n", i);
    }
    return 0;
}