#include <stdio.h>
#include <malloc.h>

/*
���� : â�� �� �κ����� ������ ������ ���� ��ȸ�Ͽ� ���� ���ڿ��� �־��� ��,
â�� ���� ���¸� ����Ѵ�. �� â�� ũ��� �ּ����� �Ǿ�� �ϰ�, �׺��� ũ�� ���������ٸ�
������ �ּ� ũ���� ������� ������.

�ذ� ��� : �켱 ���� Ʈ���� ���� ��ȸ ������ �������� �Ͽ� Ʈ���� �����, �� â�� �ּ� ũ�⸦ ���Ѵ�.
�ٽ� �ٱ��ʺ��� ���鼭 ���� ũ�⸦ ����ϴ� ���ÿ� ������� ����� ������ �ȴ�.

�ֿ� �˰��� : ����, Ʈ��, ���

��ó : MidC 2001 C��
*/

typedef struct node {
    char type;
    int mszx, mszy;
    int rszx, rszy;
    struct node* left, *right;
} node;

char s[256], res[64][64];

int big(int a, int b) {
    return a > b ? a : b;
}

int divup(int a, int b) {
    return (a + b - 1) / b;
}

int mktree(node* nd, int p) {
    int r = 1;
    nd->type = s[p];
    if (s[p] == '|' || s[p] == '-') {
        nd->left = calloc(1, sizeof(node));
        nd->right = calloc(1, sizeof(node));
        r += mktree(nd->left, p + r);
        r += mktree(nd->right, p + r);
        if (s[p] == '|') {
            nd->mszx = big(nd->left->mszx, nd->right->mszx);
            nd->mszy = nd->left->mszy + nd->right->mszy;
        }
        else {
            nd->mszx = nd->left->mszx + nd->right->mszx;
            nd->mszy = big(nd->left->mszy, nd->right->mszy);
        }
    }
    else {
        nd->mszx = 2;
        nd->mszy = 2;
    }
    return r;
}

int mkwdw(node* nd, int ofx, int ofy) {
    for (int i = ofx; i <= ofx + nd->rszx; i++) {
        for (int j = ofy; j <= ofy + nd->rszy; j++) {
            if (res[i][j] == '*') continue;
            if ((i == ofx || i == ofx + nd->rszx) && (j == ofy || j == ofy + nd->rszy)) res[i][j] = '*';
            else if (i == ofx || i == ofx + nd->rszx) res[i][j] = '-';
            else if (j == ofy || j == ofy + nd->rszy) res[i][j] = '|';
            else res[i][j] = ' ';
        }
    }
    if (nd->type == '|') {
        nd->left->rszx = nd->rszx;
        nd->right->rszx = nd->rszx;
        nd->left->rszy = divup(nd->left->mszy * nd->rszy, nd->left->mszy + nd->right->mszy);
        nd->right->rszy = nd->rszy - nd->left->rszy;
        mkwdw(nd->left, ofx, ofy);
        mkwdw(nd->right, ofx, ofy + nd->left->rszy);
    }
    else if (nd->type == '-') {
        nd->left->rszy = nd->rszy;
        nd->right->rszy = nd->rszy;
        nd->left->rszx = divup(nd->left->mszx * nd->rszx, nd->left->mszx + nd->right->mszx);
        nd->right->rszx = nd->rszx - nd->left->rszx;
        mkwdw(nd->left, ofx, ofy);
        mkwdw(nd->right, ofx + nd->left->rszx, ofy);
    }
    else res[ofx][ofy] = nd->type;
}

int main(void) {
    int t;
    node* root;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\split\\split.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\split\\split_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        root = calloc(1, sizeof(node));
        mktree(root, 0);
        root->rszx = root->mszx;
        root->rszy = root->mszy;
        mkwdw(root, 0, 0);
        printf("%d\n", tt);
        for (int i = 0; i <= root->rszx; i++) {
            for (int j = 0; j <= root->rszy; j++) {
                printf("%c", res[i][j]);
                res[i][j] = '\0';
            }
            printf("\n");
        }
        free(root);
    }
    return 0;
}