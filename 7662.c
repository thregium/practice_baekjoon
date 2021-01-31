#include <stdio.h>
#include <malloc.h>

typedef struct avl {
    int n;
    //int c;
    struct avl* l;
    struct avl* r;
} avl;

int big(int a, int b) {
    return a > b ? a : b;
}

int avl_height(avl* node) {
    if (node) {
        return 1 + big(avl_height(node->l), avl_height(node->r));
    }
    return 0;
}

int avl_bf(avl* node) {
    if (node == NULL) return 0;
    return avl_height(node->l) - avl_height(node->r);
}

avl* avl_rotate_l(avl* root) {
    avl* c = root->r;
    root->r = c->l;
    c->l = root;
    return c;
}

avl* avl_rotate_r(avl* root) {
    avl* c = root->l;
    root->l = c->r;
    c->r = root;
    return c;
}

avl* avl_rebalance_i(avl* root, int n) {
    int b = avl_bf(root);
    if (b > 1) {
        if (avl_bf(root->l) < 0) {
            root->l = avl_rotate_l(root->l);
        }
        return avl_rotate_r(root);
    }
    else if (b < -1) {
        if (avl_bf(root->r) > 0) {
            root->r = avl_rotate_r(root->r);
        }
        return avl_rotate_l(root);
    }

    return root;
}

avl* avl_insert(avl* root, int n) {
    if (root == NULL) {
        avl* new = calloc(1, sizeof(avl));
        new->n = n;
        //new->c = 1;
        return new;
    }

    if (n < root->n) {
        root->l = avl_insert(root->l, n);
    }
    else if (n > root->n) {
        root->r = avl_insert(root->r, n);
    }
    else {
        //root->c++;
        return root;
    }

    return avl_rebalance_i(root, n);
}

int main(void) {
    int t, k, n;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        avl* root = NULL;
        for (int i = 0; i < k; i++) {
            //scanf("\n%c %d", &c, &n);
            c = 'I';
            n = i;
            if (c == 'I') {
                root = avl_insert(root, n);
            }
        }
        //printf("%d", n);
        continue;
    }
    return 0;
}