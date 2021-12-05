#include <stdio.h>
#include <malloc.h>

/*
���� : N * M(N, M <= 100000, N * M <= 200000) ũ���� �׸��� �� ���� �� ���� ���̿� ������ ���̰� �־��� ��,
��� ������ ���¸� ����Ѵ�.

�ذ� ��� : ���� �Ҵ��� ���� N * M ũ���� �迭�� ������ ����, �켱 ���� �׸���.
�� �� ���ο� �ͳ��� �׸��� ������ �׸� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Coder's 2016R2 B��
*/

char* res[103000];

int main(void) {
    int n, m, x, h;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < n; i++) {
        res[i] = malloc(sizeof(char) * (m + 1));
        for (int j = 0; j < m; j++) res[i][j] = '.';
        res[i][m] = '\0';
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &h);
        for (int j = n - h; j < n; j++) {
            res[j][i] = '#';
        }
    }
    for (int i = 0; i < m; i++) {
        if (res[n - x][i] == '#') res[n - x][i] = '*';
        else res[n - x][i] = '-';
        if (i % 3 == 2) {
            for (int j = n - x + 1; j < n; j++) {
                if (res[j][i] == '#') break;
                else res[j][i] = '|';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}