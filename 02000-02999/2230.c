#include <stdio.h>
#include <stdlib.h>
#define INF 0x7A35090F

/*
���� : ũ�� N(N <= 100000)�� �迭(����, || <= 10^9)�� �־��� ��, �� �迭���� ���̰� M(M <= 2 * 10^9) �̻��̸鼭
���� ���� �� ���� ���̸� ���Ѵ�.

�ذ� ��� : �迭�� ������ ����, ���ʺ��� �������� ������ �̵���Ų��. �� ���� ���̰� M �̸��� ��� ������ �̵���Ű��,
�̻��� ��� �ᱣ���� �����ϰ� �������� �ű��. �̴� ������ �迭�� ��� �� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, s = 0, e = 0, r = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    while (e < n) {
        while (e < n && a[e] - a[s] < m) e++;
        if (e == n) break;
        if (a[e] - a[s] <= r) r = a[e] - a[s];
        s++;
    }
    printf("%d", r);
    return 0;
}