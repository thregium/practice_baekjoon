#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N + M(N, M <= 100000)���� �̸��� �־��� ��, �̸��� �������� ���Ѵ�.
�� �̸��� 10�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ִ�.

�ذ� ��� : N + M���� �̸����� ���� �Է¹ް� �����Ѵ�. �� ���� ���� �Ͱ� �ٸ� �̸��� ������ ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : CornH 2015 7��
*/

char name[103000 * 2][16];

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n + m; i++) {
            scanf("%s", name[i]);
        }
        qsort(name, n + m, sizeof(char) * 16, strcmp);
        r = 1;
        for (int i = 1; i < n + m; i++) {
            if (strcmp(name[i], name[i - 1])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}