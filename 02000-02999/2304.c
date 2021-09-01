#include <stdio.h>

/*
문제 : N(N <= 1000)개의 기둥의 위치와 높이가 주어질 때, 창고 다각형의 넓이를 구한다. 창고 다각형은, 수직과 수평 부분으로
연결된 다각형이고, 각 수평, 수직 부분은 기둥과 닿아야 하며, 오목하지 않은 다각형이다.

해결 방법 : 이러한 창고 다각형의 각 지점에서의 높이는 1부터 끝 지점까지의 누적 높이 최댓값과, 반대 방향으로 누적 높이
최댓값 가운데 더 작은 것이다. 이를 1부터 끝점까지 반복하여 찾아내면 된다.

주요 알고리즘 : 구현?

출처 : 정올 2005 초2번
*/

int a[1024], lbest[1024], rbest[1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, l, h, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &h);
        a[l] = h;
    }
    for (int i = 1; i <= 1000; i++) {
        if (a[i] > lbest[i - 1]) lbest[i] = a[i];
        else lbest[i] = lbest[i - 1];
    }
    for (int i = 1000; i > 0; i--) {
        if (a[i] > rbest[i + 1]) rbest[i] = a[i];
        else rbest[i] = rbest[i + 1];
    }
    for (int i = 1; i <= 1000; i++) {
        r += small(lbest[i], rbest[i]);
    }
    printf("%d", r);
    return 0;
}