#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 200)개의 대상(30자)에 대한 사실과, M(M <= 200)개의 주장이 주어질 때,
각 주장이 사실인지 거짓인지 알 수 없는 지 구한다. 모든 사실과 주장은 A가 B보다 나쁘다로 주어진다.
모순되는 사실은 주어지지 않는다.

해결 방법 : 각 대상을 정점으로, 각 사실들을 더 나쁜 방향으로 향하는 간선으로 만들고,
각 주장에 대해 첫 대상에서 플러드필로 두 번째 대상에 도달하는 지 구한다. 그 경우 사실이다.
여기서 간선을 전부 뒤집은 다음 두 번째 대상에 도달하는 경우 거짓이다.
둘다 아니라면 진위 여부를 알 수 없다.

주요 알고리즘 : 그래프 이론, 플러드필, 해시맵, 해시셋

출처 : GCPC 2017 D번
*/

char buff[64], buff2[64];
unordered_map<string, unordered_set<string>> ed, edr;
unordered_set<string> vis;

int dfs1(string s, string t) {
    int r = 0;
    vis.insert(s);
    if (s == t) return 1;
    for (auto i : ed[s]) {
        if (vis.find(i) != vis.end()) continue;
        r |= dfs1(i, t);
    }
    return r;
}
int dfs2(string s, string t) {
    int r = 0;
    vis.insert(s);
    if (s == t) return 2;
    for (auto i : edr[s]) {
        if (vis.find(i) != vis.end()) continue;
        r |= dfs2(i, t);
    }
    return r;
}

int main(void) {
    int n, m, r;
    string s, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s are worse than %s", buff, buff2);
        s.assign(buff);
        t.assign(buff2);
        if (ed.find(s) == ed.end()) {
            ed.insert(make_pair(s, unordered_set<string>()));
        }
        ed[s].insert(t);
        if (edr.find(t) == edr.end()) {
            edr.insert(make_pair(t, unordered_set<string>()));
        }
        edr[t].insert(s);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s are worse than %s", buff, buff2);
        s.assign(buff);
        t.assign(buff2);
        r = 0;
        if (ed.find(s) != ed.end()) {
            if (dfs1(s, t)) {
                printf("Fact\n");
                r += 1;
            }
            vis.clear();
        }
        if (edr.find(s) != edr.end()) {
            if (dfs2(s, t)) {
                printf("Alternative Fact\n");
                r += 2;
            }
            vis.clear();
        }
        if (!r) printf("Pants on Fire\n");
        if (r == 3) return 1;
    }
    return 0;
}