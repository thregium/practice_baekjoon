#include <stdio.h>

/*
���� : S + M * 2 + L * 3�� ���� �ູ����� �� ��, �ູ���� 10 �̻��̸� happy, �̸��̸� sad�� ����Ѵ�.

�ذ� ��� : ������ �����ִ´�� �����Ѵ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : CCC 2020 J1��
*/

int main(void) {
    int s, m, l;
    scanf("%d%d%d", &s, &m, &l);
    if (s + m * 2 + l * 3 >= 10) printf("happy");
    else printf("sad");
    return 0;
}