#include <stdio.h>

/*
���� : �ѹ��� 5kg�� ���� �� �ִ� �ٱ��ϰ� ���� ��, 1kg, 2kg, 3kg, 4kg, 5kg�� ������ ����(<= 1000)�� ���� �־�����,
��� ������ ��� ���� �ٱ��ϰ� �ּ� �� �� �ʿ����� ���Ѵ�.

�ذ� ��� : ���ſ� ���Ǻ��� ���ʷ� ��ƺ���. 5kg�� ������ �� ���� �ϳ��� ���� �� �ְ�, 4kg�� 1kg¥���� �Բ�,
3kg�� 2kg �Ǵ� 1kg 2���� �Բ�, 2kg�� 2kg + 1kg �Ǵ� 2kg + 1kg * 3���� ���� �� �ִµ�,
��� �̷��� ������ �����ϹǷ� �̷��� �������� ������ ��� �ٱ����� ���� ���ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����
*/

int main(void) {
    int a, b, c, d, e, r = 0, cap;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
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