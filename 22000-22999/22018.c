#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 100000)���� �׸����� �Ϸķ� �����ְ�, �� �׸��� ��ġ�� Xi(Xi <= 10^9)�̴�. �� �׸����� ������ ��ġ�� �ִµ�,
�� �׸��� ��ġ�� Vi(Vi <= 10^9)�̴�. �̶�, �׸����� M���� ���ܵθ鼭 �� �׸����� �ּ� D���� ���������� �ϰ� �ʹ�.
�̶��� �׸����� �ּ� ��ġ�� �ִ�� �� ��, �ּ� ��ġ�� ���Ѵ�.

�ذ� ��� : �׸����� ��ġ ������ �����ϰ�, �׸��� ��ġ�鵵 �����صд�. �� ����, ��ġ�� X��°�� �׸� �̻��� �׸��鸸 ����Ͽ�
��� �׸����� ��ġ�� �� �ִ��� ���θ� ���� �Ű� ���� Ž���� �����Ѵ�.
�ش� ���δ� ��ġ ������ �׸��� ���� �� ���� ���� ��ġ�ؼ� M���� ���� �� �ִ����� ���� Ȯ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, �̺� Ž��

��ó : JOIG 2021 4��
*/

int pics[103000][2], vals[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getres(int n, int m, int d, int x) {
    int p = 0, l = -INF;
    for (int i = 0; i < n; i++) {
        if (pics[i][1] < vals[x]) continue;
        if (pics[i][0] - l >= d) {
            l = pics[i][0];
            p++;
        }
    }
    return (p >= m);
}

int main(void) {
    int n, m, d, l, h;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pics[i][0], &pics[i][1]);
        vals[i] = pics[i][1];
    }
    qsort(pics, n, sizeof(int) * 2, cmp1);
    qsort(vals, n, sizeof(int), cmp1);
    l = -1, h = n - 1;
    while (l < h) {
        if (getres(n, m, d, (l + h + 1) >> 1)) l = ((l + h + 1) >> 1);
        else h = ((l + h + 1) >> 1) - 1;
    }
    if (l < 0) printf("-1");
    else printf("%d", vals[l]);
    return 0;
}