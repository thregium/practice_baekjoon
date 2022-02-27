#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 100000)개의 도미노와 M(M <= 100000)개의 도미노 사이 관계(X가 무너지면 Y도 무너짐)가 주어지면,
도미노를 전부 무너뜨리기 위해 무너뜨려야 하는 도미노의 최소 개수를 구한다.

해결 방법 : 어느 하나를 무너뜨려도 서로 전부 무너지는 도미노의 집합이 SCC이므로 SCC를 구한 다음,
각 SCC 사이의 관계를 간선으로 이어 DAG를 만든 다음, 진입 차수가 0인 SCC의 개수를 구하면 된다.
초기화에 유의한다.

주요 알고리즘 : 그래프 이론, SCC

출처 : Waterloo 20080927 D번
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
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
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