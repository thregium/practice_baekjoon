#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 N(N <= 200000)의 1 ~ N까지의 자연수가 차례로 주어진 배열이 주어질 때, 배열의 특정 값을 맨 앞으로 옮기는
연산을 M(M <= 100000)회 한다면 나오는 배열을 출력한다.

해결 방법 : 먼저 원래의 배열을 만든 다음, M회동안 나오는 값들에 대해 가장 마지막에 나온 순서를 저장해 둔다.
그 다음, 가장 마지막에 나온 순서(내림차순, 나오지 않았다면 0) -> 원래의 수(오름차순)를 기준으로 정렬하면 그 배열이 답이 된다.

주요 알고리즘 : 정렬

출처 : Tsukuba 2016 A번 // Petro 2017W8 A번
*/

int a[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    if (aj != bj) return aj < bj ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, e;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) a[i][0] = i + 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &e);
        a[e - 1][1] = i + 1;
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i][0]);
    }
    return 0;
}