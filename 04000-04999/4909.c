#include <stdio.h>
#include <stdlib.h>

/*
���� : 6���� �ű� ������ �־��� ��, �ִ񰪰� �ּڰ��� �� ����� ����Ѵ�. ������ 0 �̻� 10 ������ �����̴�.
�ʿ� ���� �ڸ��� ����ؼ��� �� �ȴ�.

�ذ� ��� : ������ ������ ����, 2��°���� 5��°������ ���� ���� ���ϰ� 4�� ������ ���� ������ ���Ѵ�.
�Ҽ� ������ 4�� ���� �������� ���߾� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ��Ģ����

��ó : Arab 2007 A��
*/

int a[6];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int s;
    while (1) {
        for (int i = 0; i < 6; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, 6, sizeof(int), cmp1);
        if (a[5] == 0) break;
        s = a[1] + a[2] + a[3] + a[4];
        printf("%d", s >> 2);
        if ((s & 3) == 0) printf("\n");
        else if ((s & 3) == 1) printf(".25\n");
        else if ((s & 3) == 2) printf(".5\n");
        else printf(".75\n");
    }
    return 0;
}