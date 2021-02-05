#include <stdio.h>
#include <malloc.h>

long long s[1048576];

typedef struct stree {
    long long s;
    long long p;
    long long m;
    int st;
    int sz;
    struct stree* l;
    struct stree* r;
} stree;

void maketree(stree* root) {
    if (root->sz == 1) {
        root->s = s[root->st - 1];
        return;
    }

    stree* l, * r;
    l = calloc(1, sizeof(stree));
    r = calloc(1, sizeof(stree));
    l->st = root->st;
    l->sz = root->sz / 2;
    r->st = root->st + root->sz / 2;
    r->sz = root->sz / 2 + root->sz % 2;
    l->m = 1;
    r->m = 1;
    root->l = l;
    root->r = r;

    maketree(l);
    maketree(r);
    root->s = (root->l ? root->l->s : 0) + (root->r ? root->r->s : 0);
}

void update(stree* root) {
    if (root->p != 0) {
        if (root->l) root->l->p += root->p;
        if (root->r) root->r->p += root->p;
        root->s += root->p * root->sz;
        root->p = 0;
    }
}

void replace(stree* root, int x, int y, long long z) {
    if (y < root->st || x > root->st + root->sz - 1) {
        return;
    }
    else if (x <= root->st && y >= root->st + root->sz - 1) {
        root->s += z * root->sz;
        if (root->l) root->l->p += z;
        if (root->r) root->r->p += z;
        return;
    }
    else {
        replace(root->l, x, y, z);
        replace(root->r, x, y, z);
        root->s = (root->l ? root->l->s : 0) + (root->r ? root->r->s : 0);
    }
}

long long getsum(stree* root, int x, int y) {
    if (y < root->st || x > root->st + root->sz - 1) {
        return 0;
    }
    else if (x <= root->st && y >= root->st + root->sz - 1) {
        return root->s;
    }

    else return getsum(root->l, x, y) + getsum(root->r, x, y);
}

int main(void) {
    int n, m, k;
    long long a, b, c, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }
    stree* root;
    root = calloc(1, sizeof(stree));
    root->st = 1;
    root->sz = n;
    maketree(root);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            scanf("%lld", &d);
            replace(root, b, c, d);
        }
        else if (a == 2) {
            scanf("%lld", &d);
            
        }
        else if (a == 3) {
            scanf("%lld", &d);
        }
        else if (a == 4) {
            printf("%lld\n", getsum(root, b, c));
        }
    }

    return 0;
}