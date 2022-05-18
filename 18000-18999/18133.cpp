#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 유향 그래프에서
모든 점을 지나는 것이 가능하도록 하는 시작점의 최소 개수를 구한다.

해결 방법 : SCC를 구한 후 SCC 가운데 진입 차수가 0인 것의 개수를 세면 된다.

주요 알고리즘 : 그래프 이론, SCC

출처 : 가톨릭대 1회 D번
*/

int order[103000], stack[103000], fin[103000];
int cnt = 1, sp = 0, cp = 0;
vector<int> ed[103000], scc[103000];
int color[103000], ins[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int dfs(int x) {
    //도달 가능한 가장 앞 정점을 반환, 현재 정점 외에 없는 경우 SCC 추출
    order[x] = cnt++;
    stack[sp++] = x;

    int r = order[x];
    for (int nxt : ed[x]) {
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
        for (int i : scc[cp]) {
            color[i] = cp;
        }
        cp++;
    }

    return r;
}

int main(void) {
    int t, v, e, a, b, r = 0;
    //scanf("%d", &t);
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d %d", &v, &e);
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            ed[a].push_back(b);
        }
        for (int i = 1; i <= v; i++) {
            if (order[i]) continue;
            dfs(i);
        }
        for (int i = 1; i <= v; i++) {
            for (int j : ed[i]) {
                if (color[i] != color[j]) ins[color[j]]++;
            }
        }
        for (int i = 0; i < cp; i++) {
            if (ins[i] == 0) r++;
        }
        printf("%d\n", r);

        for (int i = 1; i <= v; i++) {
            order[i] = 0;
            fin[i] = 0;
            color[i] = 0;
            ed[i].clear();
        }
        for (int i = 0; i < cp; i++) {
            scc[i].clear();
            ins[i] = 0;
        }
        cnt = 1, sp = 0, cp = 0, r = 0;
    }
    return 0;
}