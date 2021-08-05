#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 2000)명의 사람들과 M(M <= 10^6)개의 적대 관계가 주어질 때, 모든 관계에서 적의 적이 친구인지 구한다.

해결 방법 : 적대관계를 그래프로 그렸을 때 이분 그래프 형태라면 해당 관계가 성립한다. BFS를 통해 이분 그래프 여부를
판별하면 된다.

주요 알고리즘 : 그래프 이론, 이분 그래프, BFS
*/

int fd[20480];
vector<int> edge[20480];
queue<int> q;

int main(void) {
    int v, e, a, b, r, t, f, qz, vc;
    r = 1;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vc = v;
    while (vc) {
        for (int i = 1; i <= v; i++) {
            if (!fd[i]) {
                q.push(i);
                break;
            }
        }
        f = 1;
        while (q.size()) {
            qz = q.size();
            while (qz) {
                t = q.front();
                q.pop();
                qz--;
                if (fd[t] == 0) {
                    fd[t] = f;
                    vc--;
                }
                else {
                    if (fd[t] % 2 != f % 2) {
                        r = 0;
                        break;
                    }
                    else continue;
                }
                for (int i = 0; i < edge[t].size(); i++) {
                    q.push(edge[t][i]);
                }
            }
            f++;
            if (!r) break;
        }
    }
    printf("%d\n", r);
    for (int i = 1; i <= v; i++) {
        edge[i].clear();
        fd[i] = 0;
    }
    return 0;
}