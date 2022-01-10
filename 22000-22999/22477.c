#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 256)���� ��ϵ� �̸�(10��, �ҹ���)�� �־�����. �׸��� �ٽ� M(M <= 256)���� �̸��� �־��� ��,
������� ��ϵ� �̸����� Ȯ���ϰ� ��ϵ� �̸��� ��� ���� ���θ� �ٲپ� ����Ѵ�.
��ϵ��� ���� �̸��̶�� ��ϵ��� �ʾҴٰ� ����Ѵ�.

�ذ� ��� : �� ����� �̸��� ������ ���� �̺� Ž���� ���� �̸��� �ִ� �� Ȯ���Ѵ�.
�׸��� ��쿡 �´� ����� �ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����, �̺� Ž��

��ó : JAG 2012S3B A��
*/

char s[384][16], buff[16];

int main(void) {
    int n, m, d = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 16, strcmp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        if (!bsearch(buff, s, n, sizeof(char) * 16, strcmp)) {
            printf("Unknown %s\n", buff);
            continue;
        }
        if (d) printf("Closed by %s\n", buff);
        else printf("Opened by %s\n", buff);
        d = !d;
    }
    return 0;
}