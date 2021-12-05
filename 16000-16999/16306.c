#include <stdio.h>
#define INF 1012345678

/*
문제 : 부피 V(V <= 10^6)이며 각 변의 길이가 자연수인 직육면체 가운데 가장 겉넓이가 작은 것의 겉넓이를 구한다.

해결 방법 : 가능한 모든 경우에 대해 겉넓이를 구해보고 그 가운데 가장 작은 것을 구하면 된다.

주요 알고리즘 : 브루트 포스, 수학, 정수론

출처 : BAPC 2018 C번
*/

int main(void) {
    int n, k, r = INF;
    scanf("%d", &n);
    for (int i = 1; i * i * i <= n; i++) {
        for (int j = i; i * j * j <= n; j++) {
            if (n % (i * j)) continue;
            k = n / i / j;
            if (2 * (i * j + i * k + j * k) < r) r = 2 * (i * j + i * k + j * k);
        }
    }
    printf("%d", r);
    return 0;
}