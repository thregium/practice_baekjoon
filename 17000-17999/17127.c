#include <stdio.h>

/*
문제 : N(4 <= N <= 10)개의 자연수(<= 5)로 이루어진 배열이 있다. 이 배열을 4개로 나눌 때 만들 수 있는
나누어진 배열 원소의 곱의 합 가운데 가장 큰 것을 고른다.

해결 방법 : N이 매우 작기 때문에 배열을 4개로 나누는 모든 경우를 시도해 보며 곱의 합을 구해나가면 된다.

주요 알고리즘 : 브루트 포스

출처 : 숭실대 2019C A번
*/

int che[16];

int main(void) {
    int n, a, b, c, d, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &che[i]);
    }
    for (int i = 0; i < n; i++) {
        a = 1;
        for (int j = 0; j <= i; j++) a *= che[j];
        for (int j = i + 1; j < n; j++) {
            b = 1;
            for (int k = i + 1; k <= j; k++) b *= che[k];
            for (int k = j + 1; k < n - 1; k++) {
                c = 1;
                for (int l = j + 1; l <= k; l++) c *= che[l];
                d = 1;
                for (int l = k + 1; l < n; l++) d *= che[l];
                if (a + b + c + d > r) r = a + b + c + d;
            }
        }
    }
    if (r <= 0) return 1;
    printf("%d", r);
    return 0;
}