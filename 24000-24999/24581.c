#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
���� : a ~ f ������ �ҹ��ڷ� �̷���� 200000�� ������ ���ڿ��� �־�����.
Q(Q <= 200000)���� ������ �����Ѵ�.
1. [A, B] ������ �κ� ���ڿ����� ��� ������ ������ ¦���� �κ� ���ڿ��� ������ ���Ѵ�.
2. A��° ���ڸ� x�� �ٲ۴�.

�ذ� ��� : �տ������� �� ������ ���� ���� �����غ��� ��� ���� �������� Ȧ¦���� ���� ����������
��� ������ ������ ¦�� ���� ������ �������� ������ �� �� ������ �� �� �ִ�.
����, Ư�� ������ ���ڸ� �ٲٸ� �� ������ ��� ���ڿ� ���� ���� �� ������ �� ������ ��ȣ�� ��������
���� �ٲ�� �ȴ�.

�̸� �̿��ϸ� ������ ���׸�Ʈ Ʈ���� �̿��� ������ Ǯ �� �ִ�. �켱 �� ������ ���� �տ� ����
Ȧ¦���� ������ 64���� ������ �� ����, �տ��������� ���� ���� ���ؼ� �� ���� ���� �յ��� ������ �����Ѵ�.
���ڸ� �ٲٴ� ������ ������ ��� ���� ���ڿ� �� ������ XOR ���� ���Ű����� �Ͽ�
���� ���ڿ� �� ���� ���ڿ� ���� �����Ѵ�.
���ǿ� �´� �κ� ���ڿ��� ������ ã�� ���������� 64���� ��� ������ ���� ������ �� ������.
���⼭ �� ��츶�� �������� 2���� ������ �̴� ����� ���� ���ϸ� ������ ����� �ȴ�.
�� ���ſ����� �� ���� �׿� ���Ű��� XOR�� ������ ���� ��ȯ�ϵ��� �Ѵ�. �ڽ� ���������� ���Ŀ�����
XOR�� ����Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, ������, ��Ʈ����ŷ, ���� ��

��ó : MidAtl 2021 E�� // NCNA 2021 A��
*/

typedef struct lseg {
    int st, ed;
    int num[64];
    int prop;
    struct lseg* lt;
    struct lseg* rt;
} lseg;

char s[204800];
int lsum[204800];

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void maketree(lseg* node) {
    if (node->st == node->ed) {
        node->num[lsum[node->st]] = 1;
        return;
    }
    node->lt = calloc(1, sizeof(lseg));
    node->lt->st = node->st;
    node->lt->ed = ((node->st + node->ed) >> 1);
    maketree(node->lt);
    node->rt = calloc(1, sizeof(lseg));
    node->rt->st = ((node->st + node->ed) >> 1) + 1;
    node->rt->ed = node->ed;
    maketree(node->rt);
    for (int i = 0; i < 64; i++) {
        node->num[i] = node->lt->num[i] + node->rt->num[i];
    }
}

void prop(lseg* node) {
    if (node->prop == 0) return;
    unsigned long long swapped = 0;
    for (int i = 0; i < 64; i++) {
        if ((swapped >> i) & 1) continue;
        swap(&(node->num[i]), &(node->num[i ^ (node->prop)]));
        swapped |= (1LL << i);
        swapped |= (1LL << (i ^ (node->prop)));
    }
    if (node->st != node->ed) {
        node->lt->prop ^= node->prop;
        node->rt->prop ^= node->prop;
    }
    node->prop = 0;
}

void upd(lseg* node, int s, int e, int a) {
    prop(node);
    if (node->ed < s || node->st > e) return;
    if (s <= node->st && node->ed <= e) {
        node->prop ^= a;
        prop(node);
        return;
    }
    else {
        upd(node->lt, s, e, a);
        upd(node->rt, s, e, a);
    }
    for (int i = 0; i < 64; i++) {
        node->num[i] = node->lt->num[i] + node->rt->num[i];
    }
}

int find(lseg* node, int s, int e, int a) {
    prop(node);
    if (node->ed < s || node->st > e) return 0;
    if (s <= node->st && node->ed <= e) return node->num[a];
    else return find(node->lt, s, e, a) + find(node->rt, s, e, a);
}

long long query(lseg* root, int s, int e) {
    long long r = 0, x;
    for (int i = 0; i < 64; i++) {
        x = find(root, s - 1, e, i);
        r += ((((long long)x - 1LL) * x) >> 1LL);
    }
    return r;
}

int main(void) {
    int n, q, o, a, b;
    char c;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        lsum[i] = (lsum[i - 1] ^ (1 << (s[i] - 'a')));
    }
    lseg* root = calloc(1, sizeof(lseg));
    root->st = 0, root->ed = n;
    maketree(root);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(root, a, b));
        }
        else if (o == 2) {
            scanf("%d %c", &a, &c);
            b = ((1 << (s[a] - 'a')) ^ (1 << (c - 'a')));
            upd(root, a, n, b);
            s[a] = c;
        }
        else return 1;
    }
    return 0;
}