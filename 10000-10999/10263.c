#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 건물과 각 건물의 높이가 주어질 때, 건물을 모두 부수기 위해 장비를 몇 번 써야 하는지 구한다.
장비를 쓸 때 마다 모든 건물을 한 층 부수거나 한 건물을 부술 수 있다.

해결 방법 : 건물을 높이 순으로 정렬한 후, 매 건물까지 층으로 부쉈을 때 장비를 쓰는 횟수를 세 보면서 가장 적은 것을 고르면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : NCPC 2014 E번
*/

int h[103000];
int cnt[1048576];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main() {
    int n, x, p = 0, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (cnt[x] == 0) {
            h[p++] = x;
        }
        cnt[x]++;
    }
    qsort(h, p, sizeof(int), cmp1);

    r = n;
    x = 0;
    for (int i = 0; i < p; i++) {
        x += cnt[h[i]];
        r = small(r, h[i] + n - x);
    }
    printf("%d", r);
    return 0;
}