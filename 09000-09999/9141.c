#include <stdio.h>

/*
���� : N * N(N <= 15 * 10^8) ũ���� ���� ���� ü���ǿ��� N���� ���� ���� �������� �ʰ�
��ġ�ϴ� ����� �ִ� �� ���Ѵ�.

�ذ� ��� : ���Ʈ ������ 15 * 15���� ���� �ִ� �� Ȯ���� ����
6ȸ ������ ���� �ݺ����� �� �� �ִ�. N�� 2�� 3���� ������ �������� ������ ��ġ �����ϰ�,
�� �ܿ��� ��ġ �Ұ����ϴ�.

�ֿ� �˰����� : �ֵ� Ȥ?

��ó : CTU 2001 G��
*/

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("Kralovny %s.\n", (n % 2) && (n % 3) ? "lze umistit" : "se nevejdou");
    }
    return 0;
}