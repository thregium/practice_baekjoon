#include <stdio.h>
#include <stdlib.h>

/*
문제 : L / 2^M(M <= 10)(L <= 2^M) 꼴의 분수가 N(N <= 20000)개 주어질 때, 분수들을 크기 순으로 정렬한다.
단, 같은 크기의 분수들은 L에 대한 오름차순으로 정렬한다.

해결 방법 : 각 분수들을 L / 2^10로 통분한 후 정렬해주면 된다. 만약 통분한 값이 같다면 L 순서로 정렬한다.

주요 알고리즘 : 수학, 정렬

출처 : PA 2001 2-1번
*/

int weights[20480][2];

int cmp1(const void* a, const void* b) {
    int al = *(int*)a;
    int bl = *(int*)b;
    int am = *((int*)a + 1);
    int bm = *((int*)b + 1);
    if ((al << (10 - am)) != (bl << (10 - bm))) return (al << (10 - am)) > (bl << (10 - bm)) ? 1 : -1;
    else return al > bl ? 1 : al == bl ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i][0], &weights[i][1]);
    }
    qsort(weights, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", weights[i][0], weights[i][1]);
    }
    return 0;
}