#include <stdio.h>
#include <stdlib.h>

/*
���� : 5���� ������ �������� �ְ�, ������ ���鳢���� �Ÿ� 4���� �־��� ��, ��� ���� ������ �Ÿ��� ���Ѵ�.

�ذ� ��� : ����, ù ��° ���� ������ �� ������ �Ÿ��� ���� ���� �̿��� ���Ѵ�.
�׷��� ������ ������ �Ÿ��� �� ������ �Ÿ��� ù ��° ������ �Ÿ��� �̿��� ���� �� �ִ�.

�ֿ� �˰��� : ����, ���� ��

��ó : CCC 2018 J3��
*/

int dists[4], res[5][5];

int main(void) {
    scanf("%d %d %d %d", &dists[0], &dists[1], &dists[2], &dists[3]);
    for (int i = 1; i < 5; i++) {
        res[0][i] = res[0][i - 1] + dists[i - 1];
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res[i][j] = abs(res[0][i] - res[0][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}