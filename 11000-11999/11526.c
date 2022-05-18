#include <stdio.h>

/*
���� : ���� ������ Ʈ���� ���м� P / Q(P, Q < 2^31)�� �� �� ������ �� ���Ѵ�.

�ذ� ��� : ���ʰ� �������� �̵��� Ȯ���� �����鼭 ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, Ʈ��

��ó : GNY 2015 E�� // IIPC 2015 E��
*/

int main(void) {
    int t, o, stt;
    unsigned long long n, p, q;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %llu/%llu", &o, &p, &q);
        n = 0;
        for (int i = 0; i < 64; i++) {
            if (p > q) {
                n += (1ULL << i);
                p -= q;
            }
            else if (p < q) q -= p;
            else {
                n += (1ULL << i);
                break;
            }
        }
        printf("%d %llu\n", o, n);
    }
    return 0;
}