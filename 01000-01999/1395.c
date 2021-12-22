#include <stdio.h>
#include <malloc.h>

/*
문제 : N(N <= 100000)개의 스위치가 꺼진 상태로 있다. M(M <= 100000)개의 쿼리에 응답한다.
0. [S, E]에 있는 스위치의 상태를 반전시킨다.
1. [S, E]에 있는 켜진 상태의 스위치 개수를 구한다.

해결 방법 : 레이지 세그먼트 트리를 이용해 풀 수 있다. 각 정점의 값은 해당 장점 이하의 켜진 스위치 수,
갱신값은 스위치를 반전할지 여부로 둔다. 값을 갱신할 때에는 해당 구간의 갱신값에 1을 XOR한 다음 갱신을 전달한다.
전달시에는 자식 노드로 갱신값을 XOR해준 뒤, 갱신값이 1이었던 경우 구간의 크기 - 정점의 값으로 값을 바꾸어 주면 된다.
값을 구할 때에는 일반적인 레이지 세그먼트 트리와 비슷하게 하면 된다.

주요 알고리즘 : 자료 구조, 레이지 세그먼트 트리

출처 : USACO 2008N G3번
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