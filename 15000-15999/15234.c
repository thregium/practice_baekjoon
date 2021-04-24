#include <stdio.h>

/*
문제 : N(N <= 1000)개의 수로 이루어진 배열이 있을 때, 두 수의 합이 K가 되는 쌍의 갯수를 구한다.

해결 방법 : N의 제한이 작은 편이므로 모든 쌍에 대해 합이 K인지 검사하고 그 갯수를 세면 된다.

주요 알고리즘 : 브루트 포스

출처 : AIPO 2017P 3번
*/

int a[1024];

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) r++;
        }
    }
    printf("%d", r);
    return 0;
}