#include <stdio.h>

/*
문제 : 길이 N(N <= 200000)의 배열에 2^30보다 작은 자연수들이 적혀있다. 이때, 이 배열의 일정한 구간의 값을
전부 OR한 값이 자연수 K(K < 2^30)인 구간이 있는 지 구하고, 있다면 그러한 구간 가운데 하나를 출력한다.

해결 방법 : OR해서 K를 만들 수 있는(K와 OR한 값이 K인) 값들을 전부 기록해둔다.
그리고 기록된 칸들만으로 이루어진 구간을 모두 확인해보며 OR한 값이 K인지 살핀다.
그러한 경우 그 구간을 출력하면 되고, 배열의 모든 구간에 대해 그러한 경우가 없다면 그러한 구간이 없는 것이다.

주요 알고리즘 : 그리디 알고리즘, 비트마스킹

출처 : 나코더 2021 A번
*/

int a[204800], good[204800];

int main(void) {
    int n, k, x, e;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        good[i] = ((a[i] | k) == k);
    }
    for (int i = 0; i < n; i++) {
        if (!good[i]) continue;
        x = 0, e = i;
        while (e < n && good[e]) {
            x |= a[e];
            e++;
        }
        if (x == k) {
            printf("%d %d", i + 1, e);
            return 0;
        }
        i = e - 1;
    }
    printf("-1");
    return 0;
}