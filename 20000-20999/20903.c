#include <stdio.h>

/*
���� : N * N(N <= 100) ũ�� ���忡�� 600�� ���� �� 2���� ������ ��� ���� ��´�.
�� ������ �����¿�� �����̰ų� �������� ���� �� �ְ�, ��� ���� ���� ������� �̵��Ѵ�. �� ������ ��ĥ �� ������,
��� ���� ��ġ�� ��� ���� ���� ���̴�.

�ذ� ��� : �� ���� X��ǥ�� �������� ��� ���� ��������� �������� �̵��ϰ�
�ٸ� �� ���� Y��ǥ�� �������� ��� ���� ��������� ��� ���� �������� ������ �ǹǷ� ��� ���� �׻� N�� ���� ���� �� �ִ�.

�ֿ� �˰��� : ������, ���� �̷�

��ó : GCPC 2020 C��
*/

int main(void) {
    int n, px1, py1, px2, py2, ox, oy;
    scanf("%d", &n);
    scanf("%d %d %d %d", &px1, &py1, &px2, &py2);
    while (1) {
        scanf("%d %d", &ox, &oy);
        if (ox == 0 && oy == 0) return 0;
        if (px1 < ox) px1++;
        else if (px1 > ox) px1--;
        else if (py1 < oy) py1++;
        else if (py1 > oy) py1--;

        if (py2 < oy) py2++;
        else if (py2 > oy) py2--;
        else if (px2 < ox) px2++;
        else if (px2 > ox) px2--;

        printf("%d %d %d %d\n", px1, py1, px2, py2);
        fflush(stdout);
    }
    return 0;
}