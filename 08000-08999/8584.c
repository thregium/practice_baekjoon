#include <stdio.h>

/*
���� : N(N <= 10^6)���� ���ϰ� �ִ� �ձ��� �ִ�. �Ѹ� ���Ϸ� �� ������ ��� ��ȣ�� �־��� ��,
ó���� �� �ִ� ����� �ִ� ���� ���Ѵ�. �� ���ϴ� ���� ��� �ִ� 1���� ó���� �� �ִ�.

�ذ� ��� : Ʈ���� �Ʒ� �������� ���ʷ� ó���� ����� �̴´�. ��Ƴ��� ����� ���� ���� ��� ���
��Ƴ��� ���� Ȯ������ �ʴ� ���� ������ ����̴�. ��Ƴ��� ����� ���� ��� ó������ �ʴ´�.
�̸� �ݺ��Ͽ� ó���� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, Ʈ��, ���Ͽ� ���ε�

��ó : JPOI 2011 1-3��
*/

int p[1048576], uf_g[1048576], saved[1048576];

int uf_find(int x) {
    if (uf_g[x] < 0) return x;
    else return uf_g[x] = uf_find(uf_g[x]);
}

void uf_uni(int x, int y) {
    if (uf_find(x) == uf_find(y)) return;
    uf_g[uf_find(y)] = uf_find(x);
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        uf_g[i] = -1;
    }
    uf_g[1] = -1;
    uf_g[0] = -1;
    for (int i = n; i > 1; i--) {
        if (saved[i]) continue;
        if (uf_find(p[i]) >= 1) {
            saved[uf_find(p[i])] = 1;
            uf_uni(p[uf_find(p[i])], uf_find(p[i]));
            r++;
        }
    }
    printf("%d", r);
    return 0;
}