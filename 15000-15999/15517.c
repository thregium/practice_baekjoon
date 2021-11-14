#include <stdio.h>
#include <stdlib.h>
#define SIZE 1048576

/*
���� : N(N <= 10^6)���� ������ �̷���� �迭�� �־��� ��, �� �迭�� �� ������ �տ� �ִ� �� ���
�� ���� ���� ������ ����Ѵ�.

�ذ� ��� : ���� �迭�� ��ǥ ���� �� ����, ���׸�Ʈ Ʈ���� 0���� �ʱ�ȭ�Ѵ�.
���ķ� ������ ������ ������� 0���� ���� ������ ���� �� ������ ������ ���ؼ� ����ϰ�
���׸�Ʈ Ʈ���� ���� ���� ������ 1 ���ؼ� �ִ� ������ �Ѵ�.
�̸� �ݺ��ϸ� ���� ���� �� �ִ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, ��ǥ ����

��ó : Startlink #1 E2��
*/

int a[1048576][3], seg[SIZE * 2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}
int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
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
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i;
    }
    qsort(a, n, sizeof(int) * 3, cmp1);
    a[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i][0] == a[i - 1][0]) a[i][2] = a[i - 1][2];
        else a[i][2] = a[i - 1][2] + 1;
    }
    qsort(a, n, sizeof(int) * 3, cmp2);
    for (int i = SIZE; i < SIZE + n; i++) seg[i] = 0;
    for (int i = SIZE - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    for (int i = 0; i < n; i++) {
        printf("%lld\n", find(0, SIZE - 1, 1, 0, a[i][2] - 1));
        update(a[i][2], 1);
    }
    return 0;
}