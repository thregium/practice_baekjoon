#include <stdio.h>

/*
문제 : 자연수(<= 2000)로 이루어진 길이 N(N <= 100)의 배열 A와 길이 M(M <= 100)의 배열 B가 주어질 때,
A와 B의 모든 값의 순서쌍 가운데 B의 값이 A의 값 이상인 순서쌍의 개수를 구한다.

해결 방법 : 두 배열의 길이가 작으므로 모든 순서쌍에 대해 B의 값이 A의 값 이상인 지 확인하면 된다.

주요 알고리즘 : 브루트 포스

출처 : JOI 2021예1 3-3번
*/

int a[128], b[128];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] <= b[j]) r++;
        }
    }
    printf("%d\n", r);
    return 0;
}