#include <stdio.h>

/*
문제 : K(K <= 6)개의 디지털 숫자로 이루어진 자연수 X(X < 10^K)가 주어진다.
이때, 이 수에서 LED 1개 이상 P(P <= 42)개 이하를 반전시켜 만들 수 있는
1 이상 N(K <= N < 10^K) 이하의 자연수 개수를 구한다.

해결 방법 : 각 숫자의 켜진 LED를 비트마스킹을 통해 미리 저장해 둔다.
그리고 1부터 N까지의 자연수마다 서로 다른 LED의 수를 구해나간다. 이는 각 자리 숫자를 확인한 뒤,
두 숫자의 켜진 LED 수 차이를 비트마스킹을 통해 확인하는 것으로 구할 수 있다.
서로 다른 LED의 수가 1 이상 N 이하인 것의 수를 센 다음 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스, 비트마스킹

출처 : 류호석 3회 1번
*/

char digit[10] = { 119, 36, 93, 109, 46, 107, 123, 37, 127, 111 };

int main(void) {
    int n, k, p, x, r = 0, dx, di, diff;
    scanf("%d %d %d %d", &n, &k, &p, &x);
    for (int i = 1; i <= n; i++) {
        diff = 0;
        for (int j = 0, xx = x, ii = i; j < k; j++, xx /= 10, ii /= 10) {
            dx = xx % 10;
            di = ii % 10;
            for (int bit = 0; bit < 7; bit++) diff += (((digit[dx] >> bit) & 1) ^ ((digit[di] >> bit) & 1));
        }
        if (diff > 0 && diff <= p) r++;
    }
    printf("%d", r);
    return 0;
}