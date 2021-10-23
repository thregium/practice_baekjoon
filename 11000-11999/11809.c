#include <stdio.h>
#include <stdlib.h>

/*
���� : �� �ڿ��� N, M(N, M <= 10^9)�� �־��� ��, �� ���� �ڸ������� ���ؼ� �� ���� �ڸ����� ���� ������.
�ش� ������ ������ �� ���� ���� ���Ѵ�. ��, �ڸ����� �ϳ��� ���� �ʾҴٸ� "YODA"�� ����ϰ�,
���� �ڸ����� ���� ��쿡�� 0���� �����Ѵ�.

�ذ� ��� : �� �ڸ����� ���ʷ� �ڸ����� �� ������. ���� �ڸ����� 0�̶�� YODA�� ����ϰ�,
�ƴϸ� �� ���� �Ųٷ� ���� ���� strtoll �Լ��� ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : COCI 15/16#4 1��
*/

char a[16], b[16], ar[16], br[16];

int main(void) {
    int n, m, ap = 0, bp = 0;
    scanf("%d %d", &n, &m);
    while (n > 0 || m > 0) {
        if (n % 10 > m % 10) a[ap++] = n % 10 + '0';
        else if (n % 10 < m % 10) b[bp++] = m % 10 + '0';
        else {
            a[ap++] = n % 10 + '0';
            b[bp++] = m % 10 + '0';
        }
        n /= 10;
        m /= 10;
    }
    if (ap == 0) printf("YODA\n");
    else {
        for (int i = 0; i < ap; i++) ar[14 - i] = a[i];
        printf("%lld\n", strtoll(ar + 15 - ap, NULL, 10));
    }
    if (bp == 0) printf("YODA");
    else {
        for (int i = 0; i < bp; i++) br[14 - i] = b[i];
        printf("%lld", strtoll(br + 15 - bp, NULL, 10));
    }
    return 0;
}