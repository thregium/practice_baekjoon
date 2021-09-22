#include <stdio.h>

/*
문제 : N(N <= 10000)개의 자연수 가운데 평균 이하인 자연수의 개수를 구한다.

해결 방법 : 모든 수의 합을 구한 다음, N으로 나눈 값이 평균값(을 버림한 값)이 된다. 이 값 이하면 평균 이하가 되므로,
이 값 이하인 값의 개수를 구하면 된다.

주요 알고리즘 : 수학, 구현

출처 : JDC 2018 A번
*/

int a[10240];

int main(void) {
    int n, s, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        s /= n;
        r = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= s) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}