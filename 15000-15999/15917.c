#include <stdio.h>

/*
���� : �־��� �� A�� 2�� �ŵ����� ������ ���Ѵ�. �̴� A & -A == A��� ������ ���� ���� �� �ִٰ� �Ѵ�.

�ذ� ��� : �������� �־������ Ǯ�� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���� 2ȸ B��
*/

int main(void) {
    int q, a;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        if ((a & -a) == a) printf("1\n");
        else printf("0\n");
    }
    return 0;
}