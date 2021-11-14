#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 음이 아닌 서로 다른 정수(<= 10^9)로 이루어진 배열이 있을 때, 배열에서 연속한 5개의 정수가
나오도록 하기 위해 추가해야 하는 원소의 최소 개수를 구한다.

해결 방법 : 배열을 정렬한 다음, 모든 수마다 해당 수보다 5보다 적은 차이의 더 작은 수의 개수 + 1을 각각 구한다.
이 값이 가장 큰 것을 구하고, 그 값을 5에서 빼면 답이 된다.

주요 알고리즘 : 정렬, 투 포인터
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 5, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (p = i; p >= 0 && a[i] - a[p] < 5; p--);
        if (5 - (i - p) < r) r = 5 - (i - p);
    }
    printf("%d", r);
    return 0;
}