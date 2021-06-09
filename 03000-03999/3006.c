#include <stdio.h>
#include <stdlib.h>
#define SZ 131072

/*
문제 : 1부터 N(N <= 100000)까지의 수로 이루어진 순열을 칵테일 소트한다.
이때, 각 과정마다 몇회 swap 연산이 일어나는지 구한다.

해결 방법 : 먼저 수들을 정렬한 후 정렬한 각 수의 번호들을 순서대로 찾는다.
그리고 일단 처음 상태에서는 모든 수가 남아있는 상태이므로 세그먼트 트리에 모든 수에 대해 1을 저장해준다.
그 다음으로는 가장 작은 수와 가장 큰 수들을 순서대로 찾아가며 그 앞의 수 또는 그 뒤의 수들 중 남아있는 수의 개수를 구한다.
개수를 구한 다음에는 그 수를 출력하고, 현재 확인한 수를 세그먼트 트리에서 0으로 바꾸면 된다.
주요 알고리즘 : 자료구조, 세그먼트 트리

출처 : COCI 07/08#2 4번
*/

int a[103000], idx[103000], seg[SZ * 2];

int cmp1(const void* x, const void* y) {
    int ai = a[*(int*)x];
    int bi = a[*(int*)y];
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void update(int p, int x) {
    seg[SZ + p] = x;
    for (int i = ((SZ + p) >> 1); i >= 1; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int find(int fs, int fe, int ss, int se, int d) {
    if (ss > fe || se < fs) return 0;
    else if (ss >= fs && se <= fe) return seg[d];
    return find(fs, fe, ss, (ss + se) >> 1, d << 1) + find(fs, fe, ((ss + se) >> 1) + 1, se, (d << 1) + 1);
}

int main(void) {
    int n, p = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        idx[i] = a[i];
    }
    qsort(idx + 1, n, sizeof(int), cmp1);

    for (int i = 1; i <= n; i++) seg[SZ + i] = 1;
    for (int j = SZ - 1; j > 0; j--) {
        seg[j] = seg[j << 1] + seg[(j << 1) + 1];
    }
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            p = idx[n - (i >> 1)];
            printf("%d\n", find(p + 1, n, 0, SZ - 1, 1));
        }
        else {
            p = idx[1 + (i >> 1)];
            printf("%d\n", find(1, p - 1, 0, SZ - 1, 1));
        }
        update(p, 0);
    }
    return 0;
}