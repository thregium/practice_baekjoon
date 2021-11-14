#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���ڿ� N(N <= 100000)���� �ִ� ���հ�, �� ���տ��� ���ڿ� �� ���� ����� ������ �־��� ��,
����� ���ڿ��� ���Ѵ�.

�ذ� ��� : �� ���ڿ��� ������ ����, ���� ���Һ��� ���Ѵ�. ó������ �޶����� ������ N�� �ִ� ���տ����� ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : COCI 14/15#2 2��
*/

char orig[103000][32], fin[103000][32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", orig[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%s", fin[i]);
    }
    qsort(orig, n, sizeof(char) * 32, strcmp);
    qsort(fin, n - 1, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        if (strcmp(orig[i], fin[i])) {
            printf("%s", orig[i]);
            return 0;
        }
    }
    return 1;
}