#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� ������ ���� ���� X_i(X_i <= 10^6) ��ġ�� ���� �����Ѵ�. �� ������ ũ��� g_i(g_i <= 10000)�̴�.
�̶�, Ư���� �������� ���� K(K <= 2 * 10^6) �Ÿ� �ȿ� �ִ� ������ ũ�� ���� �ִ밡 �ǵ��� �ϸ�
�׶��� ������ ũ�� ���� ���Ѵ�.

�ذ� ��� : �̸� ���� ���� ���� ��ü ������ ��ó�� ���� ����, 0���� 100�������� ��� ���� ���� ���� K �Ÿ� ����
���� ũ�� �յ��� Ȯ���ϸ� ���� ū ���� ����.

�ֿ� �˰��� : ���� ��

��ó : USACO 2014M B2��
*/

int bucket[1048576], sum[1048576];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("lazy.in", "r");
        fo = fopen("lazy.out", "w");
    }
    int n, k, g, x, r = 0, psum;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &g, &x);
        bucket[x + 1] = g;
    }
    for (int i = 1; i <= 1000001; i++) {
        sum[i] = bucket[i] + sum[i - 1];
    }
    for (int i = 0; i <= 1000001; i++) {
        psum = sum[(i + k > 1000001 ? 1000001 : i + k)] - sum[(i - k - 1 < 0 ? 0 : i - k - 1)];
        if (psum > r) r = psum;
    }
    printf("%d", r);
    return 0;
}