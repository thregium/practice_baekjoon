#include <stdio.h>

/*
문제 : N(N <= 100000)개의 에너지 드링크의 양(<= 10^9)이 주어질 때, 한 개만 남을 때 까지 한 드링크의 절반을
다른 드링크에 붓고 나머지는 버린다면 남는 것의 가능한 최대 양을 구한다.

해결 방법 : 가장 양이 많은 것에 나머지 드링크들을 부으면 된다. 전체 합의 절반에 최댓값의 절반을 더한 것이 답이 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 경북대 2020 D번
*/

int main(void) {
    int n, x, best = -1;
    double r = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > best) best = x;
        r += x / 2.0;
    }
    r += best / 2.0;
    printf("%.9f", r);
    return 0;
}