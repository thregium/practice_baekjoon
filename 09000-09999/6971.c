#include <stdio.h>

/*
문제 : 자연수 N(N <= 32000)이 주어질 때, 곱해서 N이 되는 두 쌍 중 한 쌍의 차와 다른 한 쌍의 합이 같은 쌍이 있는지 구한다.

해결 방법 : N의 약수를 구하면 양쪽 끝에서부터 서로를 곱한 값이 N이 된다. 따라서, N의 모든 약수를 구한 다음,
두 개의 약수들을 일일히 확인한다. 그리고 하나의 약수는 반대쪽 약수와의 차를, 다른 약수는 반대쪽 약수와의 합을 찾는다.
두 값이 같아지는 경우가 나온다면 그러한 쌍이 나온 것이고, 나오지 않는다면 그러한 쌍이 없는 것이다.

주요 알고리즘 : 수학, 정수론

출처 : CCC 1997 2번
*/

int div[256];

int main(void) {
    int t, n, p, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        p = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) div[p++] = i;
        }
        r = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                //if (i == j || i == p - j - 1) continue;
                if (div[p - i - 1] - div[i] == div[j] + div[p - j - 1]) r++;
            }
        }
        if (r) printf("%d is nasty\n", n);
        else printf("%d is not nasty\n", n);
    }
    return 0;
}