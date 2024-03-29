#include <stdio.h>

/*
문제 : N(N <= 10)명의 선수가 카약 대회에 나갔다. S(S <= N)명의 카약이 손상되었는데, R(R <= N)명은 여분의 카약이 있다.
만약 여분의 카약이 있는 선수의 카약이 손상되었다면 그 카약을 이용해야 한다.
손상되지 않았다면 바로 옆 번호의 선수에게 그 카약을 줄 수 있다. 하지만 카약을 받은 선수는
다시 다른 선수한테 카약을 줄 수는 없다. 이때 카약을 이용할 수 없는 선수의 수를 최소한으로 하면 몇 명이 되는지 구한다.

해결 방법 : 먼저 입력받은 정보들로 선수별로 카약의 수를 구한다. 그 다음, 앞쪽부터 탐색하며 카약이 남는 선수들은
카약이 부족한 다른 선수들에게 카약을 나누어 주되, 앞쪽 선수부터 확인하며 먼저 오는 선수에게 나누어 주도록 한다.
이렇게 하여 최종적으로 최종적으로 카약이 모자란 선수들의 수를 세면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : COCI 09/10#6 2번
*/

int cnt[16];

int main(void) {
    int n, s, r, x;
    scanf("%d %d %d", &n, &s, &r);
    for (int i = 0; i < s; i++) {
        scanf("%d", &x);
        cnt[x]--;
    }
    for (int i = 0; i < r; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] <= 0) continue;
        for (int j = -1; j <= 1; j++) {
            if (cnt[i + j] < 0) {
                cnt[i + j]++;
                cnt[i]--;
                break;
            }
        }
    }
    r = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] < 0) r++;
    }
    printf("%d", r);
    return 0;
}