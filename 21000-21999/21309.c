#include <stdio.h>

/*
���� : R * C(R, C <= 1000) ũ���� ������ �־��� ��, �� �������� ���� ���η� �´��� ���� �밢������ �´��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �� �������� ���� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : GNY 2020 J��
*/

int land[1024][1024];

int main(void) {
    int r, c, ca = 0, ic = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &land[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (land[i][j] && land[i][j - 1]) {
                //����
                ca++;
                ic++;
            }
        }
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (land[i][j] && land[i - 1][j]) {
                //����
                ca++;
                ic++;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (land[i][j] && land[i + 1][j + 1]) ic++; //�밢(\)
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (land[i][j] && land[i + 1][j - 1]) ic++; //�밢(/)
        }
    }

    printf("%d %d", ca, ic);
    return 0;
}