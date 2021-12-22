#include <stdio.h>

/*
���� : �ڿ��� K(K <= 10^6)�� �־��� ��, 2�� �ŵ������� ���� ���� �ɰ��� K�� ���� �� �ִ� 2�� �ŵ������� ���ϰ�,
�̶� �ش� ���� �ɰ��� Ƚ���� ���Ѵ�.

�ذ� ��� : K�� ���� �� �ִ� ���� ���� 2�� �ŵ������� K �̻��� ���� ���� 2�� �ŵ������̴�.
�ش� ���� �ɰ��� Ƚ���� �� ������ K�� LSB���� ������ Ƚ���� ����.

�ֿ� �˰����� : ����, ������

��ó : COCI 09/10#7 2��
*/

int main(void) {
    int k, t, r = 0;
    scanf("%d", &k);
    for (int i = 0;; i++) {
        if ((1 << i) >= k) {
            printf("%d ", 1 << i);
            t = (1 << i) / (k & -k) / 2;
            while (t) {
                t >>= 1;
                r++;
            }
            printf("%d", r);
            break;
        }
    }
    return 0;
}