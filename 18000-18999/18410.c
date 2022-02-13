#include <stdio.h>
#include <stdlib.h>

/*
문제 : 단조 증가하는 2000 이하의 자연수로 이루어진 길이 N(N <= 500)의 배열 A와
같은 조건의 길이 M(M <= 500)인 배열 B가 주어질 때, 두 배열을 문제에 주어진 알고리즘대로 합친 결과를 구한다.

해결 방법 : 주어진 알고리즘은 두 배열을 단조성을 유지하며 합치는 과정과 같고,
따라서, 두 배열을 합친 다음 정렬한 결과와 같게 된다. 그러므로 두 배열을 합치고 정렬해도 답을 낼 수 있다.

주요 알고리즘 : 구현, 정렬

출처 : JOI 2020예1 1-3번
*/

int c[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n + m, sizeof(int), cmp1);
    for (int i = 0; i < n + m; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}