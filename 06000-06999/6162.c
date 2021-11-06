#include <stdio.h>

/*
���� : ���� ������ E�� ���� ������ A(0 <= E, A <= 10^6, A != 0)�� �־��� ��, ��� ���� �������� ���Ѵ�.
A�� E �̻��� ��� ������ �ƴϰ�(no drought), E�� A�� 5�� ���϶�� �Ϲ� ����(drought), 25�� ���϶�� �ް� ����(mega drought),
125�� ���϶�� mega mega drought, ... �̷� ������ �þ��.

�ذ� ��� : �� ���� �Է¹��� ����, A�� E�� ���� ���Ѵ� A�� E �̻��� ��� ������ �ƴϴ�.
�� ���ķδ� A�� 5�辿 �÷����� A�� E �̻��� ���� �ʴ� ��� mega�� �ϳ��� �÷�����.
A�� E �̻��� �Ǵ� ���� drought�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : USC 2014F A��
*/

int main(void) {
    int t, e, a;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &e, &a);
        printf("Data Set %d:\n", tt);
        if (a >= e) {
            printf("no drought\n\n");
            continue;
        }
        while (1) {
            a *= 5;
            if (a >= e) break;
            printf("mega ");
        }
        printf("drought\n\n");
    }
    return 0;
}