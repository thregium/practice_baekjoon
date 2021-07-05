#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 수로 이루어진 집합을 K(K <= 1000)개의 구간으로 나눌 때, 가장 구간의 길이의 합이 작을 때의 구간 길이 합을 구한다.
단, 구간의 길이는 0이 될 수 있다.

해결 방법 : 수의 집합을 두 구간으로 나눈다면 수들을 정렬했을 때 기준으로 인접한 두 수 사이 거리 중 하나를 제외시키는 것이 가능해진다.
이 중 가장 먼 것을 제외시키는 것이 가장 좋은 것을 알 수 있고, 유사하게 이를 반복하면 K - 1개의 가장 먼 구간들을 제외시키는 것이
가장 좋다. 따라서, 수를 정렬한 다음 각 수 사이의 거리를 찾아 다시 정렬한 후 가장 큰 K - 1개를 제외한 거리의 합을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Seoul 2005I E번
*/

int a[10240], b[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
        r += b[i];
    }
    qsort(b, n - 1, sizeof(int), cmp2);
    for (int i = 0; i < k - 1; i++) {
        r -= b[i];
    }
    printf("%d", r);
    return 0;
}