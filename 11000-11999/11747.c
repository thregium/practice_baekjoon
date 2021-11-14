#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 1000)���� ���ڷ� �̷���� ���ڿ����� 0���� �ö󰡸� �� ������ ã�� ��, ã�� �� ���� ù ���� ���Ѵ�.

�ذ� ��� : �ƹ��� Ŀ�� 3�ڸ� �� �̳��δ� ���� ������ ���� �� �� �ִ�. ����, ���ڿ����� 1���� �ö󰡸�
������ ���� ã�ƺ��� ���� ���� �ð� ���� ã�� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : Tsukuba 2015 A��
*/

char d[1024], nd[1024];

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &d[i]);
    }
    for (int i = 0;; i++) {
        p = 0;
        for (int j = i; j; j /= 10) nd[p++] = j % 10 + '0';
        if (i == 0) nd[p++] = '0';
        nd[p] = '\0';
        for (int j = 0, k = p - 1; j < k; j++, k--) swap(&nd[j], &nd[k]);
        if (strstr(d, nd) == NULL) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}