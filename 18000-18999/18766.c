#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ī�� ���� 2���� �־��� ��, �� ������ ������ ������ ���Ѵ�. �� ī��� ���� 2�� ���ڿ��� �־�����.
ī���� ù �ڴ� 'R', 'Y', 'B' �� �ϳ�, �� ��° �ڴ� �����̴�.

�ذ� ��� : �� ī�� ������ ���������� ������ ����, ��� ������ ���� ������ �˻��Ѵ�.
�ٸ� ���� �ϳ��� �ִٸ� �ٸ� ���̰� ��� ���ٸ� ���� ���̴�.

�ֿ� �˰��� : ����, ����
*/

char s1[256][8], s2[256][8];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s1[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", s2[i]);
        }
        qsort(s1, n, sizeof(char) * 8, strcmp);
        qsort(s2, n, sizeof(char) * 8, strcmp);
        r = 1;
        for (int i = 0; i < n; i++) {
            if (strcmp(s1[i], s2[i])) r = 0;
        }
        printf("%s\n", r ? "NOT CHEATER" : "CHEATER");
    }
    return 0;
}