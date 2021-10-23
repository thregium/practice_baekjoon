#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)명이 경매에 참가했다. 경매에 참가한 각 사람들은 U(U <= 10000) 이하의 자연수로 원하는 낙찰가를 적어서 낸다.
그 중 가장 적게 나온 낙찰가 가운데 가장 낮은 수가 최종 낙찰가가 된다. 최종 낙찰가를 적은 사람 가운데 가장 먼저 적은 사람이
물건을 낙찰받을 때, 낙찰받은 사람의 이름과 낙찰가를 출력한다. 이름은 10자 이하의 소문자로 주어진다.

해결 방법 : 낙찰가의 범위가 좁은 편이기 때문에 각 낙찰가의 개수를 세서, 가장 적게 나온 낙찰가 가운데
가장 낮은 수를 찾아서 최종 낙찰가를 구할 수 있다. 그러면 미리 입력받아놓은 가격과 이름들에 대해
최종 낙찰가를 적은 사람을 찾고 그 이름과 값을 출력하도록 하면 된다.

주요 알고리즘 : 구현
*/

char s[103000][16];
int price[103000], cnt[10240];

int main(void) {
    int u, n, best = -1, bc = INF;
    scanf("%d %d", &u, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", s[i], &price[i]);
        cnt[price[i]]++;
    }
    for (int i = 1; i <= u; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] < bc) {
            bc = cnt[i];
            best = i;
        }
    }
    if (best < 0) return 1;
    for (int i = 0; i < n; i++) {
        if (price[i] == best) {
            printf("%s %d", s[i], best);
            return 0;
        }
    }
    return 1;
}