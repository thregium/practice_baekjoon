#include <stdio.h>
#include <stdlib.h>

/*
문제 :N(N <= 100000)개의 자연수(<= 10000)가 주어진다. 이때, 자연수들 가운데 하나를 뺀 수의 합으로 가능한
값의 개수와 그 값들을 오름차순으로 출력한다.

해결 방법 : 우선 각 수의 합을 구한 다음, 그 수에서 각 자연수들을 뺀 값을 배열에 저장한다.
이를 정렬한 다음, 다음 수와 다른 수의 개수를 세서 그러한 서로 다른 값의 개수를 구하고,
다시 그 수들을 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : UAPC 2022 N번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = s - a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) r++;
    }
    printf("%d\n", r);
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}