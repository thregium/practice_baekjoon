#include <stdio.h>
#define INF 987654321

/*
���� : ���ǿ� ��ȸ ������ �ظ� ���Ѵ�. (N <= 16)

�ذ� ��� : ��Ʈ����ŷ�� ���̳��� ���α׷����� ���� �� ������ ��������� �����ϰ� ��� ��쿡 ���� ������ ���� ���� ����� ���� ������ ����� ���� �� ����� ���� ��θ� �����Ѵ�.
��� ����� ������ ��������� ���ƿ��� �� ��� ������ �� ����� ����� ����Ѵ�.

�ֿ� �˰��� : ���̳��� ���α׷���, ��Ʈ����ŷ
*/

int w[20][20], mem[20][65536];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, res = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
            if (!w[i][j]) w[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            mem[i][j] = INF;
        }
    }
    mem[0][0] = 0;
    for (int k = 0; k < (1 << n); k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
                if ((k >> j) % 2) {
                    mem[j][k] = small(mem[j][k], mem[i][k - (1 << j)] + w[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res = small(res, mem[i][(1 << n) - 1]);
    }
    printf("%d", mem[0][(1 << n) - 1]);
    return 0;
}