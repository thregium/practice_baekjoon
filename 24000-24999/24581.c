#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
문제 : a ~ f 사이의 소문자로 이루어진 200000자 이하의 문자열이 주어진다.
Q(Q <= 200000)개의 쿼리에 응답한다.
1. [A, B] 사이의 부분 문자열에서 모든 문자의 개수가 짝수인 부분 문자열의 개수를 구한다.
2. A번째 문자를 x로 바꾼다.

해결 방법 : 앞에서부터 각 문자의 누적 합을 생각해보면 모든 문자 누적합의 홀짝성이 같은 지점끼리는
모든 문자의 개수가 짝수 개인 구간의 시작점과 끝점이 될 수 있음을 알 수 있다.
또한, 특정 지점의 문자를 바꾸면 그 이후의 모든 문자에 대해 누적 합 개수는 그 문자의 번호를 기준으로
서로 바뀌게 된다.

이를 이용하면 레이지 세그먼트 트리를 이용해 문제를 풀 수 있다. 우선 각 문자의 누적 합에 대한
홀짝성을 나누어 64개의 값으로 둔 다음, 앞에서부터의 누적 합을 구해서 그 값의 구간 합들을 정점에 저장한다.
문자를 바꾸는 쿼리가 들어오는 경우 현재 문자와 새 문자의 XOR 값을 갱신값으로 하여
현재 문자와 그 이후 문자에 대해 갱신한다.
조건에 맞는 부분 문자열의 개수를 찾는 쿼리에서는 64가지 경우 각각에 대한 개수를 세 나간다.
여기서 각 경우마다 개수에서 2개의 지점을 뽑는 경우의 수를 더하면 쿼리의 결과가 된다.
각 갱신에서는 각 값과 그에 갱신값을 XOR한 값들을 서로 교환하도록 한다. 자식 정점으로의 전파에서는
XOR을 사용한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 레이지, 비트마스킹, 누적 합

출처 : MidAtl 2021 E번 // NCNA 2021 A번
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