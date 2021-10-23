#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 500)개의 정점과 E(E <= 10000)개의 간선으로 이루어진 가중치 없는 양방향 그래프가 주어지고
Q(Q <= 1000)개의 쿼리가 주어질 때, 각 쿼리에 응답한다.
1. 정점 A와 정점 B를 연결한 후 1에서 N으로 흐르는 유량의 값을 구한다. 정점 A와 B는 연결되지 않은 상태이다.
2. 정점 A와 정점 B를 연결한 후 1에서 N으로 흐르는 유량의 값을 구한다. 정점 A와 B는 연결된 상태이다.
모든 간선은 중복되지 않는다.

해결 방법 : 먼저, 처음 주어지는 간선들로 1에서 N으로 흐르는 유량을 구한다. 그 다음, 쿼리를 확인해 나간다.

1번 쿼리가 들어오는 경우에는 유량을 최대 1번 늘릴 수 있으므로 정점 사이를 연결한 후 1에서 유량을 다시 흘려보면 된다.

2번 쿼리가 들어오는 경우에는 해당 간선에 유량이 흐르지 않는다면 그대로 지우면 된다. 간선을 벡터에서 지우더라도
한 정점에 최대 499개의 간선만 이어질 수 있으므로 충분히 시간 내로 돌릴 수 있다.

간선에 유량이 흐르는 상태라면 그래프에서 해당 간선을 포함해 유량이 흐르는 경로를 찾아내서 그 경로의 유량을
모두 지운 다음 간선을 지우면 된다. 물론 이 과정에서 전체 유량은 1 줄어들게 된다.
해당 경로를 찾는 방법은 1에서 해당 유량의 시작점으로 흐르는 경로를 BFS로 찾은 다음,
해당 유량의 끝점에서 N으로 흐르는 경로를 또 BFS로 찾고 여기에 해당 유량까지 추가해준 다음 이들을 연결시키면 된다.
간선을 지운 다음에는 다른 경로로 유량이 흐를 수도 있으므로 다시 1에서 유량을 한번 흘려준다.

이렇게 하면 매 쿼리마다 1 ~ 3회의 BFS만으로 쿼리를 처리할 수 있으므로 모든 쿼리에 시간 내로 응답이 가능해진다.

주요 알고리즘 : 그래프 이론, 최대 유량

출처 : JAG 2011SP4 D번
*/

char inl[256], outl[256];
int cap[512][512], flow[512][512], pre[512], res[1024];
vector<int> v[512];
queue<int> q;
int tf;

void makeflow(int n) {
    //BFS를 통해 1에서 N으로 이동하는 유량을 가능한 만큼 흘린다.
    int x = 1;
    while (1) {
        q.push(1);
        pre[1] = -1;
        for (int i = 2; i <= n; i++) pre[i] = 0;
        while (q.size()) {
            x = q.front();
            q.pop();
            for (int i : v[x]) {
                if (pre[i]) continue;
                if (cap[x][i] > flow[x][i]) {
                    pre[i] = x;
                    q.push(i);
                }
            }
        }

        if (!pre[n]) break;
        for (int i = n; i > 1; i = pre[i]) {
            flow[pre[i]][i] += 1;
            flow[i][pre[i]] += -1; //역방향 간선에 유량을 흘리는 것도 잊지 않는다
        }
        tf++;
    }
}

void findflow(int n, int a, int b) {
    //1에서 A -> B 간선을 지나 N으로 흐르는 경로를 찾아 유량을 지운 다음 전체 유량을 1 줄인다.
    int x = 1;
    q.push(1);
    pre[1] = -1;
    for (int i = 2; i <= n; i++) pre[i] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : v[x]) {
            if (pre[i]) continue;
            if (flow[x][i] > 0) {
                pre[i] = x;
                q.push(i);
            }
        }
    }

    for (int i = a; i > 1; i = pre[i]) {
        flow[pre[i]][i] -= 1; //1에서 A로 흐르는 유량 제거
        flow[i][pre[i]] -= -1;
    }

    for (int i = 1; i <= n; i++) pre[i] = 0;
    pre[b] = a;
    q.push(b);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : v[x]) {
            if (pre[i]) continue;
            if (flow[x][i] > 0) {
                pre[i] = x;
                q.push(i);
            }
        }
    }

    for (int i = n; i != b; i = pre[i]) {
        flow[pre[i]][i] -= 1; //B에서 N으로 흐르는 유량 제거
        flow[i][pre[i]] -= -1;
    }
    flow[a][b] -= 1; //A에서 B로 흐르는 유량 제거
    flow[b][a] -= -1;
    tf -= 1; //전체 유량 1 감소
}

int main(void) {
    int n, e, q, m, a, b;
    for (int fn = 1; fn <= 1; fn++) {
        //sprintf(inl, "E:\\PS\\Contest\\JAG\\2011SP\\summer-camp-2011-day4\\D\\in%d.txt", fn);
        //freopen(inl, "r", stdin);
        
        tf = 0;
        scanf("%d %d %d", &n, &e, &q);
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            cap[a][b] = 1;
            cap[b][a] = 1;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        makeflow(n);
        
        for (int i = 0; i < q; i++) {
            scanf("%d %d %d", &m, &a, &b);
            if (m == 1) {
                //그대로 간선을 추가만 하면 된다.
                cap[a][b] += 1;
                cap[b][a] += 1;
                v[a].push_back(b);
                v[b].push_back(a);
            }
            else if (m == 2) {
                cap[a][b] -= 1;
                cap[b][a] -= 1;
                if (flow[a][b] > 0) findflow(n, a, b); //A -> B로 유량이 흐르는 경우
                else if (flow[b][a] > 0) findflow(n, b, a); //B -> A로 유량이 흐르는 경우

                for (int j = 0; j < v[a].size(); j++) {
                    if (v[a][j] == b) {
                        v[a].erase(v[a].begin() + j); //해당하는 간선을 벡터에서 삭제한다. O(N)의 시간이 들지만 괜찮다.
                        break;
                    }
                }
                for (int j = 0; j < v[b].size(); j++) {
                    if (v[b][j] == a) {
                        v[b].erase(v[b].begin() + j); //해당하는 간선을 벡터에서 삭제한다.
                        break;
                    }
                }
            }
            else return 1;

            makeflow(n); //다시 한번 유량을 흘린다.
            res[i] = tf; //현재 유량의 값으로 결괏값을 저장한다.
        }

        /*
        sprintf(outl, "E:\\PS\\Contest\\JAG\\2011SP\\summer-camp-2011-day4\\D\\out%d.txt", fn);
        freopen(outl, "r", stdin);
        b = 1;
        for (int i = 0; i < q; i++) {
            scanf("%d", &a);
            if (a != res[i]) b = 0;
        }
        
        printf("File %d: ", fn);
        if (b) printf("OK\n");
        else printf("ERROR!!\n");
        */
        for (int i = 0; i < q; i++) {
            printf("%d\n", res[i]); //결괏값을 출력한다.
        }

        for (int i = 0; i <= n; i++) {
            v[i].clear();
            for (int j = 0; j <= n; j++) {
                cap[i][j] = 0;
                flow[i][j] = 0;
            }
        }
    }
    return 0;
}
