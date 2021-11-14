#include <stdio.h>
#include <stdlib.h>

/*
���� : R * C(R, C <= 40) ũ���� �̹������� ��� 3 * 3 ũ�� ������ �߾Ӱ��� ���Ͽ���.
�߾Ӱ��� T �̻��� ���� ������ ���Ѵ�. �̹����� �� �ȼ��� ���� 0 �̻� 255 ���Ϸ� �־�����.

�ذ� ��� : ��� 3 * 3 ������ ���� �ش��ϴ� �ȼ����� ������ ����, �����ϰ� 5��° ���� ���Ѵ�.
�� ���� ���� 5��° ���� �� �� ���Դ��� �� ����, T �̻��� ���� ���� �� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : NOIS 2003 1��
*/

int img[48][48], cnt[256], tmp[9];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r, c, t, res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &img[i][j]);
        }
    }
    for (int i = 0; i < r - 2; i++) {
        for (int j = 0; j < c - 2; j++) {
            for (int ii = 0; ii < 3; ii++) {
                for (int jj = 0; jj < 3; jj++) {
                    tmp[ii * 3 + jj] = img[i + ii][j + jj];
                }
            }
            qsort(tmp, 9, sizeof(int), cmp1);
            if (tmp[4] < 0 || tmp[4] > 255) return 1;
            cnt[tmp[4]]++;
        }
    }
    scanf("%d", &t);
    for (int i = t; i < 256; i++) {
        res += cnt[i];
    }
    printf("%d", res);
    return 0;
}