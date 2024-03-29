#include <stdio.h>

/*
문제 : N(N <= 100)개의 항을 가진 다항함수 f(x)가 주어질 때, f'(1)의 값을 구한다.
이때, 같은 항은 2번 이상 주어지지 않고, 각 항의 차수는 0 이상 1000 이하의 정수이다.
또한, 각 항의 계수는 절댓값이 100 이하인 정수이다.

해결 방법 : 각 항을 미분하면 그 항의 계수는 차수 * 계수가 된다. x가 1이므로 x에 관한 것은 신경 쓸 필요 없이
모든 항의 계수를 더하면 되고, 차수 * 계수를 전부 더한 것이 답이 된다.

주요 알고리즘 : 수학, 미적분학

출처 : 중앙대 2017P E번
*/

int main(void) {
    int n, c, k, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &k);
        r += c * k;
    }
    printf("%d", r);
    return 0;
}
