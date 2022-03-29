#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 정수(|| <= 100000)가 주어질 때, 어떠한 두 정수 쌍의 차이도
L(L <= 100000) 이상이 되도록 하기 위해 제거해야 하는 정수의 개수를 구한다.

해결 방법 : 수들을 정렬한 후 1번째 수부터 차이를 L씩 두며 남길 수 있는 정수의 최대 개수를 구한다.
이를 N에서 빼면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Tehran 2020 J번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, r = 1, last;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= l) {
            r++;
            last = a[i];
        }
    }
    printf("%d", n - r);
    return 0;
}