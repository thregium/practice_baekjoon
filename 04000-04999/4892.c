#include <stdio.h>

/*
���� : N0�� �־��� ��, �־��� ������� ����� �� ��� ����� ���Ѵ�.(���� ����)

�ذ� ��� : �־��� ��Ĵ�� ����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ��Ģ����

��ó : Arab 2009 D��
*/

int main(void) {
    int n0, n1, n2, n3, n4;
    for (int tt = 1;; tt++) {
        scanf("%d", &n0);
        if (n0 == 0) break;
        n1 = 3 * n0;
        if (n1 & 1) n2 = (n1 + 1) / 2;
        else n2 = n1 / 2;
        n3 = 3 * n2;
        n4 = n3 / 9;

        printf("%d. ", tt);
        if (n1 & 1) {
            printf("odd %d\n", n4);
        }
        else {
            printf("even %d\n", n4);
        }
    }
    return 0;
}