#include <stdio.h>
#include <stdlib.h>

/*
���� : �� L * L(L <= 400) ũ���� ���簢�� ������ ��(<= 255)���� �־��� ��,
�� ��° ���簢���� �����ų� ȸ������ ����� ��(���̰� 100 ����)�� ������ �ִ�� �ϴ� �����
�� ������ ����Ѵ�.

�ذ� ��� : ���簢�� �������� �����ų� ȸ����Ű�� ��� ��츦 ���� ���� ����
����� ���� ���� ���� ���� ����� �� ������ ���ϰ� �׸� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : SARC 2002 G��
*/

int img[512][512], scanned[512][512], tmpimg[512][512];

int big(int a, int b) {
    return a > b ? a : b;
}

int imgcmp(int l) {
    int c = 0, x;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (abs(scanned[i][j] - img[i][j]) <= 100) c++;
        }
    }
    return c;
}

void rotimg(int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) tmpimg[i][j] = scanned[l - j - 1][i];
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) scanned[i][j] = tmpimg[i][j];
    }
}

void flipimg(int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) tmpimg[i][j] = scanned[i][l - j - 1];
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) scanned[i][j] = tmpimg[i][j];
    }
}

int main(void) {
    int l, x, r;
    while (1) {
        scanf("%d", &l);
        if (l == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%d", &img[i][j]);
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%d", &scanned[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < 8; i++) {
            r = big(r, imgcmp(l));
            if (i & 1) rotimg(l);
            flipimg(l);
        }
        printf("%.2f\n", (double)r / (l * l) * 100.0 + 1E-9);
    }
    return 0;
}