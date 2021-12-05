#include <stdio.h>

/*
���� : �����̰� �칰 �ٴڿ��� ���̰� H�� �칰�� �ö󰡷� �Ѵ�. �Ϸ翡 U * (100 - F * �� ��) / 100�� �ö󰡰�,
D�� �����´ٸ� �칰�� �ö󰡰ų� ���� �칰 �ٴ����� �������� ���� ���Ѵ�.
��, �칰�� �� ������ �� �� �Ǵ� �ٴں��� �� �Ʒ��� �����;� ������ ���̰�, �ƹ��� ���� �ö󰡵� ������ŭ �ö����� �ʴ´�.

�ذ� ��� : ���� �ö󰡴� ��� �� ��ġ, ��¥�� �����ذ��� �칰�� ����� �Ǵ� �ٴڿ� �����ϴ� ������ ��� Ȯ���س����� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 1997 B��
*/

int main(void) {
    int h, u, d, f, day;
    double updist, pos;
    while (1) {
        scanf("%d %d %d %d", &h, &u, &d, &f);
        if (h == 0) break;
        pos = 0;
        day = 1;
        updist = u;
        while (1) {
            pos += updist;
            if (pos > h) {
                printf("success on day %d\n", day);
                break;
            }
            pos -= d;
            if (pos < 0) {
                printf("failure on day %d\n", day);
                break;
            }
            day++;
            updist -= (double)u * f / 100.0;
            if (updist < 0) updist = 0;
        }
    }
    return 0;
}