#include <stdio.h>

/*
���� : ��, ��, ���� ī�尡 ���ļ� 5�� �̳��� �ִ�. �� ī��� 3, ���� 2, ���� 1�� ��ġ�� ���´�.
�̶�, �� ī���� �� �� �ִ� ���� ���� �͵��� ����Ѵ�.

�ذ� ��� : ��츦 ������ �ذ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : VTH 2017 K��
*/

int main(void) {
    int g, s, c, b = 0, v = 0, t = 0;
    scanf("%d %d %d", &g, &s, &c);
    b = g * 3 + s * 2 + c;
    if (b >= 8) v = 3;
    else if (b >= 5) v = 2;
    else if (b >= 2) v = 1;
    if (b >= 6) t = 3;
    else if (b >= 3) t = 2;
    else if (b >= 0) t = 1;
    if (v) printf("%s or ", v == 3 ? "Province" : v == 2 ? "Duchy" : "Estate");
    printf("%s", t == 3 ? "Gold" : t == 2 ? "Silver" : "Copper");
    return 0;
}