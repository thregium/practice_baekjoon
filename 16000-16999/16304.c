#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 자연수(<= 10^9)로 이루어진 배열에서 어떤 서로 다른 두 수도 합이 X(X <= 10^9)를 넘지 않는
가장 큰 부분집합의 크기를 구한다.

해결 방법 : 배열을 오름차순으로 정렬하고 인접한 두 수의 합을 살피면 그 두 수와 왼쪽의 수둘로 이루어진 부분집합의
가장 큰 서로 다른 두 수의 합이 된다. 따라서, 왼쪽부터 연속된 두 수의 합을 살피며 X를 넘기 전의 마지막
집합의 크기를 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : BAPC 2018 A번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, r = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] + a[i - 1] > x) break;
        r++;
    }
    printf("%d", r);
    return 0;
}