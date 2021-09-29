#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 16)���� ������ �������� �ְ�, ó���� ���°� �־�����. B(B <= 10^15)���� ������ ������ �� ������
� �������� ���Ѵ�. �� ���۸��� ������ ���¿��� ������ ������ ���� ���¿��ٸ� ���� ���¿� �ݴ� ���·� ������ �ٲ۴�.
���� ���¿��ٸ� ���� ���� �״�� ����.

�ذ� ��� : ������ ���·� ������ �������� ���ƾ� 65536(= 2^16)���� ���̴�. ����, �� �������� ������ ���� �� ����
���� ���̹Ƿ� �������� ���¸� ���� ǥ���ϴ� ���� �����ϴ�. �̸� �̿��� �������� ���°� �ݺ��Ǵ� ������ ã��
�� ���� �ݺ� �ֱ�� �ݺ��ϴ� ������ ���ϰ�, �׸� ���� �� �������� ���¸� ����س��� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ����ŷ

��ó : USACO 2013O B2��
*/

int mem[81920][16], last[65536];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("blink.in", "r");
        fo = fopen("blink.out", "w");
    }
    int n, x, sz, t = 0, f;
    long long b;
    scanf("%d %lld", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        mem[0][i] = x;
        t += (x << i);
    }
    for (int i = 0; i < (1 << n); i++) last[i] = -1;
    last[t] = 0;
    for (sz = 1;; sz++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (mem[sz - 1][(j + n - 1) % n]) mem[sz][j] = !mem[sz - 1][j];
            else mem[sz][j] = mem[sz - 1][j];
            t += (mem[sz][j] << j);
        }
        if (last[t] >= 0) break;
        last[t] = sz;
    }
    f = sz - last[t];

    if (b < last[t]) {
        for (int i = 0; i < n; i++) {
            printf("%d\n", mem[b][i]);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            printf("%d\n", mem[(b - last[t]) % f + last[t]][i]);
        }
    }
    return 0;
}