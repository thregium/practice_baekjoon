#include <stdio.h>
#include <stdlib.h>
#define SIZE 524288

/*
���� : ���� N(N <= 500000)�� ������ �����Ʈ �Ϸ��� �� �� �ʿ��� swap ������ Ƚ���� ���Ѵ�.

�ذ� ��� : ���� ������ �� ������ �ε����� ���� ������ �� �����Ѵ�. �� ���� ���׸�Ʈ Ʈ���� 0���� N���� ��� ���� ��忡 1�� ä���.
�� �ڷδ� ���ĵ� �迭���� 0���� �� ���� �ε��� �� �������� ���� ���׸�Ʈ Ʈ������ ã�� �ᱣ���� ���� ���� �� ���� �ε����� �ִ� ����
���׸�Ʈ Ʈ������ ã�� 0���� ������Ʈ ���ִ� ���� �ݺ��ϸ� �ȴ�. �̴� ���ĵ� �迭���� �� �� �տ� �ִ� �� ��� �� ������ ū ���� ������ ã�°Ͱ� ����.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��
*/

int a[524288][2], seg[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int update(int pos, int x) {
    seg[SIZE + pos] = x;
    for (int p = (SIZE + pos) >> 1; p > 0; p >>= 1) seg[p] = seg[p << 1] + seg[(p << 1) + 1];
}

int find(int ss, int se, int p, int s, int e) {
    if (ss > e || se < s) return 0;
    if (ss >= s && se <= e) return seg[p];
    return find(ss, (ss + se) >> 1, p << 1, s, e) + find(((ss + se) >> 1) + 1, se, (p << 1) + 1, s, e);
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i;
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = SIZE; i < SIZE + n; i++) seg[i] = 1;
    for (int i = SIZE - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    for (int i = 0; i < n; i++) {
        r += find(0, SIZE - 1, 1, 0, a[i][1] - 1);
        update(a[i][1], 0);
    }
    printf("%d", r);
    return 0;
}