#include <stdio.h>

/*
���� : 50���� ������ ������������ �־��� ��, ���� �־��� ������ ����� ������� ��� ������� ���Ѵ�.
������ �־����� �ʴ´�.

�ذ� ��� : ������ ������������ �־����� ������ �־��� ������ �� ��°�� �������� ã���� �� ���� ����� �ȴ�.
����� ã���� ����� �´� ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ȫ�ʹ� 2019 A��
*/

int scores[64];

int main(void) {
    int x;
    for (int i = 1; i <= 50; i++) {
        scanf("%d", &scores[i]);
    }
    scanf("%d", &x);
    for (int i = 1; i <= 50; i++) {
        if (scores[i] == x) {
            if (i <= 5) printf("A+");
            else if (i <= 15) printf("A0");
            else if (i <= 30) printf("B+");
            else if (i <= 35) printf("B0");
            else if (i <= 45) printf("C+");
            else if (i <= 48) printf("C0");
            else printf("F");
            break;
        }
    }
    return 0;
}