#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : 정점 V(V <= 10000)개, 간선 E(E <= 100000)개인 그래프에서 제거하면 연결 요소의 개수가 늘어나는 정점의 개수와 정점들을 찾는다.

해결 방법 : 모든 간선에 대한 BCC를 구한 후 서로 다른 2개 이상의 BCC에 속하는 정점들을 찾으면 그 정점들이 단절점이 된다.

주요 알고리즘 : 그래프 이론, BCC, 단절점
*/

int dfsn[10240], chk[10240], cnt[10240], dfsc = 1;
vector<int> ed[10240], spf;
vector<pair<int, int>> st;
vector<vector<pair<int, int>>> bcc;

int dfs(int cur, int prev) {
    dfsn[cur] = dfsc++;
    int res = dfsn[cur];
    int nres;

    for (int next : ed[cur]) {
        if (next == prev) continue;
        if (dfsn[cur] > dfsn[next]) st.push_back(pair<int, int>(cur, next));

        if (dfsn[next] > 0 && dfsn[next] < res) res = dfsn[next];
        if (dfsn[next] == 0) {
            nres = dfs(next, cur);
            if (nres < res) res = nres;
            if (nres >= dfsn[cur]) {
                vector<pair<int, int>> cbc;
                while (st.size() && st[st.size() - 1] != pair<int, int>(cur, next)) {
                    cbc.push_back(st[st.size() - 1]);
                    st.pop_back();
                }
                cbc.push_back(st[st.size() - 1]);
                st.pop_back();
                bcc.push_back(cbc);
            }
        }
    }
    
    //if (res == dfsn[cur] && ed[cur].size() > 1 && prev >= 0) spf.push_back(cur);

    return res;
}

int main(void) {
    int v, e, a, b, lbc = 0;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) {
        if (dfsn[i] == 0) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < bcc.size(); i++) {
        for (int j = 0; j < bcc[i].size(); j++) {
            chk[bcc[i][j].first] = 1;
            chk[bcc[i][j].second] = 1;
        }
        for (int j = 1; j <= v; j++) {
            cnt[j] += chk[j];
            chk[j] = 0;
        }
    }

    for (int i = 1; i <= v; i++) {
        if (cnt[i] >= 2) spf.push_back(i);
    }
    printf("%d\n", spf.size());
    for (int i = 0; i < spf.size(); i++) {
        printf("%d ", spf[i]);
    }
    return 0;
}