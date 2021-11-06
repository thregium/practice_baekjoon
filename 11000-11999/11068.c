#include <stdio.h>

/*
���� : �ڿ��� N(64 <= N <= 10^6)�� �־��� ��, 2�������� 64���� ������ �� ��� �ش� �������� ��Ÿ����
ȸ���� �Ǵ� ������ �ִ��� ���Ѵ�.

�ذ� ��� : 2�������� 64���������� �� �������� N�� ��Ÿ�����鼭 ȸ���� ��츦 ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : Daejeon 2015I H��
*/

int digit[32];

int main(void) {
    int t, n, l, r, r2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 2; i <= 64; i++) {
            l = 0;
            for (int j = n; j; j /= i) {
                digit[l++] = j % i;
            }
            r2 = 1;
            for (int j = 0, k = l - 1; j <= k; j++, k--) {
                if (digit[j] != digit[k]) {
                    r2 = 0;
                    break;
                }
            }
            r |= r2;
            if (r) break;
        }
        printf("%d\n", r);
    }
    return 0;
}