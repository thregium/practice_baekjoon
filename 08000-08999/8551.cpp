#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 10000)개의 정점으로 이루어진 무가중치 방향그래프에서 1번 정점에서 N번 정점으로 갈 수 없게 하기 위해
제거해야 할 최소 간선 개수를 구한다.

해결 방법 : 이는 1번 정점에서 N번 정점으로 향하는 최대 유량을 구하는 문제와 같다.
단, N이 상당히 크기 때문에 디닉 알고리즘을 이용해야 풀 수 있다.

주요 알고리즘 : 그래프 이론, 최대 유량, 최소 컷, 디닉

출처 : PA 2002.11 4-1번
*/

int level[10240], see[10240];
vector<pair<tuple<int, int, int>, int>> ed[10240]; // (nxt / usg / cap) / revi
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

void set_level(void) {
    int x;
    while (q.size()) q.pop();
    q.push(1);
    level[1] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto i : ed[x]) {
            if (get<1>(i.first) == get<2>(i.first) || level[get<0>(i.first)]) continue; //유량을 흘릴 수 없거나 이미 방문한 경우
            q.push(get<0>(i.first));
            level[get<0>(i.first)] = level[x] + 1; //최단거리 + 1이 레벨과 같다.
        }
    }
}

int dinic(int x, int e, int f) {
    if (x == e) return f; //종료 지점에 도달한 경우
    int ff;

    for (int i = see[x]; i < ed[x].size(); i++) {
        //마지막으로 확인한 곳의 다음 곳부터 확인
        if (level[get<0>(ed[x][i].first)] != level[x] + 1 || get<1>(ed[x][i].first) == get<2>(ed[x][i].first)) {
            see[x] = i + 1;
            continue;
        }
        //다음 레벨이 아니거나 유량을 흘릴 수 없는 간선은 통과
        ff = dinic(get<0>(ed[x][i].first), e, small(f, get<2>(ed[x][i].first) - get<1>(ed[x][i].first))); //전체 유량을 확인함
        if (ff) {
            //유량을 흘릴 수 있는 경우 유량을 흘리고 유량을 리턴
            get<1>(ed[x][i].first) += ff;
            get<1>(ed[get<0>(ed[x][i].first)][ed[x][i].second]) -= ff;
            return ff;
        }
        see[x] = i + 1; //마지막 확인 위치를 업데이트(이미 확인한 간선은 다시 볼 필요가 없음)
    }

    return 0; //유량 확인에 실패한 경우
}

int main(void) {
    int n, m, a, b, r = 0, c;
    tuple<int, int, int> t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(pair<tuple<int, int, int>, int>(make_tuple(b, 0, 1), ed[b].size()));
        ed[b].push_back(pair<tuple<int, int, int>, int>(make_tuple(a, 0, 0), ed[a].size() - 1));
    }
    while (1) {
        memset(level + 1, 0, n * sizeof(int));
        memset(see + 1, 0, n * sizeof(int));
        set_level();
        if (!level[n]) break; //더이상 유량 추가 불가시
        while (1) {
            c = dinic(1, n, INF);
            if (!c) break; //새로운 레벨 그래프 생성 필요시
            r += c;
        }
    }
    printf("%d", r);
    return 0;
}