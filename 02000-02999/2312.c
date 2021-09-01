#include <stdio.h>

/*
문제 : 자연수 N(N <= 100000)을 소인수분해한 결과를 구한다.

해결 방법 : 먼저 에라토스테네스의 체로 모든 소수들을 미리 찾아낸다. 그 다음으로 N이 입력되면,
N이 1이 될 때 까지 다음을 반복하면 된다. 소수들을 작은 수부터 차례로 확인해본다. 이때, N을 나눌 수 없다면 넘어가고,
나눌 수 있다면 나누어질 때 까지 N을 나눈다. 그 다음, 그 수가 나누어진 횟수를 구한다.

주요 알고리즘 : 수학, 정수론, 소인수분해
*/

char sieve[103000];

int main(void) {
    int t, n, c;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 100000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 2; n > 1; i++) {
            if (sieve[i] || n % i) continue;
            printf("%d ", i);
            c = 0;
            while (n % i == 0) {
                n /= i;
                c++;
            }
            printf("%d\n", c);
        }
    }
    return 0;
}