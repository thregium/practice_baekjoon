#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^8)을 K(K <= 10000)개의 소수로 만들 수 있는 지 여부를 구한다.

해결 방법 : 4 이상의 모든 짝수는 두 소수의 합을 이용해 표현할 수 있다는 골드바흐의 추측을 이용한다.
증명되지는 않았으나 10^8 이내의 모든 자연수에 대해 가능함이 확인되었다.
2개 이상의 소수로 짝수를 만들도록 바꿀 수 없는 경우에는 소수 판정을 통해 가능한 지 여부를 확인한다.
그 외에는 그렇게 바꾼 다음 4 이하의 수가 나오면 불가능하고,
그 외에는 모든 경우의 수를 시도해보면 된다.

주요 알고리즘 : 수학, 정수론, 골드바흐의 추측, 케이스 워크

출처 : kimyeonwoo0506
*/

int isprime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    if (k == 1) {
        if (isprime(n)) printf("%d", n);
        else printf("-1");
    }
    else if (k == 2) {
        if (n & 1) {
            if (isprime(n - 2)) printf("%d %d", 2, n - 2);
            else printf("-1");
        }
        else if (n == 4) printf("2 2");
        else {
            for (int i = 3; i <= n - i; i += 2) {
                if (isprime(i) & isprime(n - i)) {
                    printf("%d %d", i, n - i);
                    r = 1;
                    break;
                }
            }
            if (!r) return 1;
        }
    }
    else {
        if (n & 1) n -= (k - 2) * 2;
        else n -= (k - 2) * 2;
        if (n < 4) printf("-1");
        else {
            for (int i = 2; i < k; i++) {
                if ((n & 1) && i == k - 1) {
                    printf("3 ");
                    n--;
                }
                else printf("2 ");
            }
            if (n & 1) return 2;
            if (n == 4) printf("2 2");
            else {
                for (int i = 3; i <= n - i; i += 2) {
                    if (isprime(i) & isprime(n - i)) {
                        printf("%d %d", i, n - i);
                        r = 1;
                        break;
                    }
                }
                if (!r) return 1;
            }
        }
    }
    return 0;
}