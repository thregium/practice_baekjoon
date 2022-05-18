#include <stdio.h>

/*
���� : R * C(R, C <= 100) ũ���� �迭�� C * R ũ���� �迭�� �־��� ��, ù ��° �迭��
���������� 90�� ������ �� ��° �迭�� �Ǵ� �� Ȯ���ϰ�, ����� ���� �׸��� ���� ����Ѵ�.

�ذ� ��� : ù ��° �迭�� 90�� ���� �� ����� ���Ѵ�. ����� �����ϹǷ� �Ǽ����� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : ���縯�� 1ȸD2 2��
*/

int food1[128][128], food2[128][128], food1r[128][128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void rotr(int* a, int* t, int* h, int* w, int lsz) {
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) {
            t[i * lsz + j] = a[(*h - j - 1) * lsz + i];
        }
    }
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) a[i * lsz + j] = t[i * lsz + j];
    }
    swap(h, w);
}

int main(void) {
    int r, c, res = 1;
    scanf("%d %d", &c, &r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &food1[i][j]);
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &food2[i][j]);
        }
    }
    rotr(food1, food1r, &r, &c, 128);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (food1r[i][j] != food2[i][j]) res = 0;
        }
    }
    if (res) {
        printf("|>___/|        /}\n| O < |       / }\n(==0==)------/ }\n| ^  _____    |\n|_|_/     ||__|");
    }
    else {
        printf("|>___/|     /}\n| O O |    / }\n( =0= )\"\"\"\"  \\\n| ^  ____    |\n|_|_/    ||__|");
    }
    return 0;
}