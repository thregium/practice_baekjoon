#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���ڿ��� �� �ߺ��� ������ ���ڿ��� �� ������ ���Ѵ�.

�ذ� ��� : �� ���ڿ����� �Է¹��� ���� ���ڿ����� �����Ѵ�. �� �������δ� ��ü ���ڿ�����
���� ���ڿ��� ���� ���ڿ��� ���� ������ ���ڿ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : NZPC 2011 D��
*/

char towns[128][32];

int main(void) {
    int n, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            fgets(towns[i], 30, stdin);
            if (towns[i][0] == '\n') {
                i--;
                continue;
            }
        }
        qsort(towns, n, sizeof(char) * 32, strcmp);
        r = n;
        for (int i = 1; i < n; i++) {
            if (!strcmp(towns[i], towns[i - 1])) r--;
        }
        printf("Week %d %d\n", tt, r);
    }
    return 0;
}