#include <stdio.h>

/*
���� : R * C ũ���� ���簢�� ���·� ���� ����Ѵ�.

�ذ� ��� : ������ ��������� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : AIPO 2017P 1��
*/

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("*");
        printf("\n");
    }
    return 0;
}