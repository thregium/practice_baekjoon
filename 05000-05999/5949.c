#include <stdio.h>
#include <string.h>

/*
���� : �־��� 2 * 10^9 ������ �ڿ����� �޸��� ��´�.

�ذ� ��� : �־��� ���� �ڸ����� Ȯ���� ����, �ڿ��� 3�� �����°���� ,�� ������ �ȴ�. ���������� ���� �ʴ´�.

�ֿ� �˰��� : ���ڿ�

��ó : USACO 2010D B3��
*/

char n[32];

int main(void) {
    int l;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; i < l; i++) {
        printf("%c", n[i]);
        if (i == l - 1) break;
        if ((l - i - 1) % 3 == 0) printf(",");
    }
    return 0;
}