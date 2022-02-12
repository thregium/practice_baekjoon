#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 정수(|| <= 100000)를 곱하거나 나눈 식의 결과가 정수인 지 구한다.
0으로 나누는 경우는 주어지지 않는다.

해결 방법 : 모든 정수를 소인수분해하여 곱하는 경우 각 소수의 개수에 더하고,
나누는 경우 개수에서 뺀다. 이를 반복한 다음 모든 항의 소수 개수가 0 이상인 경우 정수이고,
음수인 것이 하나라도 있다면 정수가 아님을 알 수 있다. 단, 0을 한 번이라도 곱한 경우
답은 0이기 때문에 소수 개수 중 음수인 것이 있더라도 답은 정수이다.

주요 알고리즘 : 수학, 소인수분해

출처 : 서강대 2020M D번
*/

int prime[10240], pcnt[10240], sieve[103000];
int pp = 0;

void factorize(int x, int m) {
    for (int i = 0; prime[i] * prime[i] <= x && i < pp; i++) {
        while (x % prime[i] == 0) {
            pcnt[i] += m;
            x /= prime[i];
        }
    }
    for (int i = pp - 1; i >= 0; i--) {
        if (prime[i] == x) {
            pcnt[i] += m;
            return;
        }
    }
}

int main(void) {
    int n, m, o = 1, z = 0, r = 1;
    char c;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 100000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    scanf("%d", &m);
    if (m) factorize(abs(m), o);
    else z = 1;
    for (int i = 1; i < n; i++) {
        scanf(" %c", &c);
        scanf("%d", &m);
        if (c == '*') o = 1;
        else o = -1;
        if (m) factorize(abs(m), o);
        else z = 1;
    }
    if (z) printf("mint chocolate");
    else {
        for (int i = 0; i < pp; i++) {
            if (pcnt[i] < 0) r = 0;
        }
        printf("%s", r ? "mint chocolate" : "toothpaste");
    }
    return 0;
}