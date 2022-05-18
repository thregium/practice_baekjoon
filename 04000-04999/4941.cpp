#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 3000)개의 도로와 M(M <= 300)개의 주유소가 있다. 한번의 주유로 C(C <= 200) * 10 Km를
이동할 수 있다고 할 때, 주어진 두 도시 사이를 이동 가능한 지 구한다.
모든 도로는 자기 자신과 연결되거나 두 도시 사이 여러 도로가 직접 연결되지 않는다.
도시 사이 거리는 2000 이하고, 시작점과 끝점에는 주유소가 없어도 된다.

해결 방법 : 우선 주유소가 있는 도시, 시작점, 끝점에서 다른 도시로 다익스트라를 이용하여
거리를 체크한다. 그 후 주유소가 있는 쌍 끼리 거리를 구하고 길이가 C * 10 이하인 간선으로
새로운 그래프를 만들어준다. 다시 새로운 그래프를 이용해서 시작점과 끝점 사이의 거리를 구하면
답이 된다. 이 과정에서 해시를 그대로 이용하면 시간 초과가 날 수 있기 때문에
자연수로 각 정점의 번호를 바꾸어주는 과정이 필요하다.

주요 알고리즘 : 그래프 이론, 다익스트라, 해시맵, 해시셋

출처 : Fukuoka 2011 D번
*/

char buff1[32], buff2[32];
unordered_map<string, vector<pair<string, int>>> ed;
vector<pair<int, int>> edn[6144], edn2[6144];
unordered_map<string, int> nodenm;
int distn[6144], visn[6144];
unordered_set<string> city, lpg;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void dijk(int src, int n, int m, int cap) {
    int node, d;
    for (int i = 1; i <= n; i++) {
        distn[i] = cap + 1;
        visn[i] = 0;
    }
    
    while (pq.size()) pq.pop();
    pq.push({ 0, src });
    while (pq.size()) {
        node = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if (visn[node]) continue;
        else visn[node] = 1;
        for (auto& i : edn[node]) {
            if (d + i.second < distn[i.first]) {
                distn[i.first] = d + i.second;
                pq.push({ distn[i.first], i.first });
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (distn[i] <= cap) {
            edn2[src].push_back({ i, distn[i] });
        }
    }
}

int dijk2(int src, int dest, int n) {
    int node;
    int d;
    for (int i = 1; i <= n; i++) {
        distn[i] = INF;
        visn[i] = 0;
    }

    while (pq.size()) pq.pop();
    pq.push({ 0, src });
    while (pq.size()) {
        node = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if (node == dest) return d;
        if (visn[node]) continue;
        else visn[node] = 1;
        for (auto& i : edn2[node]) {
            if (d + i.second < distn[i.first]) {
                distn[i.first] = d + i.second;
                pq.push({ distn[i.first], i.first });
            }
        }
    }

    return -1;
}

int main(void) {
    string src, dest;
    int n, m, cap, x;
    while (1) {
        scanf("%d %d %d", &n, &m, &cap);
        if (n == 0 && m == 0 && cap == 0) break;
        else cap *= 10;
        scanf("%s %s", buff1, buff2);
        src = buff1, dest = buff2;
        for (int i = 0; i < n; i++) {
            scanf("%s %s %d", buff1, buff2, &x);
            if (ed.find(buff1) == ed.end()) ed.insert({ buff1, {{buff2, x}} });
            else ed[buff1].push_back({ buff2, x });
            if (ed.find(buff2) == ed.end()) ed.insert({ buff2, {{buff1, x}} });
            else ed[buff2].push_back({ buff1, x });
            if (city.find(buff1) == city.end()) city.insert(buff1);
            if (city.find(buff2) == city.end()) city.insert(buff2);
        }
        for (int i = 0; i < m; i++) {
            scanf("%s", buff1);
            lpg.insert(buff1);
        }
        lpg.insert(src);
        lpg.insert(dest);
        nodenm.insert({ src, 1 });
        nodenm.insert({ dest, 2 });
        m = 2;
        for (auto& i : lpg) {
            if (i == src || i == dest) continue;
            nodenm.insert({ i, ++m });
        }
        n = m;
        for (auto& i : city) {
            if (lpg.find(i) != lpg.end()) continue;
            nodenm.insert({ i, ++n });
        }
        for (auto& i : ed) {
            for (auto& j : i.second) {
                edn[nodenm[i.first]].push_back({nodenm[j.first], j.second});
            }
        }


        for (int i = 1; i <= m; i++) {
            dijk(i, n, m, cap);
        }
        printf("%d\n", dijk2(1, 2, m));


        city.clear();
        lpg.clear();
        ed.clear();
        for (int i = 1; i <= n; i++) {
            edn[i].clear();
            edn2[i].clear();
        }
        nodenm.clear();
    }
    return 0;
}