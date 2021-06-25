#include <stdio.h>

/*
문제 : 짝수 X(X <= 10^6)이 주어질 때, X를 가장 차이가 큰 두 소수로 나누는 것을 반복한다면 3 이하가 되는데 몇 회나 해야 하는지 구한다.
단, 4 이상 10^6 이하의 모든 짝수에 대해 두 소수로 나누는 것은 가능하다.

해결 방법 : 먼저 에라토스테네스의 체를 통해 100만까지의 모든 소수를 구해준 후, 2부터 시작해서 i와 X - i가 모두 소수인
가장 작은 i를 찾은 뒤, X를 X - i * 2(= X - i - i)로 업데이트하고 다시 i를 찾는다. 이를 X가 4보다 작아질 때 까지 반복하며
횟수를 세면 된다.

주요 알고리즘 : 수학, 에라토스테네스의 체, 시뮬레이션

출처 : PacNW 2018 H/U번 // SEUSA 2018D2 C번
*/

char sieve[1048576];

int main(void) {
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            sieve[j] = 1;
        }
    }
    sieve[1] = 1;
    int x, r = 0;
    scanf("%d", &x);
    while (x > 3) {
        r++;
        for (int i = 2; i <= x; i++) {
            if (!sieve[i] && !sieve[x - i]) {
                x = x - 2 * i;
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}