#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 초콜릿을 왼쪽과 오른쪽 부분으로 나누었다. 양 쪽의 초콜릿 형태가 주어질 때,
일부분이 사라졌는지 구한다. 돌려지거나 뒤집히지 않은 형태이다. 이를 T(T <= 100)번 반복한다.

해결 방법 : 각 줄마다 양 부분의 초콜릿 합이 모두 N이라면 사라지지 않은 것이고 N보다 작은 것이 하나라도 있다면 사라진 것이다.

주요 알고리즘 : 수학

출처 : RCC 2012Q3 A번
*/

int main(void) {
    int t, n, l, r, res;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &l, &r);
            if (l + r > n) return 1;
            else if (l + r < n) res = 1;
        }
        printf("%s\n", res ? "yes" : "no");
    }
    return 0;
}