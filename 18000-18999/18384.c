#include <stdio.h>

/*
문제 : 5개의 자연수(<= 10^6)가 주어질 때, 각 해당 수 이상인 가장 작은 소수의 합을 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 미리 10^6 다음 소수까지의 소수 여부를 전부 구해놓는다.
그 후 수들을 입력받으며 각 수마다 그 수 이상으로 올라가며 나오는 첫 소수들을 합하면 된다.

주요 알고리즘 : 수학, 에라토스테네스

출처 : Kabul 2018 C번
*/

char sieve[1048576];

int main(void) {
    int t, x, r = 0;
    for (int i = 2; i < 1048576; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j < 1048576; j += i) sieve[j] = 1;
    }
    sieve[1] = 1;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &x);
            for (int j = x;; j++) {
                if (!sieve[j]) {
                    r += j;
                    break;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}