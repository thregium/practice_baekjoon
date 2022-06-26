#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^6)장의 종이와 N벌의 셔츠가 각각 있다. 현재 종이와 셔츠가 놓인 상태가 주어질 때,
각각을 고대로 놓이도록 하기 위해 인접한 것 끼리 순서를 바꾸는 연산을 얼마나 해야 하는 지 구한다.

해결 방법 : 셔츠(0)가 위치하는 지점과 위치해야 하는 지점을 잡고 각 지점의 거리 차이를 더하면
이동해야 하는 최소 거리가 된다.(각 셔츠의 순서를 바꾸지 않는 것이 가장 빠르므로)
셔츠를 앞쪽부터 놓는 경우와 뒤쪽부터 놓는 경우 두 가지를 비교해 더 적은 쪽으로 하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : PA 2007 3-1번
*/

int a[1048576 * 2], shirt[1048576];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, sc = 0;
    long long res1 = 0, res2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) shirt[sc++] = i;
    }
    if (sc != n) return 1;
    for (int i = 0; i < n; i++) {
        res1 += abs(shirt[i] - i * 2 - 1);
    }
    for (int i = 0; i < n; i++) {
        res2 += abs(shirt[i] - i * 2);
    }
    printf("%lld", small(res1, res2));
    return 0;
}