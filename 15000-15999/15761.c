#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명이 줄을 서려 한다. 각 사람은 앞의 사람이 w_i(w_i <= 10^9)명 이하인 경우 줄을 선다.
사람들이 오는 순서를 조정할 수 있다면 줄을 최대한 적게 설 때 줄을 서는 사람 수를 구한다.

해결 방법 : w_i 값이 높은 사람부터 오는 것이 최적이다. 따라서, 내림차순으로 정렬한 다음, w_i가 i보다 커지는 경우
그때의 i값을 출력하면 된다. 그러한 경우가 없다면 N을 출력한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2018O S2번
*/

int w[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    qsort(w, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (w[i] < i) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", n);
    return 0;
}