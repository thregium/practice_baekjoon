#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� '-'�� '|'�� �̷���� �迭�� �־��� ��, �� �迭���� ������ '-'�� '|'�� ���� �ϳ��� ģ�ٸ�
������ ������ ���Ѵ�.

�ذ� ��� : ���� �� ĭ���� Ȯ���ϸ� '-'�� ��� ���������� ������ '-'�� ��� �湮 ó���� �Ѵ�.
���������� '|'�� ��� �Ʒ��� ������ '|'�� ��� �湮 ó���� �Ѵ�. �湮 ó���� �� ĭ�� �Ѿ���� �ϸ�
�湮�� Ƚ���� ������ ������ ����.

�ֿ� �˰��� : �׸��� �˰���
*/

char fl[64][64], vis[64][64];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", fl[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            r++;
            if (fl[i][j] == '-') {
                for (int k = j; k < m && fl[i][k] == '-'; k++) {
                    if (vis[i][k]) return 1;
                    vis[i][k] = 1;
                }
            }
            else if (fl[i][j] == '|') {
                for (int k = i; k < n && fl[k][j] == '|'; k++) {
                    if (vis[k][j]) return 1;
                    vis[k][j] = 1;
                }
            }
            else return 1;
        }
    }
    printf("%d", r);
    return 0;
}