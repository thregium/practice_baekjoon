#include <stdio.h>
#include <stdlib.h>

/*
���� : M(M <= 1000)���� Ű���� Ÿ���ο� ���� �ð��� Ű���� ��ȣ, �Է��� ���ڰ� �־��� ��, ��µ� ���ڿ��� ���Ѵ�.
���ڿ��� �ð� -> ��ȣ ������� ǥ�õȴ�.

�ذ� ��� : �Է��� ����ü�� �ְ� �ð� -> ��ȣ ������� ������ ���� �� ������� ���ڵ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���ϴ� 2019 K��
*/

typedef struct key {
    int n;
    int t;
    char c;
} key;

key tp[1024];

int cmp1(const void* a, const void* b) {
    key ak = *(key*)a;
    key bk = *(key*)b;
    if (ak.t != bk.t) return ak.t > bk.t ? 1 : -1;
    return ak.n > bk.n ? 1 : ak.n == bk.n ? 0 : -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &tp[i].n, &tp[i].t, &tp[i].c);
    }
    qsort(tp, m, sizeof(key), cmp1);
    for (int i = 0; i < m; i++) {
        printf("%c", tp[i].c);
    }
    return 0;
}