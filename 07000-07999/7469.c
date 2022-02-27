#include <stdio.h>
#include <malloc.h>
#define INF 1012345678

/*
���� : ���� N(N <= 100000)�� ���� 10^9 ������ ������ �̷���� ������ �־��� ��,
M(M <= 5000)���� ������ �����Ѵ�.
1. [I, J] ������ ���� ��� K��°�� ���� ���� ����Ѵ�.

�ذ� ��� : �켱 ������ ���� ���� ��Ʈ Ʈ���� �����. �׷��� �� ������ ���� �Ű� ���� Ž���� �ϸ�
���� O(logN^3) �ð��� ã�Ƴ� �� �ִ�. �Ű����� Ž���� �տ� ���� K�� �̸����� �ִ� ���� ���� ���� ã�´�.
�̶� ���� �Լ��� ���� ��Ʈ Ʈ�� �ȿ��� ���� ������ ���� ���� ������ �̺� Ž������ ã�Ƴ��� �������
�����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, ���� ��Ʈ Ʈ��, �̺� Ž��, �Ķ��Ʈ��

��ó : NEERC 2004N K��
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