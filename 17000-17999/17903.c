#include <stdio.h>

/*
���� : �־��� 3-SAT ������ Ǭ ����� ����Ѵ�(?)

�ذ� ��� : �� �������̰� �ڼ��� ���� ��� M�� ũ�Ⱑ 8 �̻��̸� ��, 8 �̸��̸� ������ ����Ѵٰ� ���´�.

�ֿ� �˰��� : ����?

��ó : Bergen 2018 C��
*/

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    if (m >= 8) printf("satisfactory");
    else printf("unsatisfactory");
    return 0;
}