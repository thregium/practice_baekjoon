#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 70)마리의 포켓몬의 이름과 진화시키는데 필요한 사탕 수, 현재 갖고 있는 사탕 수가 각각 주어진다.
이때, 진화시킬 수 있는 포켓몬의 마리 수와 가장 많이 진화시킬 수 있는 포켓몬 가운데 가장 먼저 나온 포켓몬의 이름을 출력한다.
포켓몬을 진화시킬 때 사탕 2개를 돌려받을 수 있다. 사탕 수는 1000 이하의 범위에서 주어진다. 진화시키는데 필요한 사탕 수는
12 이상으로 주어진다.

해결 방법 : 각 포켓몬마다 사탕을 진화시키는 데 필요한 양 이상 갖고 있는 동안 진화를 계속 시도한다.
진화를 모두 완료하고는 진화 횟수를 바탕으로 전체 진화 수와 가장 많이 진화한 포켓몬을 구해나가면 된다.

주요 알고리즘 : 구현

출처 : COCI 16/17#2 1번
*/

char poke[32], bpk[32];

int main(void) {
    int n, k, m, tot = 0, evo, bev = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", poke);
        scanf("%d %d", &k, &m);
        evo = 0;
        while (m >= k) {
            m -= k - 2;
            evo++;
        }
        if (evo > bev) {
            bev = evo;
            strcpy(bpk, poke);
        }
        tot += evo;
    }
    if (bev == 0) return 1;
    printf("%d\n%s", tot, bpk);
    return 0;
}