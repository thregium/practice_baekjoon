#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 64)장의 카드에 쓰인 값(0 <=, <= 10000, 정수)들이 주어질 때, 처음 C(0 <= C < N)장의
카드는 넘긴 다음 그 값보다 큰 카드가 나오면 멈춘다고 한다. (나오지 않으면 멈추지 않는다.).
이때, 마지막 카드에 쓰인 수의 기댓값을 구한다.

해결 방법 : C장을 뽑아서 나온 가장 큰 카드의 값에 따라 나올 수 있는 경우의 수와 기댓값을 구하고,
이를 전부 더한 다음 다시 전체 경우의 수로 나누면 된다. 가장 큰 수가 뽑히지 않은 경우 기댓값은
더 큰 수의 평균이고 경우의 수는 (번째수 - 1)_C_(c-1)이다.
가장 큰 카드를 뽑았다면 경우의 수는 위와 같고, 기댓값은 가장 큰 수를 제외한 모든 수의 평균이다.
전체 경우의 수는 N_C_c이다.
단, C가 0인 경우에는 전체 평균이 답이 되므로 예외 처리를 하는 것이 좋다.

주요 알고리즘 : 수학, 확률론, 조합론

출처 : VTH 2017 B번
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c;
    double tot = 1, sum = 0, cmb, tsum;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (c == 0) {
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        printf("%.9f", sum / n);
        return 0;
    }
    for (int i = n; i > n - c; i--) tot *= i;
    for (int i = 1; i <= c; i++) tot /= i;
    qsort(a, n, sizeof(int), cmp1);
    for (int i = c; i < n; i++) {
        cmb = 1;
        for (int j = i - 1; j > i - c; j--) cmb *= j;
        for (int j = 1; j < c; j++) cmb /= j;
        tsum = 0;
        for (int j = i; j < n; j++) tsum += a[j];
        tsum /= n - i;
        sum += tsum * cmb;
    }
    cmb = 1;
    for (int i = n - 1; i > n - c; i--) cmb *= i;
    for (int i = 1; i < c; i++) cmb /= i;
    tsum = 0;
    for (int i = 0; i < n - 1; i++) tsum += a[i];
    tsum /= n - 1;
    sum += tsum * cmb;
    printf("%.9f", sum / tot);
    return 0;
}