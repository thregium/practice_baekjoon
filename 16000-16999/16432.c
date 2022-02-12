#include <stdio.h>

/*
���� : ���� N(N <= 1000)�� �������� �� ��ġ���� ������ �ڿ���(<= 9)�� ����� �־��� ��,
������ ��ġ�� ���� ���� ���� �ʵ��� �ϴ� ������ ���� �� �ִ� �� ���ϰ�, ������ ��� �׷��� ������ ����Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �� ��ġ�� ������ ������ ������ �� ���θ� ����Ѵ�.
������ ��ġ���� ������ ��� ������ ���� �� ������, ������ ��ġ���� ��������
������ ������ ����� ������ �ȴ�.

�ֿ� �˰��� : DP, ������

��ó : ��ϴ� 2018 ȣ���̹�
*/

int d[1024][16], mem[1024][16], res[1024];

int main(void) {
    int n, m, x, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            d[i][x] = 1;
        }
    }
    for (int i = 1; i <= 9; i++) mem[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (!d[i][j]) continue;
            for (int k = 1; k <= 9; k++) {
                if (j == k) continue;
                mem[i][j] |= mem[i - 1][k];
            }
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (mem[n][i]) r = i;
    }
    if (!r) {
        printf("-1");
        return 0;
    }
    res[n] = r;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= 9; j++) {
            if (r != j && mem[i][j]) {
                r = j;
                break;
            }
        }
        res[i] = r;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}