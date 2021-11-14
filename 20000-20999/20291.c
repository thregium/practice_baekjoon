#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 50000)���� ���ϸ�(. 1���� �ҹ���, 100��)�� �־��� ��, Ȯ������ ������ ������ ���������� ����Ѵ�.

�ذ� ��� : ���ϸ��� strchr �Լ��� �̿��� Ȯ������ ��ġ�� ã�� �� �� �迭�� �����Ѵ�.
�� �迭�� ������ ����, �ߺ��� ���鼭 ������ ������ ���� ���ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : ������ 2020C A��
*/

char buff[128], ext[51200][128];

int main(void) {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strchr(buff, '.')) return 1;
        strcpy(ext[i], strchr(buff, '.') + 1);
    }
    qsort(ext, n, sizeof(char) * 128, strcmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && !strcmp(ext[i], ext[i - 1])) {
            c++;
            continue;
        }
        if (i > 0) printf("%d\n", c);
        c = 1;
        printf("%s ", ext[i]);
    }
    printf("%d", c);
    return 0;
}