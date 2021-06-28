#include <stdio.h>

/*
문제 : X * a + Y * b = W이고, X + Y = N이라고 할 때, X와 Y의 값을 구한다. 단, 주어지는 모든 수는 1000 이하이고,
답이 1개가 아니라면 -1을 출력한다.

해결 방법 : 1부터 N - 1까지 모든 수를 살펴보며 답이 되는 X의 수와 그때의 X를 구한다.
여기서 X의 수가 1이 아니라면 -1을 출력하면 되고, 1이라면 X와 N - X(N - X = Y)를 출력하면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : Seoul 2018I B번
*/

int main(void) {
    int a, b, n, w, x = -1, c = 0;
    scanf("%d %d %d %d", &a, &b, &n, &w);
    for (int i = 1; i < n; i++) {
        if (a * i + b * (n - i) == w) {
            x = i;
            c++;
        }
    }
    if (c == 1) printf("%d %d", x, n - x);
    else printf("-1");
    return 0;
}