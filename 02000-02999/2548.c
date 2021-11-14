#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)개의 자연수가 주어질 때, 주어진 모든 자연수에서의 차이의 합이 가장 작은 수 가운데 가장 작은 수를 구한다.

해결 방법 : 중앙값(짝수개인 경우 두 중앙값 사이의 수)일 때 가장 차이의 합이 작다. 이는 정렬을 통해 매우 쉽게 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 정올 2009 초1번
*/

int a[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    printf("%d", a[(n - 1) >> 1]);
    return 0;
}