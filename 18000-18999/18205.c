#include <stdio.h>
#include <stdlib.h>

/*
���� : �Ϸķ� ���� N(N <= 10000)�� ���� pH ��(0 <= pH <= 14)�� �Ҽ��� �Ʒ� 6�ڸ����� �־�����.
�̶�, M(M <= 10000)���� ������ �����Ѵ�.
[L, R] ������ ������ pH ���� ���� ���� ������ �� ���Ѵ�.
(���ѽð� 2��)

�ذ� ��� : �� ���� pH���� �ٸ� �� ���θ� �߿��ϹǷ� ������ ���� ���� ������ ������ N �̳��� ���δ�.
�׸��� N, M�� ���� ���ѽð��� ũ�Ƿ� �� ������ ������ ������ ���� ������ �� ������ �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, �� ����

��ó : MidC 2019 H��
*/

int ph[10240][3], cnt[10240];

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

int main(void) {
    int n, m, x, y, l, r, h;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d.%d", &x, &y);
        ph[i][0] = x * 1000000 + y;
        ph[i][1] = i;
    }
    qsort(ph, n, sizeof(int) * 3, cmp1);
    ph[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (ph[i][0] == ph[i - 1][0]) ph[i][2] = ph[i - 1][2];
        else ph[i][2] = ph[i - 1][2] + 1;
    }
    qsort(ph, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l, &r);
        h = 0;
        for (int j = l - 1; j < r; j++) {
            cnt[ph[j][2]]++;
            if (cnt[ph[j][2]] > h) h = cnt[ph[j][2]];
        }
        for (int j = 1; j <= n; j++) cnt[j] = 0;
        if (h * 2 > r - l + 1) printf("usable\n");
        else printf("unusable\n");
    }
    return 0;
}