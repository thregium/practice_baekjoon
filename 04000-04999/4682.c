#include <stdio.h>
#include <stdlib.h>

/*
���� : 9���� ������ �־��� ��, �ش� �������� 8���׺��� ����ױ����� ����� �ϴ� ���׽��� ������ �־��� ��� ����Ѵ�.

�ذ� ��� : ���׽��� ù ������ ���θ� ������ �ΰ� �������� ���� ����� ������ �������� ��츦 ������ ����� ������ �ȴ�.
�̶�, ��� ���� 0�� ��쿡 �����Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : MidC 1996 A��
*/

int main(void) {
    int coef, stt;
    while (1) {
        stt = 0;
        for (int i = 8; i >= 0; i--) {
            if (scanf("%d", &coef) == EOF) return 0;
            if (coef == 0) continue;
            if (stt == 0) {
                if (coef < 0) printf("-");
                if (abs(coef) > 1) printf("%d", abs(coef));
                else if (i == 0) printf("1");
                if (i > 1) printf("x^%d", i);
                else if (i == 1) printf("x");
                stt = 1;
            }
            else {
                if (coef < 0) printf(" - ");
                else printf(" + ");
                if (abs(coef) > 1) printf("%d", abs(coef));
                else if (i == 0) printf("1");
                if (i > 1) printf("x^%d", i);
                else if (i == 1) printf("x");
            }
        }
        if (!stt) printf("0");
        printf("\n");
    }
    return 0;
}