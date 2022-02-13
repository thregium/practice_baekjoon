#include <stdio.h>

/*
문제 : M(M <= 100) 이하의 자연수로 이루어진 길이 N(N <= 100)의 배열 A가 주어질 때,
A의 각 자연수의 등장 횟수를 길이 M의 배열 B로 만들면 배열 B의 원소 가운데 최댓값을 구한다.

해결 방법 : 배열 B를 만든 다음 최댓값을 구하면 된다.

주요 알고리즘 : 구현

출처 : JOI 2020예1 2-3번
*/

int b[128];

int main(void) {
    int n, m, a, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        b[a]++;
    }
    for (int i = 1; i <= m; i++) {
        if (b[i] > r) r = b[i];
    }
    printf("%d\n", r);
    return 0;
}