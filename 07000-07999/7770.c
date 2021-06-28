#include <stdio.h>

/*
문제 : 블록 N(N <= 10^9)개를 사용해 만들 수 있는 가장 높은 안정된 피라미드의 높이를 구한다.
안정된 피라미드는 위에 올라간 블록의 아래 블록은 전부 옆면에 다른 블록이 있는 피라미드이다.

해결 방법 : 맨 위층부터 아래층으로 한층씩 내려갈 때마다 사용한 블록의 개수는 층수 * 4개만큼 늘어나야 한다는 것을 알 수 있다.
이를 이용해 각 층의 블록 수를 구하고, 해당 층을 만들 수 없을 때, 그 값을 구하면 된다.

주요 알고리즘 : 수학?

출처 : NRRC 2012 A번
*/

int main(void) {
    int n, f = 1, r = 0;
    scanf("%d", &n);
    while (n >= 0) {
        n -= f;
        if (n < 0) break;
        f += 4 * (r + 1);
        r++;
    }
    printf("%d", r);
    return 0;
}