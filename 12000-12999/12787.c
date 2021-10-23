#include <stdio.h>

/*
���� : 64��Ʈ ��ȣ ���� ������ IP ���·� �ٲٰų� 64��Ʈ IP�� ���� ���·� �ٲ۴�.

�ذ� ��� : IP�� ������ �Է¹��� ����, ���ʺ��� ���ؼ� ���س����� �ǰ�, ������ �Է¹��� ����, ���ʺ��� �߶󳪰��� �ȴ�.
64��Ʈ '��ȣ ����' ������ ������ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : ���ϴ� 2016 J��
*/

unsigned long long x[8];

int main(void) {
    int t, m;
    unsigned long long n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &m);
        if (m == 1) {
            scanf("%llu.%llu.%llu.%llu.%llu.%llu.%llu.%llu", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7]);
            n = 0;
            for (int i = 0; i < 8; i++) {
                n <<= 8;
                n += x[i];
            }
            printf("%llu\n", n);
        }
        else if (m == 2) {
            scanf("%llu", &n);
            for (int i = 7; i >= 0; i--) {
                x[i] = (n & 255);
                n >>= 8;
            }
            printf("%llu.%llu.%llu.%llu.%llu.%llu.%llu.%llu\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7]);
        }
        else return 1;

    }
    return 0;
}