#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���� 50 ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ���� 1 �̻��� �� �κ����� ������
�� �κ��� ������ ���� ���� ���ڿ� ��� ���������� ���� ���� ���ڿ��� ���Ѵ�.

�ذ� ��� : ���̰� 50�̹Ƿ� �� �κ����� ������ ����� 50^2 ������ ������ ���̴�.
���� ��� ��츦 ���� �غ� ���� ������ ���� ���� ���������� ���� ���ڿ��� ã���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ���ڿ�, ����

��ó : COCI 07/08#4 3��
*/

char orig[64], made[4096][64];

int main(void) {
    int l, sz = 0, p;
    scanf("%s", orig);
    l = strlen(orig);
    for (int i = 0; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            p = 0;
            for (int k = i; k >= 0; k--) made[sz][p++] = orig[k];
            for (int k = j; k > i; k--) made[sz][p++] = orig[k];
            for (int k = l - 1; k > j; k--) made[sz][p++] = orig[k];
            sz++;
        }
    }
    qsort(made, sz, sizeof(char) * 64, strcmp);
    printf("%s", made[0]);
    return 0;
}