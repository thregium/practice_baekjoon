#include <stdio.h>
#include <stdlib.h>

/*
���� : 5���� ���� �־��� ��, �� ��°�� ū ���� �� ��°�� ���� ���� ���� 4 �̻��̸� KIN��, �� �ܿ��� ���� ū ���� ���� ���� ���� ������ ���� ����Ѵ�.

�ذ� ��� : ���� �����ϰ� 2��°�� ���� ���� 4��°�� ���� ���� ���� Ȯ���� ���� ��쿡 �°� ����ϸ� �ȴ�.
(�������� �ʰ� ���� ���� �ִ�.)

�ֿ� �˰��� : ����, ����?

��ó : Seoul 2004 A��
*/

int n[5];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 5; i++) {
            scanf("%d", &n[i]);
        }
        qsort(n, 5, sizeof(int), cmp1);
        if (n[3] - n[1] >= 4) printf("KIN\n");
        else printf("%d\n", n[1] + n[2] + n[3]);
    }
    return 0;
}