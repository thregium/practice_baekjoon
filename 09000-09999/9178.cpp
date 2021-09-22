#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : NV(NV <= 20)개의 정점으로 이루어진 무방향 가중치 그래프가 있다. 이때, SV 정점에서 DV정점으로 향하는
가중치합이 MAXDIST(MAXDIST <= 9999) 이하인 경로를 전부 찾고, 거리 순 -> 경로 사전 순으로 정렬해 출력한다.

해결 방법 : 백트래킹을 통해 SV에서 출발하는 경로를 전부 찾아본다. 이때, 중간에 경로의 거리가 MAXDIST를 넘어가는 경우
중간에 탐색을 종료해 시간을 절약한다. DV에 도달하면 해당 지점까지의 경로를 저장하고 다른 경로를 탐색해본다.
경로를 전부 탐색했다면 지금까지의 모든 경로들을 거리 순과 경로 사전 순으로 정렬해 둔다.
이제 정렬해둔 경로들을 각각 출력해두면 된다.

주요 알고리즘 : 그래프 이론, 백트래킹, 정렬

출처 : PacNW 2004 G번
*/

int chk[32];
vector<pair<int, int>> ed[32];
vector<int> path;
pair<int, vector<int>> res[1024];
int rp = 0;

void track(int sv, int dv, int dist, int maxdist) {
    chk[sv] = 1;
    path.push_back(sv);
    if (sv == dv) {
        res[rp].second = path;
        res[rp++].first = dist;
        chk[sv] = 0;
        path.pop_back();
        return;
    }
    for (auto i : ed[sv]) {
        if (chk[i.first]) continue;
        if (dist + i.second > maxdist) continue;
        track(i.first, dv, dist + i.second, maxdist);
    }
    chk[sv] = 0;
    path.pop_back();
}

int main(void) {
    int nv, nr, c1, c2, dist, sv, dv, maxdist;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\g.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\g_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &nv);
        if (nv < 0) break;
        scanf("%d", &nr);
        for (int i = 0; i < nr; i++) {
            scanf("%d %d %d", &c1, &c2, &dist);
            ed[c1].push_back(pair<int, int>(c2, dist));
            ed[c2].push_back(pair<int, int>(c1, dist));
        }
        scanf("%d %d", &sv, &dv);
        scanf("%d", &maxdist);

        rp = 0;
        track(sv, dv, 0, maxdist);
        sort(res, res + rp);
        
        if (tt > 1) printf("\n");
        printf("Case %d:\n", tt);
        for (int i = 0; i < rp; i++) {
            printf(" %d: ", res[i].first);
            for (int j = 0; j < res[i].second.size(); j++) {
                printf("%d", (res[i].second)[j]);
                printf(" ");
            }
            printf("\n");
        }
        if (rp == 0) printf(" NO ACCEPTABLE TOURS\n");
        for (int i = 1; i <= nv; i++) {
            ed[i].clear();
        }
    }
    return 0;
}