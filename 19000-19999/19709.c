#include <stdio.h>
#include <stdlib.h>

/*
문제 : N개의 학교에 도시락을 보내려고 한다. 각 학교에는 K_i개의 도시락을 보내거나 아예 보내지 않아야 한다면
M개의 도시락으로 보낼 수 있는 학교 개수의 최댓값을 구한다.

해결 방법 : K_i의 오름차순으로 정렬한 후 그 순서대로 최대한 보내는 것을 시도한다.
그때 보낸 학교 개수가 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : NOIS 2016 1번
*/

int k[1030000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &m, &n);
    if (m < 0 || m > 1000000000 || n > 100000) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    qsort(k, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (m >= k[i]) {
            m -= k[i];
            r++;
        }
        else break;
    }
    printf("%d", r);
    return 0;
}