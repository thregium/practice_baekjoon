#include <stdio.h>
#include <malloc.h>

/*
���� : N(N <= 100000)���� ����ġ�� ���� ���·� �ִ�. M(M <= 100000)���� ������ �����Ѵ�.
0. [S, E]�� �ִ� ����ġ�� ���¸� ������Ų��.
1. [S, E]�� �ִ� ���� ������ ����ġ ������ ���Ѵ�.

�ذ� ��� : ������ ���׸�Ʈ Ʈ���� �̿��� Ǯ �� �ִ�. �� ������ ���� �ش� ���� ������ ���� ����ġ ��,
���Ű��� ����ġ�� �������� ���η� �д�. ���� ������ ������ �ش� ������ ���Ű��� 1�� XOR�� ���� ������ �����Ѵ�.
���޽ÿ��� �ڽ� ���� ���Ű��� XOR���� ��, ���Ű��� 1�̾��� ��� ������ ũ�� - ������ ������ ���� �ٲپ� �ָ� �ȴ�.
���� ���� ������ �Ϲ����� ������ ���׸�Ʈ Ʈ���� ����ϰ� �ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ������ ���׸�Ʈ Ʈ��

��ó : USACO 2008N G3��
*/

typedef struct lazyseg {
    int st;
    int ed;
    int val;
    int prop;
    struct lazyseg* left;
    struct lazyseg* right;
} lazyseg;

int initseg(lazyseg* node) {
    if (node->st == node->ed) return;
    node->left = calloc(1, sizeof(lazyseg));
    node->right = calloc(1, sizeof(lazyseg));
    node->left->st = node->st;
    node->left->ed = (node->st + node->ed) >> 1;
    node->right->st = ((node->st + node->ed) >> 1) + 1;
    node->right->ed = node->ed;
    initseg(node->left);
    initseg(node->right);
}

void prop(lazyseg* node) {
    if (node->left) node->left->prop ^= node->prop;
    if (node->right) node->right->prop ^= node->prop;
    if (node->prop) node->val = (node->ed - node->st + 1) - node->val;
    node->prop = 0;
}

void invert(lazyseg* node, int s, int e) {
    prop(node);
    if (node->ed < s || node->st > e) return;
    if (s <= node->st && node->ed <= e) {
        node->prop ^= 1;
        prop(node);
        return;
    }
    invert(node->left, s, e);
    invert(node->right, s, e);
    node->val = node->left->val + node->right->val;
}

int counton(lazyseg* node, int s, int e) {
    prop(node);
    if (node->ed < s || node->st > e) return 0;
    if (s <= node->st && node->ed <= e) {
        return node->val;
    }
    return counton(node->left, s, e) + counton(node->right, s, e);
}

int main(void) {
    int n, m, o, s, t;
    scanf("%d %d", &n, &m);
    lazyseg* root = calloc(1, sizeof(lazyseg));
    root->st = 1, root->ed = n;
    initseg(root);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &s, &t);
        if (o == 0) {
            invert(root, s, t);
        }
        else {
            printf("%d\n", counton(root, s, t));
        }
    }
    return 0;
}