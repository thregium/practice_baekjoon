#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
���� : N(N <= 10000)���� ���ĺ��� '-'�� �̷���� ���ڿ��� �־��� ��, '-'�� �����ϰ� ��ҹ��ڸ� �����Ѵٸ�
���� �ٸ� ���ڿ��� ���� ���Ѵ�.

�ذ� ��� : �� ���ڿ��鿡�� -�� �����ϰ� ��� ���ڸ� �ҹ��ڷ� �ٲپ� ���ο� ���ڿ����� �����Ѵ�.
�� ���� �ش� ���ڿ��� �����ϰ� ������ ���ڿ��� ��� ���� �ٸ� ���� �� + 1�� �ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : PA 2002.05 1-1��
*/

char buff[103000], reduc[10240][32];

int main(void) {
    int n, p, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        p = 0;
        for (int j = 0; buff[j]; j++) {
            if (isalpha(buff[j])) reduc[i][p++] = tolower(buff[j]);
        }
    }
    qsort(reduc, n, sizeof(char) * 32, strcmp);
    for (int i = 1; i < n; i++) {
        if (strcmp(reduc[i], reduc[i - 1])) r++;
    }
    printf("%d", r);
    return 0;
}