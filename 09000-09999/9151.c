#include <stdio.h>

/*
���� : ���� �ƴ� ���������� ���ü���� ������ ���� �� �ִ� N(N <= 151200) ������ ���� ū �ڿ����� ���Ѵ�.

�ذ� ��� : N�� 60 �̻��̸� ���������� 151200���� ũ��, 100 �̻��̸� ���ü���� 151200���� Ŀ����.
����, ���� 60�� 100���� �ݺ��غ��� ���� ������ ���� �� �ִ� N ������ ��� �ڿ����� ���� �� �ִ�.

�ֿ� �˰����� : ���Ʈ ����

��ó : Hakodate 2001 A��
*/

char chk[524288];

int main(void) {
    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= 100; j++) {
            chk[i * i * i + j * (j + 1) * (j + 2) / 6] = 1;
        }
    }
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        while (!chk[n]) n--;
        printf("%d\n", n);
    }
    return 0;
}