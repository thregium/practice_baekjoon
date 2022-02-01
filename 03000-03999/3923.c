#include <stdio.h>
#include <stdlib.h>
#define INF 12345678987

/*
���� : 2���� ���� ����(<= 50000, �ڿ���)�� ���Ը� �� ������ ����(<= 50000, �ڿ���)�� �ִ�.
�̶�, �� ������ ���Ը� ��� ���� �ʿ��� �� ���� ������ ���Ѵ�. �� �� �ִ� ��찡 �����̹Ƿ�
���� ���� ���� ���� ���� ��, �� �߿��� ���� ���� ���� ���� ���� �����Ѵ�.

�ذ� ��� : ���ʿ� �� A�� 0������ 50000������ ���ʷ� ���ƺ��� ������ ��� ���
���� �켱�Ǵ� ��츦 ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : Ehime 2004 A��
*/

void upd(long long* ra, long long* rb, long long x, long long y, long long a, long long b) {
    if (x + y < *ra + *rb) {
        *ra = x;
        *rb = y;
    }
    else if (x + y == *ra + *rb && a * x + b * y < *ra * a + *rb * b) {
        *ra = x;
        *rb = y;
    }
}

int main(void) {
    long long a, b, d, ra, rb;
    while (1) {
        scanf("%lld %lld %lld", &a, &b, &d);
        if (a == 0) break;
        ra = INF, rb = INF;
        for (int i = 0; i <= 103000; i++) {
            if ((d - (a * i)) % b == 0) {
                upd(&ra, &rb, i, llabs((d - (a * i)) / b), a, b);
            }
            if ((d + (a * i)) % b == 0) {
                upd(&ra, &rb, i, (d + (a * i)) / b, a, b);
            }
        }
        printf("%lld %lld\n", ra, rb);
    }
    return 0;
}