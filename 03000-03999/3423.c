#include <stdio.h>

/*
���� : N * N(N <= 1000) ũ���� �迭�� ���ڵ��� ����ΰ� ������ �� ���� �ð�������� �������� ���ڵ��� �о���.
�̶�, ���� ���ڵ��� ������� ����Ѵ�.

�ذ� ��� : ���� 4���� �������� �������� ������ �ִ� ĭ���� �����صд�. �� ���⸶�� �б� ������ ������ ã�ư���
������ �ִ� ĭ������ ���ڵ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : CERC 2011 H��
*/

char hole[4][1024][1024], ciph[1024][1024];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", hole[0][i]);
        }
        for (int i = 1; i <= 3; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    hole[i][j][k] = hole[i - 1][n - k - 1][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", ciph[i]);
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (hole[i][j][k] == 'O') printf("%c", ciph[j][k]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}