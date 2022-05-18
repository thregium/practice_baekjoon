#include <stdio.h>

/*
문제 : N(N <= 30)개의 블록 중 K(K <= 12)개 이하를 담아서 전체 무게가 S(S <= 10^6) 이하가 되는 집합
가운데 가장 무거운 집합의 무게를 찾는다. 각 블록의 무게는 S 이하다.

해결 방법 : S 이내의 모든 무게 범위에 대해 냅색을 한다. 각 개수마다 해당 무게가 가능한 지 여부를
저장해나가며 한다. 냅색이 끝나면 전체 범위에 대해 S 이하 무게의 가장 무거운 것을 찾으면 된다.

주요 알고리즘 : DP, 냅색

출처 : JPOI 2009 3-2번
*/

char mem[16][1048576];

int main(void) {
    int n, k, s, m, r = 0;
    scanf("%d %d %d", &n, &k, &s);
    mem[0][0] = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = k; j >= 1; j--) {
            if (j > i + 1) continue;
            for (int w = m; w <= s; w++) mem[j][w] |= mem[j - 1][w - m];
        }
    }
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= k; j++) {
            if (mem[j][i]) r = i;
        }
    }
    printf("%d", r);
    return 0;
}