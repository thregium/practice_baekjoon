#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : 정점이 V(V <= 10000)개인 그래프에서 모든 SCC들을 추출한다.

해결 방법 : 타잔 알고리즘을 이용한다.

주요 알고리즘 : 그래프 이론, SCC
*/

int order[10240], stack[10240], fin[10240];
int cnt = 1, sp = 0, cp = 0;
vector<int> edge[10240], scc[10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int dfs(int x) {
    //도달 가능한 가장 앞 정점을 반환, 현재 정점 외에 없는 경우 SCC 추출
    order[x] = cnt++;
    stack[sp++] = x;

    int r = order[x];
    for (int nxt : edge[x]) {
        //인접한 정점들에 대해 체크
        if (order[nxt] == 0) r = small(r, dfs(nxt)); //아직 방문하지 않은 정점인 경우
        else if (!fin[nxt]) r = small(r, order[nxt]); //아직 SCC를 뽑지 않은 정점인 경우
    }

    if (r == order[x]) {
        //SCC 추출
        while (1) {
            scc[cp].push_back(stack[--sp]);
            fin[stack[sp]] = 1;
            if (stack[sp] == x) break; //X가 나올 때 까지 스택의 원소들을 추출
        }
        sort(scc[cp].begin(), scc[cp].end());
        cp++;
    }

    return r;
}

int main(void) {
    int v, e, a, b;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
    }
    for (int i = 1; i <= v; i++) {
        if (order[i]) continue;
        dfs(i);
    }
    sort(scc, scc + cp);
    printf("%d\n", cp);
    for (int i = 0; i < cp; i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            printf("%d ", scc[i][j]);
        }
        printf("-1\n");
    }
    return 0;
}