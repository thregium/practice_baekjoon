#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(5 <= N <= 66) 명의 푼 문제 수와 페널티가 주어질 때, 6위 이하의 인원 가운데 5위와 푼 문제 수가 같은 사람 수를 구한다.

해결 방법 : 순위 순으로 정렬한 후, 6위 이하에서 5위와 푼 문제 수가 같은 사람 수를 구하면 된다.

주요 알고리즘 : 정렬

출처 : shake! 2018 A번
*/

int part[128][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &part[i][0], &part[i][1]);
    }
    qsort(part, n, sizeof(int) * 2, cmp1);
    for (int i = 5; i < n; i++) {
        if (part[i][0] == part[4][0]) r++;
    }
    printf("%d", r);
    return 0;
}