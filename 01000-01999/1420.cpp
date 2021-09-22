#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 103000
using namespace std;

/*
문제 : N * M(N, M <= 100) 크기의 격자가 있다. 이 격자에서 #으로 표시된 지역은 지나갈 수 없다고 할 때,
K에서 H로 갈 수 없도록 하기 위해 #으로 바꿔야 할 .의 최소 개수를 구한다. K나 H는 #으로 바꿀 수 없고,
어떻게 해도 갈 수 있다면 -1을 출력한다. 이동은 상하좌우로만 할 수 있다.

해결 방법 : 이는 최소 컷을 찾는 문제로 바꿀 수 있고, 다시 최대 유량을 찾는 문제로 바꿀 수 있다.
단, 일반적인 최소 컷과는 달리 정점을 나누어야 한다. 이는 각 정점을 2개로 나누고, 용량 1의 간선으로 사이를 연결하는 것을 통해 해결 가능하다.
여기서 이미 #인 정점은 간선을 추가하지 않는다.(이미 용량이 포화되었기 때문). 또한, K와 H는 용량 무한대인 간선으로 연결한다.
또한, 인접한 정점 사이에는 두 정점의 도착 정점과 출발 정점의 사이를 용량 무한대인 간선으로 이어준다.

이제 K의 출발 정점에서 H의 도착 정점까지 유량을 흘려보내면, 이때의 최대 유량이 답이 된다.

주요 알고리즘 : 그래프 이론, 최대 유량, 최소 컷
*/

char s[128][128];
pair<int, int> path[20480];
vector<tuple<int, int, int, int>> ed[20480]; //도착지, 유량, 용량, 도착지의 i값
queue<int> q;

int main(void) {
    int n, m, r = 0, k = -1, h = -1, x, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            //간선 추가
            if (s[i][j] == '.') {
                //.인 칸은 용량 1인 간선 생성
                ed[i * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, 1, ed[i * m * 2 + j * 2 + 1].size()));
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2, 0, 0, ed[i * m * 2 + j * 2].size() - 1));
            }
            else if (s[i][j] == 'K' || s[i][j] == 'H') {
                //K 또는 H는 용량 무한대인 간선 생성
                ed[i * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, INF, ed[i * m * 2 + j * 2 + 1].size()));
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2, 0, 0, ed[i * m * 2 + j * 2].size() - 1));
                if (s[i][j] == 'K') k = i * m * 2 + j * 2;
                else h = i * m * 2 + j * 2 + 1;
            }
            if (j > 0) {
                //좌우 간선 생성
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2 - 2, 0, INF, ed[i * m * 2 + j * 2 - 2].size()));
                ed[i * m * 2 + j * 2 - 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, 0, ed[i * m * 2 + j * 2 + 1].size() - 1));
                ed[i * m * 2 + j * 2 - 1].push_back(make_tuple(i * m * 2 + j * 2, 0, INF, ed[i * m * 2 + j * 2].size()));
                ed[i * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 - 1, 0, 0, ed[i * m * 2 + j * 2 - 1].size() - 1));
            }
            if (i > 0) {
                //상하 간선 생성
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple((i - 1) * m * 2 + j * 2, 0, INF, ed[(i - 1) * m * 2 + j * 2].size()));
                ed[(i - 1) * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, 0, ed[i * m * 2 + j * 2 + 1].size() - 1));
                ed[(i - 1) * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2, 0, INF, ed[i * m * 2 + j * 2].size()));
                ed[i * m * 2 + j * 2].push_back(make_tuple((i - 1) * m * 2 + j * 2 + 1, 0, 0, ed[(i - 1) * m * 2 + j * 2 + 1].size() - 1));
            }
        }
    }
    if (k < 0 || h < 0) return 1;

    while (1) {
        while (q.size()) q.pop();
        q.push(k);
        for (int i = 0; i < n * m * 2; i++) path[i].first = -1;
        //에드몬드-카프 알고리즘을 통한 유량 찾기
        while (q.size() && path[h].first < 0) {
            x = q.front();
            q.pop();
            for (int i = 0; i < ed[x].size(); i++) {
                if (get<2>(ed[x][i]) <= get<1>(ed[x][i]) || path[get<0>(ed[x][i])].first >= 0) continue;
                q.push(get<0>(ed[x][i]));
                path[get<0>(ed[x][i])].first = x;
                path[get<0>(ed[x][i])].second = i;
                if (get<0>(ed[x][i]) == h) break;
            }
        }
        if (path[h].first < 0) break;
        b = INF;
        for (int i = h; i != k; i = path[i].first) {
            if (get<2>(ed[path[i].first][path[i].second]) - get<1>(ed[path[i].first][path[i].second]) < b) {
                b = get<2>(ed[path[i].first][path[i].second]) - get<1>(ed[path[i].first][path[i].second]);
            }
        }
        for (int i = h; i != k; i = path[i].first) {
            get<1>(ed[path[i].first][path[i].second]) += b;
            get<1>(ed[i][get<3>(ed[path[i].first][path[i].second])]) -= b;
        }
        r += b;
    }
    printf("%d", r > 401 ? -1 : r);
    return 0;
}