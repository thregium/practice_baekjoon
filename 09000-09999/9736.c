#include <stdio.h>
#include <string.h>

/*
���� : ���̸�ü���� ���� ���Ѵ�.

�ذ� ��� : ���� ������ Ǯ��� ��Ģ�� ã�´�. ���� b�� Ȧ¦���� �� a�� ����� ���� a�� �����Ǹ�,
�� b�� ����� ���� b�� �����ȴ�.

�ֿ� �˰��� : ����

��ó : Phil 2013M D��
*/

char id[1024];

int main(void) {
    int m, n, p, x, z, y, w;
    while (1) {
        scanf("%s %d %d %d", id, &m, &n, &p);
        if (!strcmp(id, "ZZ")) break;
        for (int i = 0; i < p; i++) {
            scanf(" a%db%d a%db%d", &x, &z, &y, &w);
            printf("ProblemID %s: a%db%d * a%db%d = a%db%d\n",
                id, x, z, y, w, (x + ((z & 1) ? (m - y) : y)) % m, (z + w) % n);
        }
    }
    return 0;
}