#include <stdio.h>
#include <stdlib.h>

/*
���� : �� ���� ���ݼ��� �����(Ű�� ����)(<= 11)���� ����ο����� �Ÿ�(<= 10000)�� �־��� ��,
���� ���°� �������̵��� �� ���Ѵ�.

�ذ� ��� : �� ���� ������ ��ġ�� ����ο��� ����� ������ ������ ��,
�������� ���� ����� ������ �������� 2��°�� ����� �������� ������ �ִ� �� Ȯ���Ѵ�.
�׷��ϴٸ� �������̵��̰�, �ƴ϶�� �������̵尡 �ƴϴ�.

�ֿ� �˰��� : ����, ����

��ó : SARC 2007 H�� / 2008 PB��
*/

int b[16], c[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, d;
    while (1) {
        scanf("%d %d", &a, &d);
        if (a == 0) break;
        for (int i = 0; i < a; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < d; i++) {
            scanf("%d", &c[i]);
        }
        qsort(b, a, sizeof(int), cmp1);
        qsort(c, d, sizeof(int), cmp1);
        printf("%c\n", b[0] < c[1] ? 'Y' : 'N');
    }
    return 0;
}