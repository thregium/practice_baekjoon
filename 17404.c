#include <stdio.h>
#define INF 1234567890

/*
���� : �������� �� �Ÿ��� n���� ���� �ְ�, �� ���� ������ ������, �ʷϻ�, �Ķ��� ��� �ϳ��� ĥ�ؾ� �Ѵ�. �̶� ���� �̿��� ���� ���� ������ ĥ�� �� ���ٸ�
������ ���� ���󺰷� ĥ�ϴ� ����� �־��� �� ���� ĥ�ϴ� ��� ��� ���� ��뿡 ���� ��� ����� ���Ѵ�.

�ذ� ��� : �������� ĥ�ϴ� ���� �������� �и��� �� ù ��° ���� ĥ�� ���� ���� �ٸ��� �����Ѵ�. ���� ������ ���� ������ ����� �� ù ��° ���� ������ ����
������ ���� ���� ����� ���Ѵ�� �ٲٰ�, ������ ���� ��� ��� ���� ���� ���� ����Ѵ�.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int mem[1024][3][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, r, g, b, res = INF;
    scanf("%d", &n);
    scanf("%d %d %d", &r, &g, &b);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                if (i == 0) mem[1][i][j] = r;
                if (i == 1) mem[1][i][j] = g;
                if (i == 2) mem[1][i][j] = b;
            }
            else mem[1][i][j] = INF;
        }
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d %d %d", &r, &g, &b);
        for (int j = 0; j < 3; j++) {
            mem[i][j][0] = small(mem[i - 1][j][1], mem[i - 1][j][2]) + r;
            mem[i][j][1] = small(mem[i - 1][j][0], mem[i - 1][j][2]) + g;
            mem[i][j][2] = small(mem[i - 1][j][0], mem[i - 1][j][1]) + b;
        }
    }
    //scanf("%d %d %d", &r, &g, &b);
    for (int i = 0; i < 3; i++) {
        mem[n][i][i] = INF;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) res = small(res, mem[n][i][j]);
    }

    printf("%d", res);
    return 0;
}