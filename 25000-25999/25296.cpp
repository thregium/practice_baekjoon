#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define SZ 131072
#define INF 1012345678
using namespace std;

/*
문제 : 

해결 방법 : 레이지 세그먼트 트리를 이용해 조건을 만족하는 구간의 개수가 C개인 지점의 수를 매번 찾아나가면 된다.
업데이트시에는 구간에 1 또는 -1을 더하고 개수는 필요한 구간에서 최댓값이 C인 개수를 구하면 된다.
트리의 각 정점에는 최댓값과 그 개수를 저장한다.
Ai가 0인 경우에 유의한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 레이지

출처 : GCJ 2022_3 B번
*/

typedef struct lzseg {
    int st, ed;
    int hi, cnt;
    int prp;
    struct lzseg* lt, * rt;
} lzseg;

int ab[103000][2], p[103000 * 2], cnt[103000];
vector<int> hat[103000];

int big(int a, int b) {
    return a > b ? a : b;
}

int badchange(int col, int cnt, int chg) {
    int pv, at;
    if (cnt == 0 || (ab[col][0] <= cnt && cnt <= ab[col][1])) pv = 0;
    else pv = 1;
    if (cnt + chg == 0 || (ab[col][0] <= cnt + chg && cnt + chg <= ab[col][1])) at = 0;
    else at = 1;
    return at - pv;
}

void nodeupd(lzseg* node) {
    if (node->lt->hi == node->rt->hi) {
        node->hi = node->lt->hi;
        node->cnt = node->lt->cnt + node->rt->cnt;
    }
    else if (node->lt->hi > node->rt->hi) {
        node->hi = node->lt->hi;
        node->cnt = node->lt->cnt;
    }
    else {
        node->hi = node->rt->hi;
        node->cnt = node->rt->cnt;
    }
}

void lazy_inittree(lzseg* node, int x) {
    node->hi = x;
    node->cnt = 1;
    if (node->st == node->ed) return;

    node->lt = (lzseg*)calloc(1, sizeof(lzseg));
    node->rt = (lzseg*)calloc(1, sizeof(lzseg));
    node->lt->st = node->st;
    node->lt->ed = ((node->st + node->ed) >> 1);
    node->rt->st = ((node->st + node->ed) >> 1) + 1;
    node->rt->ed = node->ed;
    lazy_inittree(node->lt, x);
    lazy_inittree(node->rt, x);
    nodeupd(node);
}

void prop(lzseg* node) {
    if (node->prp) {
        if (node->st != node->ed) {
            node->lt->prp += node->prp;
            node->rt->prp += node->prp;
        }
        node->hi += node->prp;
        node->prp = 0;
    }
}

void lazy_upd(lzseg* node, int ust, int ued, int uval) {
    prop(node);
    if (node->ed < ust || node->st > ued) return;
    if (ust <= node->st && node->ed <= ued) {
        node->prp += uval;
        prop(node);
    }
    else {
        lazy_upd(node->lt, ust, ued, uval);
        lazy_upd(node->rt, ust, ued, uval);
        nodeupd(node);
    }
}

int lazy_find(lzseg* node, int fst, int fed, int n) {
    prop(node);
    if (node->ed < fst || node->st > fed) return 0;
    if (fst <= node->st && node->ed <= fed) {
        if (node->hi == n) return node->cnt;
        else return 0;
    }
    else return lazy_find(node->lt, fst, fed, n) + lazy_find(node->rt, fst, fed, n);
}

void freetree(lzseg* node) {
    if (node->lt) freetree(node->lt);
    if (node->rt) freetree(node->rt);
    free(node);
}

int segpoint(int hn, int modi, int n) {
    int stt = cnt[hn];
    if (hat[hn].size() <= stt + modi) return INF;
    else return hat[hn][stt + modi];
}

int main(void) {
    //freopen("E:\\PS\\Contest\\Google Code Jam\\2022\\duckduckgeese_test_data\\test_set_1\\ts1_input.txt", "r", stdin);
    int t, n, c, good;
    long long res;
    lzseg* root;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &c);
        for (int i = 1; i <= c; i++) {
            scanf("%d %d", &ab[i][0], &ab[i][1]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            hat[p[i]].push_back(i);
        }
        for (int i = n; i < n * 2; i++) {
            p[i] = p[i - n];
            hat[p[i]].push_back(i);
        }

        root = (lzseg*)calloc(1, sizeof(lzseg));
        if (root == NULL) return 1;
        root->st = 0, root->ed = n * 2 - 1;
        lazy_inittree(root, 0);
        res = 0;

        good = c;
        for (int i = 0; i < n * 2; i++) {
            cnt[p[i]]++;
            good -= badchange(p[i], cnt[p[i]] - 1, 1);
            lazy_upd(root, i, i, good);
        }
        for (int i = 1; i <= c; i++) cnt[i] = 0;
        res += lazy_find(root, 1, n - 2, c);
        for (int i = 1; i < n; i++) {
            if (ab[p[i - 1]][0] > 0) {
                lazy_upd(root, i, hat[p[i - 1]][cnt[p[i - 1]] + 1] - 1, 1);
                lazy_upd(root, 0, i - 1, -1);
            }
            lazy_upd(root, segpoint(p[i - 1], ab[p[i - 1]][0] - 1, n),
                segpoint(p[i - 1], ab[p[i - 1]][0], n) - 1, -1);
            lazy_upd(root, segpoint(p[i - 1], ab[p[i - 1]][1], n),
                segpoint(p[i - 1], ab[p[i - 1]][1] + 1, n) - 1, 1);
            res += lazy_find(root, i + 1, i + n - 2, c);
            cnt[p[i - 1]]++;
            if (root->hi > c) {

                return 1;
            }
        }

        printf("Case #%d: %lld\n", tt, res);

        freetree(root);
        for (int i = 1; i <= c; i++) hat[i].clear();
        for (int i = 1; i <= c; i++) cnt[i] = 0;
    }
    return 0;
}