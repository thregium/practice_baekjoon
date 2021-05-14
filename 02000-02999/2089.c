#include <stdio.h>

/*
���� : N(|N| <= 2 * 10^9)�� �־��� ��, N�� -2�������� ǥ���� ���� ���Ѵ�.

�ذ� ��� : -2������ �� �ڸ����� ������ ����� ������ ������ ���� ���ؼ� �ش� ���� �������� ���� �ִ�/�ּڰ��� ���Ѵ�.
���� �־����� ���ߴ� ������ �������� ���� ���� ���������� ������ ���� ������ ���� �ʴ��� ���� �׷��ٸ� ���� �ڸ���
1�� ����� N���� ���� �ڸ����� ����ŭ ���ش�. �̸� �ݺ��ϸ� ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ������
*/

long long digits[64];
int res[64];

int main(void) {
    digits[0] = 1;
    digits[1] = -2;
    for (int i = 2; i <= 48; i++) {
        digits[i] = digits[i - 2];
        if (i & 1) digits[i] -= (1LL << i);
        else digits[i] += (1LL << i);
    }
    long long n;
    int p = 0;
    scanf("%lld", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    for (int i = 48; i >= 0; i--) {
        if (n < 0) {
            if (digits[i] <= n && (i < 2 || digits[i - 2] > n)) {
                n += (1LL << i);
                res[48 - i] = 1;
            }
            else res[48 - i] = 0;
        }
        else {
            if (digits[i] >= n && (i < 2 || digits[i - 2] < n)) {
                n -= (1LL << i);
                res[48 - i] = 1;
            }
            else res[48 - i] = 0;
        }
        if (n == 0) break;
    }
    while (res[p] == 0) p++;
    for (int i = p; i <= 48; i++) {
        printf("%d", res[i]);
    }
    return 0;
}