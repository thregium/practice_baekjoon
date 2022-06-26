#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 마트료시카 인형이 있다. 각 마트료시카 안에 더 작은 마트료시카를 1개까지만
넣을 수 있다면, 주어진 크기(<= 10^9)의 마트료시카들을 최대한 압축하면
나오는 마트료시카의 개수를 구한다.

해결 방법 : 가장 많이 중복되는 크기의 마트료시카의 중복 수와 같다.
이는 정렬을 통해 간단히 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : SLPC 2010_1 D번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, cnt, best;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        cnt = 1, best = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                if (cnt > best) best = cnt;
                cnt = 1;
            }
            else cnt++;
        }
        if (cnt > best) best = cnt;
        printf("%d\n", best);
    }
    return 0;
}