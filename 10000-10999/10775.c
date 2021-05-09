#include <stdio.h>

/*
문제 : G개의 게이트에 P(G, P <= 100000)대의 비행기들을 도킹시키려 한다. 각 비행기들은 1 ~ pi(pi <= G)번 게이트 중 하나에 도킹시킬 수 있다.
이때, 비행기들은 들어오는 순서대로 처리해야 하고 도킹이 불가능하다면 즉시 모든 과정을 중단한다.
이때 가장 많이 도킹한 경우 처리 가능한 비행기의 대수를 구한다.

해결 방법 : 각 비행기들을 처리 가능한 게이트 가운데 가장 번호가 높은 게이트에 도킹시키면 된다.
그 게이트를 찾는 방법으로는 유니온 파인드를 응용하면 되는데, 그룹의 대표를 해당 번호 이하에서 도킹 가능한 게이트 가운데 가장 번호가 큰 게이트로 놓고,
비행기가 들어올 때 마다 pi가 해당하는 그룹을 찾아 그 대표를 번호가 1 작은 그룹에 연결시키면 된다.
만약 그 게이트가 1번까지 찬 경우에는 도킹이 불가능하므로 집계를 종료하고 현재까지 처리한 비행기의 대수를 출력한다.

주요 알고리즘 : 그리디 알고리즘, 유니온 파인드

출처 : CCC 2015S 3번
*/

int gates[103000];

int find(int x) {
    if (gates[x] == 0) return x;
    else return gates[x] = find(gates[x]);
}

int main(void) {
    int g, p, a, r = 0;
    scanf("%d%d", &g, &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &a);
        if (gates[a] == 0) {
            r++;
            gates[a] = a - 1;
            if (a == 1) gates[a] = -1;
        }
        else {
            if (find(a) > 0) {
                if (find(a) == 1) gates[find(a)] = -1;
                else gates[find(a)] = find(a) - 1;
                r++;
            }
            else break;
        }
    }
    printf("%d", r);
    return 0;
}