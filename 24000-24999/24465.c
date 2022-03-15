#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)명의 사람의 생일이 주어질 때, 그 전에 주어진 7명의 별자리와 모두
겹치지 않는 별자리의 생일인 사람이 있는 지 구하고, 있다면 그 사람들의 생일을 오름차순으로 출력한다.
겹치는 생일도 모두 출력한다.

해결 방법 : 우선 7명의 별자리들을 저장하고, 그 후로는 그 별자리와 겹치지 않는 사람의 수를 세는 동시에
그 사람들의 생일을 저장한다. 그러한 사람이 하나라도 있다면 생일을 정렬한 후 모두 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : 한양대 8회B E번
*/

int zod[12] = { 120, 219, 321, 420, 521, 622, 723, 823, 923, 1023, 1123, 1222 };
int occu[12], res[10240][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getzod(int x) {
    for (int i = 0; i < 12; i++) {
        if (x < zod[i]) return i;
    }
    return 0;
}

int main(void) {
    int n, x, y, r = 0;
    for (int i = 0; i < 7; i++) {
        scanf("%d %d", &x, &y);
        occu[getzod(x * 100 + y)]++;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (occu[getzod(x * 100 + y)] == 0) {
            res[r][0] = x;
            res[r++][1] = y;
        }
    }
    qsort(res, r, sizeof(int) * 2, cmp1);
    if (r == 0) printf("ALL FAILED");
    else {
        for (int i = 0; i < r; i++) {
            printf("%d %d\n", res[i][0], res[i][1]);
        }
    }
    return 0;
}