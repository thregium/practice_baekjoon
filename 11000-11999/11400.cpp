#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : V(V <= 100000)개의 정점과 E(E <= 10^6)개의 간선으로 이루어진 양방향 그래프에서 단절선을 모두 찾고 정렬하여 출력한다.

해결 방법 : BCC를 찾는 알고리즘을 약간 변형하여 풀 수 있다. 만약 DFS 트리에서 다음 정점을 살펴본 결과
현재 정점보다 아래에서만 움직이는 경우 다음 정점에서 현재 정점 또는 그 위로 오려면 반드시 현재 간선을 지나야 하기 때문에
현재 간선은 단절선이 된다. 이런 식으로 단절선을 모두 찾고 정렬하여 출력하면 된다.

주요 알고리즘 : 그래프 이론, BCC, 단절선
*/

int dfsn[103000];
int dfsc = 0, sttp = 0;
pair<int, int> stack[1048576];
vector<int> ed[103000];
vector<vector<pair<int, int>>> bcc;
vector<pair<int, int>> artic;

int small(int x, int y) {
    return x < y ? x : y;
}
int big(int x, int y) {
    return x > y ? x : y;
}

int dfs(int cur, int prev) {
    //해당 정점에 dfsn 부여 후 도달 가능한 최고 지점 반환
    dfsn[cur] = ++dfsc;
    int res = dfsc;
    int ndfsn;

    for (int next : ed[cur]) {
        if (next == prev) continue;

        if (dfsn[cur] > dfsn[next]) {
            stack[sttp++] = pair<int, int>(cur, next); //방문하지 않은 간선을 스택에 추가
        }
        if (dfsn[next] > 0) res = small(res, dfsn[next]); //역방향(이미 방문한 경우)
        else {
            ndfsn = dfs(next, cur); //다음 간선 확인
            res = small(res, ndfsn);
            //더 위로 갈 수 없는 경우 BCC 추가
            if (ndfsn >= dfsn[cur]) {
                vector<pair<int, int>> cbcc;
                while (sttp > 0 && stack[sttp - 1] != pair<int, int>(cur, next)) {
                    cbcc.push_back(stack[sttp - 1]);
                    sttp--;
                }
                cbcc.push_back(stack[sttp - 1]);
                sttp--;
                bcc.push_back(cbcc);
            }
            if (ndfsn > dfsn[cur]) {
                artic.push_back(pair<int, int>(small(cur, next), big(cur, next))); 
                //단절선 추가(현재 정점 아래로만 움직일 경우)
            }
        }
    }
    return res;
}

int main(void) {
    int v, e, a, b;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) {
        if (dfsn[i] == 0) dfs(i, -1);
    }
    printf("%d\n", artic.size());
    sort(artic.begin(), artic.end());
    for (int i = 0; i < artic.size(); i++) {
        printf("%d %d\n", artic[i].first, artic[i].second);
        if (i > 0 && artic[i].first == artic[i - 1].first && artic[i].second == artic[i - 1].second) return 1;
    }
    return 0;
}