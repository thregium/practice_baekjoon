#include <stdio.h>

/*
���� : ũ�Ⱑ 5kg, 4kg, 3kg, 2kg, 1kg�� ������ ���� A, B, C, D, E(A, B, C, D, E <= 1000)�� �־�����.
�̶�, �뷮 5kg�� ������ �� �� �ʿ��� �� ���Ѵ�.

�ذ� ��� : ���� ũ�Ⱑ ū �ͺ��� ���ʷ� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : CPC 2012 D��
*/

int main(void) {
    int a, b, c, d, e, r = 0, cap;
    scanf("%d %d %d %d %d", &e, &d, &c, &b, &a);
    while (a + b + c + d + e) {
        cap = 5;
        while (e > 0 && cap >= 5) {
            cap -= 5;
            e--;
        }
        while (d > 0 && cap >= 4) {
            cap -= 4;
            d--;
        }
        while (c > 0 && cap >= 3) {
            cap -= 3;
            c--;
        }
        while (b > 0 && cap >= 2) {
            cap -= 2;
            b--;
        }
        while (a > 0 && cap >= 1) {
            cap -= 1;
            a--;
        }
        r++;
    }
    printf("%d", r);
    return 0;
}