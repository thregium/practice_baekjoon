#include <stdio.h>
#include <string.h>

/*
���� : ���� 10�� ������ ���ڿ����� ���� 10 ������ ���ڿ� N�� �� �� ���ԵǴ��� ���Ѵ�.

�ذ� ��� : strstr�Լ��� �̿��Ѵ�.

�ֿ� �˰��� : ���ڿ�

��ó : ���ϴ� 2016 C��
*/

char h[103000], n[16];

int main(void) {
    int r = 0;
    char* t = h - 1;
    scanf("%s%s", h, n);
    while (1) {
        t = strstr(t + 1, n);
        if (t == NULL) break;
        r++;
    }
    printf("%d", r);
    return 0;
}