#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : 서로 다른 알파벳 대문자로 표시된 N(N <= 26)개의 행성이 있다. 행성 사이에는 무역로가 있고, 무역로로 연결된
행성 사이에는 5%의 수수료를 내면 무역을 할 수 있다. 포탈이 있는 행성이라면 지구와 수수료 없이 무역할 수 있다.
각 행성의 무역로와 수수료가 없다면 무역시 얻을 수 있는 이익이 주어질 때, 어느 행성과 무역하는 것이 가장 좋은지 구한다.

해결 방법 : 각 행성과 무역시 얻을 수 있는 이익은 원래 이익 * 0.95^(거쳐야 하는 행성 수)이다. 따라서, BFS를 통해
거쳐야 하는 행성 수를 구한 후 각 행성의 이익을 구한 다음 가장 이익이 큰 행성을 고르면 된다.

주요 알고리즘 : 그래프 이론, BFS, 수학

출처 : MidC 1995 4번
*/

int vis[32], dist[32];
double value[32], mul[32], trade[32];
char buff[32];
vector<int> ed[26];
queue<int> q;

void bfs(void) {
    int x;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            q.push(i);
            dist[i] = dist[x] + 1;
        }
    }
}

int main(void) {
    int n, b;
    char c;
    double d;
    mul[0] = 1;
    for (int i = 1; i < 32; i++) {
        mul[i] = mul[i - 1] * 0.95;
    }
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf(" %c %lf %s", &c, &d, buff);
            value[c - 'A'] = d;
            for (int j = 0; buff[j]; j++) {
                if (buff[j] == '*') {
                    q.push(c - 'A');
                    vis[c - 'A'] = 1;
                }
                else if (isupper(buff[j])) ed[c - 'A'].push_back(buff[j] - 'A');
            }
        }
        
        bfs();

        b = 0;
        for (int i = 0; i < 26; i++) {
            if (!vis[i]) trade[i] = 0;
            else trade[i] = value[i] * mul[dist[i]];
            if (trade[i] > trade[b]) b = i;
            ed[i].clear();
            vis[i] = 0;
            dist[i] = 0;
        }
        printf("Import from %c\n", b + 'A');
    }
    return 0;
}