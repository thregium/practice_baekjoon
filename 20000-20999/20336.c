#include <stdio.h>

/*
���� : N(N <= 100)���� �ڽ� ��� �ƹ��ų� �ϳ��� ��� ����Ѵ�. �� �ڽ��� D(D <= 42)���� �丮�� �̷���� �ִ�.

�ذ� ��� : ù ��° �ڽ��� �丮�� �״�� ����Ѵ�. �ٸ� �ڽ��� �� �ʿ����� ����.

�ֿ� �˰��� : ����

��ó : UKIEPC 2020 H�� / BAPC 2020 H��
*/

char buff[32];

int main(void) {
    int n, d;
    scanf("%d%d", &n, &d);
    printf("%d\n", d);
    for (int i = 0; i < d; i++) {
        scanf("%s", buff);
        printf("%s\n", buff);
    }
    return 0;
}