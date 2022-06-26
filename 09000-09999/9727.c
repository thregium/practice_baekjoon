#include <stdio.h>

/*
���� : 6 * 6 ũ���� ������ ����� �Ǿ��� �� ���Ѵ�.

�ذ� ��� : �� �������� 1���� 6 ���� ���� 1������ ���� �� Ȯ���ϸ� �ȴ�.
�ٸ� ���� ������ ���� �̸� ó���Ѵ�. �밢���� Ȯ���ϴ� ���� ���� �ʴ´�.

�ֿ� �˰��� : ����

��ó : Khwarizmi 2010 E��
*/

int sdk[6][6], chk[6];

int valid(void) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (sdk[i][j] < 1 || sdk[i][j] > 6) return 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) chk[j] = 0;
        for (int j = 0; j < 6; j++) chk[sdk[i][j] - 1]++;
        for (int j = 0; j < 6; j++) {
            if (chk[j] != 1) return 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) chk[j] = 0;
        for (int j = 0; j < 6; j++) chk[sdk[j][i] - 1]++;
        for (int j = 0; j < 6; j++) {
            if (chk[j] != 1) return 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) chk[j] = 0;
        for (int j = 0; j < 6; j++) chk[sdk[i / 2 * 2 + j / 3][i % 2 * 3 + j % 3] - 1]++;
        for (int j = 0; j < 6; j++) {
            if (chk[j] != 1) return 0;
        }
    }
    for (int j = 0; j < 6; j++) chk[j] = 0;
    for (int j = 0; j < 6; j++) chk[sdk[j][j] - 1]++;
    for (int j = 0; j < 6; j++) {
        if (chk[j] != 1) return 0;
    }
    for (int j = 0; j < 6; j++) chk[j] = 0;
    for (int j = 0; j < 6; j++) chk[sdk[j][5 - j] - 1]++;
    for (int j = 0; j < 6; j++) {
        if (chk[j] != 1) return 0;
    }

    return 1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &sdk[i][j]);
            }
        }
        printf("Case#%d: %d\n", tt, valid());
    }
    return 0;
}