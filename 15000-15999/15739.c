#include <stdio.h>

/*
���� : N * N(N <= 100) ũ���� ����� �������� ������ �����ϴ� �� ���Ѵ�. ��� ���� N^2 ������ �ڿ����̴�.

�ذ� ��� : ���� ���� �ߺ������� �ʴ��� Ȯ���ϰ� �� ��, ��, �밢���� ���� N * (N^2 + 1) / 2���� Ȯ���Ѵ�.
�� �� �ϳ��� �������� ������ �������� �ƴϴ�.

�ֿ� �˰��� : ����

��ó : �Ѿ��E 2018P 3��
*/

int chk[10240], mat[128][128];

int main(void) {
    int n, r = 1, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (chk[mat[i][j]]) r = 0;
            else chk[mat[i][j]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++) s += mat[i][j];
        if (s != n * (n * n + 1) / 2) r = 0;
        s = 0;
        for (int j = 0; j < n; j++) s += mat[j][i];
        if (s != n * (n * n + 1) / 2) r = 0;
    }
    s = 0;
    for (int i = 0; i < n; i++) s += mat[i][i];
    if (s != n * (n * n + 1) / 2) r = 0;
    s = 0;
    for (int i = 0; i < n; i++) s += mat[i][n - i - 1];
    if (s != n * (n * n + 1) / 2) r = 0;
    printf("%s", r ? "TRUE" : "FALSE");
    return 0;
}