#include <stdio.h>

/*
���� : �־��� N(N <= 10)���� ������ Ư���� Ƚ����ŭ ������ ���� ���� ���� ���� ���Ѵ�. �־��� ���� ������ Ƚ���� ���� ä�� �־�����.
��, ���� Ƚ���� 10 �̸��̰�, �ᱣ���� 10^9 �����̴�.

�ذ� ��� : ���� Ƚ���� 10 �̸��̹Ƿ� �־��� ���� �Է¹��� ���� 10���� ���� ���̰�, ������ Ƚ���� 10���� ���� �������� �ȴ�.
���� �� ������ ���� �����ؼ� ���ϸ� �ȴ�.

�ֿ� �˰����� : ����, ��Ģ����

��ó : COCI 15/16#3 A��
*/

int main(void) {
    int n, p, t, x = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        t = 1;
        for (int i = 0; i < p % 10; i++) {
            t *= p / 10;
        }
        x += t;
    }
    printf("%d", x);
    return 0;
}