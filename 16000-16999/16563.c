#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 10^6)���� 2 �̻� 5 * 10^6 ������ �ڿ����� �־��� ��, �־����� �� �ڿ������� ���μ������� ����� ����Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��Ѵ�. 5 * 10^6 ������ ��� ������ ���μ������� ����� �̸� �����ص� ����,
���� �Էµ� �� ���� �ش��ϴ� ����� ����Ѵ�. ����� �ð��� ���̱� ���� �Ľ��� �Ϻ� �ؾ� �Ѵ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, �Ľ�

��ó : ������ 2018M C��
*/

int sieve[5242880][24];
char buff[16777216], buff2[1024], buff3[1024];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n, x, kk;
    char* c;
    for (int i = 2; i <= 5000000; i++) {
        if (sieve[i][0]) continue;
        for (int j = i; j <= 5000000; j += i) {
            for (int k = j; k % i == 0; k /= i) sieve[j][++sieve[j][0]] = i;
        }
    }
    fgets(buff, 128, stdin);
    n = strtoll(buff, NULL, 10);
    fgets(buff, 16777215, stdin);
    for (int i = 0; i < n; i++) {
        if (i == 0) c = strtok(buff, " ");
        else c = strtok(NULL, " ");
        if (c == NULL) return 1;
        x = strtoll(c, NULL, 10);
        strcpy(buff2, "");
        for (int j = 1; j <= sieve[x][0]; j++) {
            kk = 0;
            for (int k = sieve[x][j]; k; k /= 10, kk++) buff3[kk] = k % 10 + '0';
            buff3[kk] = '\0';
            for (int s = 0, e = strlen(buff3) - 1; s < e; s++, e--) swap(&buff3[s], &buff3[e]);
            buff3[kk] = ' ';
            buff3[kk + 1] = '\0';
            strcat(buff2, buff3);
        }
        printf("%s\n", buff2);
    }
    return 0;
}