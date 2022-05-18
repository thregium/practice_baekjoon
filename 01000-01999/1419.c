#include <stdio.h>

/*
문제 : [L, R](1 <= L <= R <= 10^9) 범위에서 초항과 공차가 모두 자연수인 길이 K(2 <= K <= 5)
등차수열의 합으로 나타낼 수 있는 자연수의 개수를 구한다.

해결 방법 : K의 값에 따라 경우를 나누어 해결한다. K = 2인 경우 3 이상의 모든 자연수가 가능하고,
3인 경우 6 이상의 모든 3의 배수가 가능하며, 4인 경우 14 이상의 모든 짝수 또는 10이 가능하다.
마지막으로 5인 경우는 15 이상의 5의 배수인 경우 가능하다.

주요 알고리즘 : 수학, 케이스 워크

출처 : SRM 385 D1C
*/

int main(void) {
    int l, r, k, res = 0;
    scanf("%d %d %d", &l, &r, &k);
    if (k == 2) {
        if (l < 3) l = 3;
        printf("%d", r - l + 1);
    }
    else if (k == 3) {
        for (int i = 6; i <= r; i += 3) {
            if (l <= i) res++;
        }
        printf("%d", res);
    }
    else if (k == 4) {
        for (int i = 14; i <= r; i += 2) {
            if (l <= i) res++;
        }
        if (l <= 10 && 10 <= r) res++;
        printf("%d", res);
    }
    else if (k == 5) {
        for (int i = 15; i <= r; i += 5) {
            if (l <= i) res++;
        }
        printf("%d", res);
    }
    return 0;
}