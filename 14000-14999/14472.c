#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ���ڿ� '.'�� '#'�� �ִ�. �� ���ڵ� ��� ���� �Ǵ� �¿�� �����ؼ� Dĭ��
'.'�� ������ ������ ���Ѵ�.

�ذ� ��� : N�� M�� ũ�� �ʱ� ������ ��� ������ ���� ���캸�� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JOI 2017�� 3��
*/

char room[128][128];

int main(void) {
    int n, m, d, r = 0, t = 0;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%s", room[i]);
    }
    for (int i = 0; i < n - d + 1; i++) {
        for (int j = 0; j < m; j++) {
            t = 1;
            for (int k = i; k < i + d; k++) {
                if (room[k][j] == '#') t = 0;
            }
            r += t;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - d + 1; j++) {
            t = 1;
            for (int k = j; k < j + d; k++) {
                if (room[i][k] == '#') t = 0;
            }
            r += t;
        }
    }
    printf("%d", r);
    return 0;
}