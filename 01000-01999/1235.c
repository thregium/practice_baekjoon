#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ���� ����(<= 100)�� ���ڷ� �Ǿ� �ִ� ���ڿ��� �־�����. �̶�, ��� ���ڿ����� ���� �ٸ�
���̻� ��� ���� ���̰� ª�� ���� ���̸� ���Ѵ�.

�ذ� ��� : �� �տ������� �ش� ���ڿ��� �����ϴ� ���̻縦 �����ϰ� ������ ����, ��ġ�� ���� �ִ��� Ȯ���Ѵ�.
��ġ�� ���� ����� ������ ���̻� ���� + 1�� ���� �ȴ�. �׷��� ��찡 ���ٸ� ���� 1�̴�.

�ֿ� �˰��� : ���Ʈ ����, ���ڿ�, ����
*/

char s[1024][128], ns[1024][128];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; s[0][i]; i++) {
        for (int j = 0; j < n; j++) {
            strcpy(ns[j], s[j] + i);
        }
        qsort(ns, n, sizeof(char) * 128, strcmp);
        r = 1;
        for (int j = 1; j < n; j++) {
            if (!strcmp(ns[j], ns[j - 1])) {
                r = 0;
                break;
            }
        }
        if (!r) {
            printf("%d", strlen(ns[0]) + 1);
            return 0;
        }
    }
    printf("1");
    return 0;
}