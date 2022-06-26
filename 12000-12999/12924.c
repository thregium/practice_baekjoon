#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : [A, B](A <= B <= 2 * 10^6)���� ���� ���� ������ ���Ѵ�.
���� ���� �� �ڿ����� ���� �ڸ����� �о ��������� ���� ������ ���̴�.

�ذ� ��� : ��� ���� ���� �� ������ ū ���� ���� ������ ���Ѵ�.
���ڿ� �Լ��� �̿��ϸ� ���ϴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ���ڿ�
*/

char s[16], t[16];
int x[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, b, l, res = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        sprintf(s, "%d", i);
        l = strlen(s);
        for (int j = 0; j < l; j++) {
            strcpy(t, s + j);
            for (int k = 0; k < j; k++) t[l - j + k] = s[k];
            t[l] = '\0';
            x[j] = strtoll(t, NULL, 10);
        }
        qsort(x, l, sizeof(int), cmp1);
        for (int j = 0; j < l; j++) {
            if (j > 0 && x[j] == x[j - 1]) continue;
            if (x[j] <= i || x[j] > b) continue;
            res++;
        }
    }
    printf("%d", res);
    return 0;
}