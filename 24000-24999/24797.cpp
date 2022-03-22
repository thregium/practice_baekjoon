#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)명의 사람과 M(M <= 100000)개의 인간 관계가 주어진다. 각 사람은 소문을
T_i(T_i <= 1000)명에게서 듣게 되면 다음 날부터 소문을 퍼뜨리기 시작한다.
이때, T_i가 0인 사람이 유일하고 그 사람부터 소문을 퍼뜨리기 시작한다면 D(D <= 10000)일 후에는
처음 소문을 퍼뜨린 사람을 제외하면 몇 명의 사람이 소문을 듣게 되는 지 구한다.

해결 방법 : BFS를 통해 T_i가 0인 사람부터 탐색을 시작한다. 각 사람의 T_i값을 해시맵으로 관리하고,
다른 정점에서 진입할 때 마다 1씩 줄여나가다 0이 되면 큐에 집어넣는 방식으로 하면 된다.
거리도 마찬가지로 해시맵으로 관리하며 거리가 D가 될 때 탐색을 종료하고 지금까지 탐색한 사람 수를 확인한다.
탐색한 사람은 해시셋으로 관리한다. 이 해시셋의 크기 - 1(처음 퍼뜨린 사람)이 답이 된다.

주요 알고리즘 : 그래프 이론, BFS, 해시맵, 해시셋

출처 : VTH 2017 E번
*/

char buff[32], buff2[32];
unordered_map<string, unordered_set<string>> ed;
unordered_map<string, int> skep, dist;
unordered_set<string> vis;
queue<string> q;

void bfs(string s, int d) {
    q.push(s);
    dist.insert({ s, 0 });
    vis.insert(s);
    while (q.size()) {
        s = q.front();
        q.pop();
        if (dist[s] == d) return;
        for (auto& i : ed[s]) {
            if (vis.find(i) == vis.end()) vis.insert(i);
            skep[i]--;
            if (skep[i] == 0) {
                dist.insert({ i, dist[s] + 1 });
                q.push(i);
            }
        }
    }
}

int main(void) {
    int n, m, d, t;
    string s, s2;
    //freopen("E:\\PS\\High School\\VTH\\2017\\grapevine\\data\\secret\\secret-06.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &t);
        s.assign(buff);
        skep.insert({ buff, t });
    }
    for (int i = 0; i < m; i++) {
        scanf("%s %s", buff, buff2);
        s.assign(buff);
        s2.assign(buff2);
        if (ed.find(s) != ed.end()) ed[s].insert(s2);
        else ed.insert({ s, {s2} });
        if (ed.find(s2) != ed.end()) ed[s2].insert(s);
        else ed.insert({ s2, {s} });
    }
    scanf("%s", buff);
    s.assign(buff);
    bfs(s, d);
    printf("%d", (int)vis.size() - 1);
    return 0;
}