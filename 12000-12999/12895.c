#include <stdio.h>
#include <malloc.h>

/*
문제 : N(N <= 100000)개의 집이 일렬로 있다. T(T <= 30)가지 색상으로 집의 색을 칠할 수 있다고 할 때,
Q(Q <= 100000)개의 쿼리에 응답한다.
C. X와 Y번째 집 사이를 Z번째 색으로 칠한다.
Q. X번째에서 Y번째 집 사이 칠해진 색의 가짓수를 구한다.
처음에는 모든 집이 1번 색으로 칠해져 있다.

해결 방법 : 레이지 세그먼트 트리를 이용한다. T가 작으므로 각 정점에 하위 정점에 있는 집의 목록을
비트마스킹을 통해 저장해준다. 각 정점의 값은 하위 정점의 값의 OR 값이 된다.
전파하는 값은 그대로 내려보내 주고, 전파시에는 현재 정점의 값을 전파하는 값으로 그대로 바꾸면 된다.
(X > Y)인 경우가 있으므로 주의한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 레이지
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