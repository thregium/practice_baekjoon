#include <stdio.h>

/*
���� : 30�� ������ �� ���ڿ� A�� B�� �־��� ��, �� ���ڿ� ���� ��ġ�� ù ���ڸ� ã�� ũ�ν����� ���·� ����Ѵ�.

�ذ� ��� : ������ ���δ�� �����Ѵ�. ����/���ΰ� �ٲ� �����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : COCI 11/12#5 1��
*/

char a[32], b[32];

int main(void) {
    int x = -1, y = -1;
    scanf("%s %s", a, b);
    for (int i = 0; a[i]; i++) {
        for (int j = 0; b[j]; j++) {
            if (a[i] == b[j]) {
                x = i;
                y = j;
                break;
            }
        }
        if (x >= 0) break;
    }

    for (int i = 0; b[i]; i++) {
        for (int j = 0; a[j]; j++) {
            if (i == y) printf("%c", a[j]);
            else if (j == x) printf("%c", b[i]);
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}