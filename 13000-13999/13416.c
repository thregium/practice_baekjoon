#include <stdio.h>

/*
문제 : N(N <= 1000)일간 A, B, C 중 하나를 한 개 얻을 수 있을 때, A, B, C의 이익이 매 날짜마다 주어진다면
얻을 수 있는 최대 이익을 구한다.

해결 방법 : 매일 이익이 가장 큰 것을 고른다. 만약 그것의 이익이 0 이하라면, 버리고, 이상인 경우 가져온다.
이를 반복해 가져온 것의 이익 합을 구하면 된다.

주요 알고리즘 : 구현

출처 : 국민대 2016 D번
*/

int big3(int a, int b, int c) {
    if (a > b && a > c) return a;
    else if (b > c) return b;
    else return c;
}

int main(void) {
    int t, n, a, b, c, d, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &a, &b, &c);
            d = big3(a, b, c);
            if (d > 0) r += d;
        }
        printf("%d\n", r);
    }
    return 0;
}