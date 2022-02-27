#include <stdio.h>
#include <stdlib.h>
#define SZ 131072

/*
문제 : N(N <= 75000)개 섬의 좌표가 주어진다. 이때, X좌표가 커지거나 같아지는 쪽으로,
Y좌표는 작아지거나 같아지는 쪽으로 이동하는 섬의 쌍 개수를 구한다. 좌표 범위는 절댓값 10^9 이하의 정수이다.

해결 방법 : 우선 좌표 범위의 상대적인 크기만 봐야 하므로 좌표 압축을 한다.
그리고 다시 X좌표(오름차순) -> Y좌표(내림차순)를 기준으로 정렬한 다음, 각 섬마다 Y좌표가 해당 값 이상인
섬의 개수를 결괏값에 더해나간다. 다시 해당 섬의 Y좌표를 세그먼트 트리에 추가하고 이를 반복하면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 스위핑, 좌표 압축

출처 : BAPC 2005 E번
*/

int island[81920][4], seg[SZ * 2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 0);
    int bi = *((int*)b + 0);
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

void compressxy(int n) {
    for (int i = 0; i < n; i++) {
        island[i][2] = island[i][0];
    }
    qsort(island, n, sizeof(int) * 4, cmp1);
    island[0][3] = 1;
    for (int i = 1; i < n; i++) {
        if (island[i][2] == island[i - 1][2]) island[i][3] = island[i - 1][3];
        else island[i][3] = island[i - 1][3] + 1;
    }
    for (int i = 0; i < n; i++) island[i][0] = island[i][3];

    for (int i = 0; i < n; i++) {
        island[i][2] = island[i][1];
    }
    qsort(island, n, sizeof(int) * 4, cmp1);
    island[0][3] = 1;
    for (int i = 1; i < n; i++) {
        if (island[i][2] == island[i - 1][2]) island[i][3] = island[i - 1][3];
        else island[i][3] = island[i - 1][3] + 1;
    }
    for (int i = 0; i < n; i++) island[i][1] = island[i][3];
}

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd(int a, int b) {
    seg[a + SZ] += b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int t, n;
    long long r;
    //freopen("E:\\PS\\ICPC\\Europe\\BAPC\\2005\\E\\tests\\01.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\BAPC\\2005\\E\\tests\\01_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &island[i][0], &island[i][1]);
        }
        compressxy(n);
        qsort(island, n, sizeof(int) * 4, cmp2);
        r = 0;
        for (int i = 0; i < SZ * 2; i++) seg[i] = 0;
        for (int i = 0; i < n; i++) {
            r += getsum(island[i][1], SZ - 1, 0, SZ - 1, 1);
            upd(island[i][1], 1);
        }
        printf("%lld\n", r);
    }
    return 0;
}