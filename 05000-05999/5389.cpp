#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 10^9)이 주어질 때, 차이로 N을 만드는 두 제곱수를 출력한다. 그러한 것이 여럿인 경우
큰 수가 작은 쪽을 선택한다. 그러한 것이 없는 경우 IMPOSSIBLE을 출력한다.

해결 방법 : 홀수 등차수열의 합 공식을 생각해보면 짝수 개의 수의 합 또는 홀수 개의 수의 합인 경우로
나뉠 수 있다. 홀수 개의 수의 합인 경우 평균은 홀수, 개수도 홀수가 되어야 하고,
짝수 개의 수의 합인 경우 평균과 개수가 모두 짝수가 되어야 한다. 따라서, 4로 나눈 나머지가 2인 경우
하나는 홀수, 나머지 하나는 짝수가 되어야 하기 때문에 그러한 것이 없다.

홀수 개의 수의 합인 경우와 짝수 개의 수의 합인 경우 모두 두 수의 차가 가장 작은 곱을 구한 다음,
그 수들을 이용하여 ceil(큰 수 / 2)를 평균, 다른 한 값을 개수로 하여 두 제곱수를 찾으면 된다.

주요 알고리즘 : 수학, 정수론

출처 : BAPC 2011 J번
*/

long long isqrt(long long x) {
    long long r = sqrt(x);
    for (int i = -1; i <= 1; i++) {
        if ((r + i) * (r + i) == x) return r + i;
    }
    return -1;
}

int main(void) {
    int t, n, r1, r2, md;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        //n = tt + 1;
        r1 = -1, r2 = -1;
        if ((n & 3) == 2) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else if ((n & 3) == 0) {
            for (int i = 2; i * i <= n; i += 2) {
                if (n % i == 0) {
                    if ((n / i) & 1) continue;
                    r1 = n / i;
                    r2 = i;
                }
            }
        }
        else {
            for (int i = 1; i * i <= n; i += 2) {
                if (n % i == 0) {
                    r1 = n / i;
                    r2 = i;
                }
            }
        }
        if (r1 < 0) return 1;
        md = (r1 + 1) >> 1;
        printf("%d %d\n", md - ((r2 + 1) >> 1), md + (r2 >> 1));
    }
    return 0;
}