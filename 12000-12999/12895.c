#include <stdio.h>
#include <malloc.h>

/*
���� : N(N <= 100000)���� ���� �Ϸķ� �ִ�. T(T <= 30)���� �������� ���� ���� ĥ�� �� �ִٰ� �� ��,
Q(Q <= 100000)���� ������ �����Ѵ�.
C. X�� Y��° �� ���̸� Z��° ������ ĥ�Ѵ�.
Q. X��°���� Y��° �� ���� ĥ���� ���� �������� ���Ѵ�.
ó������ ��� ���� 1�� ������ ĥ���� �ִ�.

�ذ� ��� : ������ ���׸�Ʈ Ʈ���� �̿��Ѵ�. T�� �����Ƿ� �� ������ ���� ������ �ִ� ���� �����
��Ʈ����ŷ�� ���� �������ش�. �� ������ ���� ���� ������ ���� OR ���� �ȴ�.
�����ϴ� ���� �״�� �������� �ְ�, ���Ľÿ��� ���� ������ ���� �����ϴ� ������ �״�� �ٲٸ� �ȴ�.
(X > Y)�� ��찡 �����Ƿ� �����Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, ������
*/

typedef struct lzseg {
    int st, ed;
    int val;
    int prp;
    struct lzseg* lt, * rt;
} lzseg;

void lazy_inittree(lzseg* node, int x) {
    node->val = x;
    if (node->st == node->ed) return;

    node->lt = (lzseg*)calloc(1, sizeof(lzseg));
    node->rt = (lzseg*)calloc(1, sizeof(lzseg));
    node->lt->st = node->st;
    node->lt->ed = ((node->st + node->ed) >> 1);
    node->rt->st = ((node->st + node->ed) >> 1) + 1;
    node->rt->ed = node->ed;
    lazy_inittree(node->lt, x);
    lazy_inittree(node->rt, x);
}

void prop(lzseg* node) {
    if (node->prp == 0) return;
    if (node->st == node->ed) {
        node->val = node->prp;
        node->prp = 0;
        return;
    }
    node->lt->prp = node->prp;
    node->rt->prp = node->prp;
    node->val = node->prp;
    node->prp = 0;
}

void lazy_upd(lzseg* node, int ust, int ued, int uval) {
    prop(node);
    if (node->ed < ust || node->st > ued) return;
    if (ust <= node->st && node->ed <= ued) {
        node->prp = uval;
        prop(node);
    }
    else {
        lazy_upd(node->lt, ust, ued, uval);
        lazy_upd(node->rt, ust, ued, uval);
        node->val = (node->lt->val | node->rt->val);
    }
}

int lazy_find(lzseg* node, int fst, int fed) {
    prop(node);
    if (node->ed < fst || node->st > fed) return 0;
    if (fst <= node->st && node->ed <= fed) return node->val;
    else return lazy_find(node->lt, fst, fed) | lazy_find(node->rt, fst, fed);
}

int main(void) {
    int n, t, q, x, y, z, res;
    char o;
    lzseg* root = (lzseg*)calloc(1, sizeof(lzseg));
    scanf("%d %d %d", &n, &t, &q);
    root->st = 1, root->ed = n;
    lazy_inittree(root, 1);
    for (int i = 0; i < q; i++) {
        scanf(" %c %d %d", &o, &x, &y);
        if (x > y) {
            z = x;
            x = y;
            y = z;
        }
        if (o == 'C') {
            scanf("%d", &z);
            z--;
            lazy_upd(root, x, y, (1 << z));
        }
        else if (o == 'Q') {
            z = lazy_find(root, x, y);
            res = 0;
            for (int i = 0; i < t; i++) {
                if ((z >> i) & 1) res++;
            }
            printf("%d\n", res);
        }
        else return 1;
    }
    return 0;
}