#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 15)개의 수가 주어질 때, 두 명이 차례로 번갈아가며 수를 가져가며 자신이 가져간 수의 합을 최대로 하려 한다.
이때, 두 명이 가져가는 수의 합을 구한다.

해결 방법 : 각 수를 내림차순으로 정렬하면 홀수번째를 선공이 가져가고, 짝수번째를 후공이 가져가게 됨을 알 수 있다.
각각을 더해주면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : BAPC 2017 F번
*/

int arr[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i += 2) a += arr[i];
    for (int i = 1; i < n; i += 2) b += arr[i];
    printf("%d %d", a, b);
    return 0;
}