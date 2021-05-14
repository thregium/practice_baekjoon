#include <stdio.h>

/*
문제 : N(|N| <= 2 * 10^9)이 주어질 때, N을 -2진법으로 표기한 값을 구한다.

해결 방법 : -2진법의 각 자릿수의 값들을 양수와 음수로 나누고 각각 더해서 해당 수를 포함했을 때의 최대/최솟값을 구한다.
수가 주어지면 구했던 값들의 역순으로 현재 수가 다음값에는 들어가지만 현재 값에는 들어가지 않는지 보고 그렇다면 현재 자리를
1로 만들고 N에서 현재 자릿수의 값만큼 빼준다. 이를 반복하면 값을 구할 수 있다.

주요 알고리즘 : 수학, 정수론
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