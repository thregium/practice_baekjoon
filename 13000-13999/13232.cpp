#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : D(D <= 5000)개의 정점을 가진 유향 그래프가 있을 때, 이 그래프에서 모든 정점끼리 이동 가능한 집합(SCC) 가운데
가장 큰 것의 크기를 구한다.

해결 방법 : D^2이 1억 이하이므로 D^2 시간 안에 푸는 것이 가능하다. 모든 정점에서 BFS를 진행한 후
각 정점에서 도달 가능한 정점들을 인접행렬 형태로 저장해 놓는다. 저장이 끝나면 다시 정점을 돌며
지금까지 저장된 SCC 가운데 들어갈 수 있는 것이 있는지 확인하고 있다면 그 곳에 저장, 없다면 새 그룹에 저장한다.
그리고 모든 SCC 그룹을 돌며 가장 큰 값을 찾으면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : AIPO 2015S 3번
*/

vector<int> e[5120], g[5120]; //간선, SCC 그룹
//queue<int> q;
int reach[5120][5120], q[1048576]; //인접행렬, 큐
int gp = 0, qf, qr;

void bfs(int s, int x) {
    reach[s][x] = 1;
    qf = 0;
    qr = 0;
    q[qr++] = x;
    while (qf - qr) {
        x = q[qf++];
        for (int i = 0; i < e[x].size(); i++) {
            if (!reach[s][e[x][i]]) {
                reach[s][e[x][i]] = 1; //인접행렬에 저장
                q[qr++] = e[x][i];
            }
        }
    }
}

int main(void) {
    int d, l, a, b, t1, t2, r = 0;
    //freopen("C:\\1_공부\\PS\\olympiad\\Ireland\\2015f\\test_cases\\s3\\test.17.in", "r", stdin);
    scanf("%d%d", &d, &l);
    for (int i = 0; i < l; i++) {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
    }
    for (int i = 1; i <= d; i++) {
        bfs(i, i); //BFS
    }
    for (int i = 1; i <= d; i++) {
        t1 = 0;
        for (int j = 0; j < gp; j++) {
            t2 = 1;
            for (int k = 0; k < g[j].size(); k++) {
                if (!reach[g[j][k]][i] || !reach[i][g[j][k]]) {
                    //i에서 k로 갈 수 없거나 k에서 i로 갈 수 없다면 j에 대해 탐색 종료
                    t2 = 0;
                    break;
                }
            }
            if (t2) {
                g[j].push_back(i); //들어갈 수 있는 SCC를 찾은 경우
                t1 = 1;
                break;
            }
        }
        if (!t1) g[gp++].push_back(i); //들어갈 수 없는 SCC를 찾지 못한 경우 새 그룹 생성
    }

    for (int i = 0; i < gp; i++) {
        if (g[i].size() > r) r = g[i].size();
    }
    printf("%d", r);
    return 0;
}