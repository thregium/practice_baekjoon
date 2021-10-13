#include <stdio.h>

/*
���� : A, B(A, B <= 10000), S(S <= 10^9)�� �־��� ��, A���� ����� B���� ���� ����Ͽ� S������ ����� ����� �ִ��� ���ϰ�,
�����ϴٸ� �� �� ���� ���� ���� ����ϴ� ����� ���Ѵ�.

�ذ� ��� : ����, A�� B�� �ִ������� ���Ѵ�. ���� S�� �ִ������� ����� �ƴ϶�� S ������ A�� B�� �ڿ��� ���
���� �� �ִ� ����� ����. ����� ��쿡�� �������� ��´�. �������� �� ���� 0 �̻��̸� ���� ����,
S���� (A�� B�� �ּҰ����)�� ���� �������� ���� ���̴�.
�������� ���� �������� �� ū ���� ���������� �Ķ��Ʈ���� �����Ѵ�. �� ū ���� �� ���� �� / �ִ����� �� ������
�����̸� S�� ���� �� �ִ� ���� ū ����� ���Ѵ�. ���� ������� �׷��� ���� ���ٸ� ���� �� �ִ� ��찡 ���� ���̴�.
�׷��� ���� �ִٸ� �� ���� �̿��� A�� B�� ��� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����, �Ķ��Ʈ��

��ó : AUCPC 2010S A��
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int t, a, b, s, g, l, stt1, stt2, swapped;
    long long lo, hi, mid, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &a, &b, &s);
        if (a < b) {
            swap(&a, &b);
            swapped = 1;
        }
        else swapped = 0;
        g = gcd(a, b);
        if (s % g) {
            printf("Impossible\n"); //�Ұ����� ��� 1
            continue;
        }
        for (stt1 = 0;; stt1++) {
            if ((s - a * stt1) % b) continue;
            for (stt2 = 0;; stt2++) {
                if ((a * stt1 + b * stt2) % (a * b / g) == s % (a * b / g)) break; //������ ���
            }
            break;
        }
        l = b / g;

        lo = -1, hi = 1012345678;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (a * stt1 + mid * a * l + b * stt2 <= s) lo = mid;
            else hi = mid - 1;
        } //�Ķ��Ʈ��
        if (lo < 0) {
            printf("Impossible\n"); //��� �������� ���� �� �� ���� ��
            continue;
        }
        if ((s - a * stt1 - lo * a * l - b * stt2) % b) return 1; //�߸� �� ���?
        r = (s - a * stt1 - lo * a * l - b * stt2) / b; //�� ���� ���� ��� ��
        if (swapped) printf("%lld %lld\n", r + stt2, lo * l + stt1); //�� ���� �������� ������ ���ϸ� ���� �ȴ�.
        else printf("%lld %lld\n", lo * l + stt1, r + stt2);
    }
    return 0;
}