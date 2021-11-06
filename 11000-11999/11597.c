#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 100000, N은 짝수)개의 자연수(<= 10^6)가 주어질 때, 각 자연수를 짝지어서 짝의 합이 가장 작은 짝이
가장 크도록 한다면 그 짝의 합을 구한다.

해결 방법 : 가장 큰 수와 가장 작은 수, 다음으로 큰 수와 다음으로 작은 수 ... 이런 식으로 합치는 것이 최적이다.
따라서, 이를 위해 정렬을 하고 양쪽에서부터 확인해 나가며 가장 작은 쌍을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : PacNW 2015 E/Q번 // SEUSA 2015D2 D번
*/

int s[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    qsort(s, n, sizeof(int), cmp1);
    for (int i = 0; i < (n >> 1); i++) {
        if (s[i] + s[n - i - 1] < r) r = s[i] + s[n - i - 1];
    }
    printf("%d", r);
    return 0;
}