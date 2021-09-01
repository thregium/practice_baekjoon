#include <stdio.h>

/*
���� : N(N <= 100) ũ���� ������ ������� ���� ����Ѵ�.

�ذ� ��� : �������� �߽ɿ��� �����ؼ� �ð�������� ������ �̵��ذ��� ���� ������ �ȴ�.
������ ������ N = 1, ��� ���Ŀ� �����Ѵ�.

�ֿ� �˰��� : ����
*/

char res[512][512];

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    if (n == 1) {
        printf("*");
        return 0;
    }
    x = n * 2, y = n * 2 - 2;
    for (int i = 0; i < n * 4 - 1; i++) {
        for (int j = 0; j < n * 4 - 3; j++) res[i][j] = ' ';
    }
    res[1][1] = '\0', res[x][y] = '*';
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i * 4 - 2; j++) res[--x][y] = '*';
        for (int j = 1; j <= i * 4 - 2; j++) res[x][++y] = '*';
        for (int j = 1; j <= i * 4; j++) res[++x][y] = '*';
        for (int j = 1; j <= i * 4; j++) res[x][--y] = '*';
    }
    for (int i = 1; i <= n * 4 - 2; i++) res[--x][y] = '*';
    for (int i = 1; i <= n * 4 - 4; i++) res[x][++y] = '*';
    for (int i = 0; i < n * 4 - 1; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}