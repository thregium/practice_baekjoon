#include <stdio.h>

/*
���� : N(4 <= N <= 10)���� �ڿ���(<= 5)�� �̷���� �迭�� �ִ�. �� �迭�� 4���� ���� �� ���� �� �ִ�
�������� �迭 ������ ���� �� ��� ���� ū ���� ����.

�ذ� ��� : N�� �ſ� �۱� ������ �迭�� 4���� ������ ��� ��츦 �õ��� ���� ���� ���� ���س����� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : ���Ǵ� 2019C A��
*/

int che[16];

int main(void) {
    int n, a, b, c, d, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &che[i]);
    }
    for (int i = 0; i < n; i++) {
        a = 1;
        for (int j = 0; j <= i; j++) a *= che[j];
        for (int j = i + 1; j < n; j++) {
            b = 1;
            for (int k = i + 1; k <= j; k++) b *= che[k];
            for (int k = j + 1; k < n - 1; k++) {
                c = 1;
                for (int l = j + 1; l <= k; l++) c *= che[l];
                d = 1;
                for (int l = k + 1; l < n; l++) d *= che[l];
                if (a + b + c + d > r) r = a + b + c + d;
            }
        }
    }
    if (r <= 0) return 1;
    printf("%d", r);
    return 0;
}