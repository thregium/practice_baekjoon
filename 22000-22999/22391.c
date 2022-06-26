#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^18)�� �־��� ��, N��°�� ���� �� 2���� ���ڷ� �̷���� ���� ���Ѵ�.
���� 0���� ������ �� ����.

�ذ� ��� : �� ���� �ڸ����� ������ ������ �������� �̿��Ͽ� �� ��쿡 ���� �������� ���� ���� �� �ִ�.
�켱 ���� ���̸� ���� ����, �� �ڸ����� �տ������� ������ ������ �ȴ�.

�ֿ� �˰��� : ����, ���շ�

��ó : JAG 2018D D��
*/

int main(void) {
    long long n, len = 0, types, type1 = 0, type2 = 0;
    while (1) {
        scanf("%lld", &n);
        if (n == 0) break;
        len = 2;
        for (long long i = 1;; i++) {
            if (((1LL << i) - 1) * 81 < n) {
                len = i + 2;
                n -= ((1LL << i) - 1) * 81;
            }
            else break;
        }
        types = 0;
        for (long long i = 0; i < len; i++) {
            if (i == 0) {
                for (int j = 1; j <= 9; j++) {
                    if (((1LL << (len - 1)) - 1) * 9 < n) n -= ((1LL << (len - 1)) - 1) * 9;
                    else {
                        type1 = j;
                        break;
                    }
                }
                printf("%lld", type1);
                types++;
                continue;
            }
            if (types == 1) {
                for (int j = 0; j <= 9; j++) {
                    if (j == type1) {
                        if (((1LL << (len - i - 1)) - 1) * 9 < n) n -= ((1LL << (len - i - 1)) - 1) * 9;
                        else {
                            printf("%d", j);
                            break;
                        }
                    }
                    else {
                        if (1LL << (len - i - 1) < n) n -= (1LL << (len - i - 1));
                        else {
                            printf("%d", j);
                            type2 = j;
                            types++;
                            break;
                        }
                    }
                }
            }
            else {
                for (int j = 0; j <= 9; j++) {
                    if (j != type1 && j != type2) continue;
                    if (1LL << (len - i - 1) < n) n -= (1LL << (len - i - 1));
                    else {
                        printf("%d", j);
                        break;
                    }
                }
            }
        }

        printf("\n");
    }
    return 0;
}