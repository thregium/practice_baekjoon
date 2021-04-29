#include <stdio.h>
#include <malloc.h>

/*
���� : N���� ������ �̷���� �迭�� ���� ��, �迭�� X�� �߰��ϰų� S���� E������ ���� ��� �迭�� ���Ե��� �ʴ� ���� ������ ���� ������ �����Ѵ�.
��, N <= 10^6, -10^9 <= Ni <= 10^9�̴�.

�ذ� ��� : ���̳��� ���׸�Ʈ Ʈ���� �̿��� �ذ� �����ϴ�. ������ -10^9 ~ 10^9�� ��带 ������ ����(�� ��忡�� �迭�� �ִ� ���� ������ �����ص�),
���� ������Ʈ�ϴ� ������ ������ �ش� ������ ���ؼ��� ��带 �Ҵ��Ѵ�. ���� ã�� ������ ���´ٸ� �Ϲ����� ���׸�Ʈ Ʈ���� ����ϰ� �ذ� ����������
NULL �����͸� ����Ű�� �ִ� ��� 0�� ��ȯ�Ѵٴ� ���� �ٸ���.
������, �� ���������� �̰͸����δ� �޸� ������ �ذ��ϱ⿣ �����ϴ�. ����, ���� �߰��� ��尡 � �� �������� ����Ѵٸ�,
���� ������ �������� ��� �� ���� ��ġ�� �����ϴ� ������� �ذ��� �� �ִ�. ���� ������Ʈ �������� ������ 0�� ��尡 ���´ٸ� �ش� ��忡
������Ʈ�� ��ġ�� �����صΰ� ������Ʈ�� �����ϴ� ����̴�. 1�� ��尡 ���´ٸ� �ش� ����� ������Ʈ�� �������� �ش� ��ġ�� ���� ���� ������Ʈ�Ѵ�.
�������� Ȯ���� ������ ������ 1�� ��忡�� Ž���� ������ ��ġ�� ���ԵǸ� 1��, ���Ե��� ������ 0�� ��ȯ�ϸ� �ȴ�.
���� �������� ������ ũ�⿡�� ���ָ� ������ ���� ���´�.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��, ���̳��� ���׸�Ʈ Ʈ��

��ó : ���ϴ� 2018 H��
*/

typedef struct stree {
    int n;
    int s;
    int e;
    int p;
    struct stree* l;
    struct stree* r;
} stree;

long long cnt = 0;
stree* root;

void update(stree* t, int p, int x) {
    if (t->s == t->e) {
        t->n = x;
        return;
    }
    if (t->n == 0) {
        t->n = x;
        t->p = p;
        return;
    }
    if (t->n == 1) {
        if (t->p <= ((t->s + t->e) >> 1)) {
            t->l = calloc(1, sizeof(stree));
            t->l->s = t->s;
            t->l->e = ((t->s + t->e) >> 1);
            update(t->l, t->p, x);
        }
        else {
            t->r = calloc(1, sizeof(stree));
            t->r->s = (((t->s + t->e) >> 1) + 1);
            t->r->e = t->e;
            update(t->r, t->p, x);
        }
    }
    if (p <= ((t->s + t->e) >> 1)) {
        if (t->l == NULL) {
            t->l = calloc(1, sizeof(stree));
            t->l->s = t->s;
            t->l->e = ((t->s + t->e) >> 1);
            cnt++;
        }
        update(t->l, p, x);
    }
    else {
        if (t->r == NULL) {
            t->r = calloc(1, sizeof(stree));
            t->r->s = (((t->s + t->e) >> 1) + 1);
            t->r->e = t->e;
            cnt++;
        }
        update(t->r, p, x);
    }
    t->n = (t->l ? t->l->n : 0) + (t->r ? t->r->n : 0);
}

int find(stree* t, int s, int e) {
    if (s > t->e || e < t->s) return 0;
    if (s <= t->s && e >= t->e) return t->n;
    if (t->n == 1 && t->p >= s && t->p <= e) return 1;
    else if (t->n == 1) return 0;

    return (t->l ? find(t->l, s, e) : 0) + (t->r ? find(t->r, s, e) : 0);
}

int main(void) {
    int n, q, m, x, y;
    scanf("%d", &n);
    root = calloc(1, sizeof(stree));
    root->s = -1000000000;
    root->e = 1000000000;
    for (int i = 0; i < n; i++) {
        scanf("%d", &q);
        //q = -1000000000 + i * 2000;
        update(root, q, 1);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &q);
        //q = 1;
        if (q == 1) {
            scanf("%d", &x);
            //x = -1000000000 + i * 2000 + 1000;
            update(root, x, 1);
        }
        else {
            scanf("%d %d", &x, &y);
            printf("%d\n", (y - x + 1) - find(root, x, y));
        }
    }
    return 0;
}