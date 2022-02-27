#include <stdio.h>
#include <malloc.h>
#define INF 1012345678

/*
문제 : 길이 N(N <= 100000)의 절댓값 10^9 이하의 정수로 이루어진 수열이 주어질 때,
M(M <= 5000)개의 쿼리에 응답한다.
1. [I, J] 구간의 수들 가운데 K번째로 작은 수를 출력한다.

해결 방법 : 우선 수열에 대해 머지 소트 트리를 만든다. 그러면 각 쿼리에 대해 매개 변수 탐색을 하며
답을 O(logN^3) 시간에 찾아낼 수 있다. 매개변수 탐색시 앞에 수가 K개 미만으로 있는 가장 작은 수를 찾는다.
이때 결정 함수는 머지 소트 트리 안에서 잡은 수보다 작은 수의 개수를 이분 탐색으로 찾아내는 방식으로
구현하면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 머지 소트 트리, 이분 탐색, 파라메트릭

출처 : NEERC 2004N K번
*/

typedef struct mseg {
    int st, ed, sz;
    int* val;
    struct mseg* lt, *rt;
} mseg;

int a[103000];

void inittree(mseg* node) {
    node->sz = node->ed - node->st + 1;
    if (node->sz == 1) {
        node->val = malloc(sizeof(int));
        node->val[0] = a[node->st];
        return;
    }

    node->lt = calloc(1, sizeof(mseg));
    node->rt = calloc(1, sizeof(mseg));
    node->lt->st = node->st;
    node->lt->ed = (node->st + node->ed) >> 1;
    node->rt->st = node->lt->ed + 1;
    node->rt->ed = node->ed;
    inittree(node->lt);
    inittree(node->rt);

    node->val = malloc(node->sz * sizeof(int));
    int p0 = 0, p1 = 0, p2 = 0, lsz = node->lt->sz, rsz = node->rt->sz;
    while (p1 < lsz || p2 < rsz) {
        if (p1 == lsz) node->val[p0++] = node->rt->val[p2++];
        else if (p2 == rsz) node->val[p0++] = node->lt->val[p1++];
        else if (node->lt->val[p1] <= node->rt->val[p2]) node->val[p0++] = node->lt->val[p1++];
        else node->val[p0++] = node->rt->val[p2++];
    }
}

int smallercount(int st, int ed, int x, mseg* node) {
    if (node->st > ed || st > node->ed) return 0;
    else if (st <= node->st && node->ed <= ed) {
        if (node->val[0] >= x) return 0;
        int lo = 0, hi = node->sz - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (node->val[mid] < x) lo = mid;
            else hi = mid - 1;
        }
        return lo + 1;
    }
    else return smallercount(st, ed, x, node->lt) + smallercount(st, ed, x, node->rt);
}

int query(int st, int ed, int z, mseg* root) {
    int lo = -INF, hi = INF, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (smallercount(st, ed, mid, root) < z) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main(void) {
    int n, m, x, y, z;
    mseg* root;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    root = calloc(1, sizeof(mseg));
    root->st = 1, root->ed = n, root->sz = n;
    inittree(root);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        printf("%d\n", query(x, y, z, root));
    }
    return 0;
}