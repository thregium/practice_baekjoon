#include <stdio.h>

/*
문제 : 문제의 개수 N(N <= 100)과 풀 수 있는 최대 난이도 L(L <= 50), 시간 내에 풀 수 있는 문제의 개수 K(K <= N)가 주어지면
얻을 수 있는 최대 점수를 구한다. 모든 문제는 쉬운 서브태스크와 어려운 서브태스크로 나누어지고, 어려운 것을 해결하면
자동으로 쉬운 것도 해결된다. 쉬운 서브태스크는 100점, 어려운 서브태스크는 40점(+100점)이다.

해결 방법 : 어려운 서브태스크를 푸는 것이 시간상 더 유리하다. 따라서, 각 문제들 가운데 풀 수 있는 어려운
서브태스크를 미리 풀어둔 다음, 전부 다 풀면 쉬운 서브태스크를 풀고 점수를 확인하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 아주대 2019D1 A / 2019D2 A번
*/

int sub[128][2], vis[128];

int main(void) {
    int n, l, k, r = 0;
    scanf("%d %d %d", &n, &l, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &sub[i][0], &sub[i][1]);
        if (sub[i][1] <= l && k > 0) {
            vis[i] = 1;
            r += 140;
            k--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && sub[i][0] <= l && k > 0) {
            vis[i] = 1;
            r += 100;
            k--;
        }
    }
    printf("%d", r);
    return 0;
}