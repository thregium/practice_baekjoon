#include <stdio.h>

/*
문제 : N(N <= 20)이하의 서로 다른 자연수 K(K <= 10)개를 뽑아서 더한 수가 S(S <= 155) 이하가 되는 집합의 개수를 구한다.

해결 방법 : N과 K가 충분히 작기 때문에 백트래킹을 통해 모든 경우를 살펴보며 합이 S인 것의 개수를 세면 된다.

주요 알고리즘 : 백트래킹

출처 : Aizu 2013 A번
*/

int r = 0;

void track(int n, int k, int s, int l) {
    if (k == 0) {
        if (s == 0) r++;
        return;
    }
    for (int i = l + 1; i <= n; i++) {
        if (s >= i) track(n, k - 1, s - i, i);
    }
}

int main(void) {
    int n, k, s;
    while (1) {
        scanf("%d %d %d", &n, &k, &s);
        if (n == 0) break;
        r = 0;
        track(n, k, s, 0);
        printf("%d\n", r);
    }
    return 0;
}