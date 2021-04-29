#include <stdio.h>
#include <malloc.h>

/*
문제 : N개의 정수로 이루어진 배열이 있을 때, 배열에 X를 추가하거나 S부터 E까지의 정수 가운데 배열에 포함되지 않는 수의 개수를 묻는 쿼리에 응답한다.
단, N <= 10^6, -10^9 <= Ni <= 10^9이다.

해결 방법 : 다이나믹 세그먼트 트리를 이용해 해결 가능하다. 구간이 -10^9 ~ 10^9인 노드를 만들어둔 다음(각 노드에는 배열에 있는 수의 개수를 저장해둠),
수를 업데이트하는 쿼리가 들어오면 해당 구간에 대해서만 노드를 할당한다. 수를 찾는 쿼리가 들어온다면 일반적인 세그먼트 트리와 비슷하게 해결 가능하지만
NULL 포인터를 가리키고 있는 경우 0을 반환한다는 점이 다르다.
하지만, 이 문제에서는 이것만으로는 메모리 문제를 해결하기엔 부족하다. 따라서, 새로 추가된 노드가 어떤 한 수에서만 사용한다면,
리프 노드까지 내려가는 대신 그 수의 위치를 저장하는 방식으로 해결할 수 있다. 만약 업데이트 과정에서 개수가 0인 노드가 나온다면 해당 노드에
업데이트할 위치를 저장해두고 업데이트를 종료하는 방식이다. 1인 노드가 나온다면 해당 노드의 업데이트할 방향으로 해당 위치를 보낸 다음 업데이트한다.
누적합을 확인할 때에는 개수가 1인 노드에서 탐색할 구간에 위치가 포함되면 1을, 포함되지 않으면 0을 반환하면 된다.
얻은 누적합을 구간의 크기에서 빼주면 쿼리의 답이 나온다.

주요 알고리즘 : 자료구조, 세그먼트 트리, 다이나믹 세그먼트 트리

출처 : 전북대 2018 H번
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