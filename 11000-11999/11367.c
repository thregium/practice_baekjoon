#include <stdio.h>

/*
���� : �̸��� ������ �־��� ��, �̸��� ����� ����Ѵ�. (���ǥ ����)

�ذ� ��� : �̸��� �״�� ����� �� ���ǥ�� �°� ����� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : UVaH 2014 C��
*/

char a[16];

int main(void) {
    int n, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", a, &b);
        printf("%s ", a);
        if (b >= 97) printf("A+");
        else if (b >= 90) printf("A");
        else if (b >= 87) printf("B+");
        else if (b >= 80) printf("B");
        else if (b >= 77) printf("C+");
        else if (b >= 70) printf("C");
        else if (b >= 67) printf("D+");
        else if (b >= 60) printf("D");
        else printf("F");
        printf("\n");
    }
    return 0;
}