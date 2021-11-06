#include <stdio.h>

/*
문제 : N 이상 M(1 <= N <= M <= 5000) 이하의 자연수 가운데 같은 숫자가 2번 이상 나오지 않는 수의 개수를 구한다.

해결 방법 : N부터 M 사이의 수를 일일히 확인하며 각 자릿수의 등장 횟수를 구한다. 모든 자릿수 가운데
등장 횟수가 2 이상인 것이 있는지 확인하고 없는 것의 개수를 세면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : Latin 2012 D번
*/

int cnt[10];

int main(void) {
    int n, m, r, t;
    while (scanf("%d %d", &n, &m) != EOF) {
        r = 0;
        for (int i = n; i <= m; i++) {
            for (int j = i; j; j /= 10) cnt[j % 10]++;
            t = 1;
            for (int j = 0; j < 10; j++) {
                if (cnt[j] > 1) t = 0;
                cnt[j] = 0;
            }
            r += t;
        }
        printf("%d\n", r);
    }
    return 0;
}