#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 상자의 크기와 막대의 크기가 있을 때, 각 상자에 막대를 1개씩만 넣으며 모든 막대를 넣을 수 있는지 구한다.

해결 방법 : 각 상자와 막대의 크기를 정렬하고, 순서대로 대응시킨다. 만약 막대의 크기가 더 큰 경우가 나온다면
넣을 수 없는 막대가 나오는 것이고, 따라서, 모든 막대를 넣을 수 없다. 그 외에는 모든 막대를 넣을 수 있다.

주요 알고리즘 : 구현, 정렬

출처 : COCI 17/18#5 1번
*/

int x[128], y[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    qsort(y, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            printf("NE");
            return 0;
        }
    }
    printf("DA");
    return 0;
}