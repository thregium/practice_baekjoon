#include <stdio.h>

/*
문제 : 2개 또는 3개의 10^8 이하인 수에 대해 공약수를 전부 구한다.

해결 방법 : 1부터 임의의 한 수(최솟값이면 더 좋다)까지 모든 수에 대해 각각에 대해 약수인지 확인하고 공약수라면 출력한다.

주요 알고리즘 : 브루트 포스, 수학, 사칙연산

출처 : JOI 2006모1 2번
*/

int a[16];

int main(void) {
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= a[0]; i++) {
        t = 1;
        for (int j = 0; j < n; j++) {
            if (a[j] % i) t = 0;
        }
        if (!t) continue;
        printf("%d\n", i);
    }
    return 0;
}