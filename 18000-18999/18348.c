#include <stdio.h>

/*
문제 : N(N <= 888888)개의 수로 이루어진 1 ~ N 순열에서 입력에 따라 인접한 두 수(와 양 끝)의 합들이 각각 소수 또는 합성수가 가장 많게 하는 방법을 출력한다.

해결 방법 : 먼저, 합성수가 나오게 하는 방법으로는 모든 짝수는 합성수이기 때문에 짝수들끼리, 홀수들끼리 서로 붙여준다.
그러면 홀수와 짝수들이 만나는 부분이 2개 생기는데 이 둘은 합을 홀수 합성수로 맞춰주면 된다. 가장 작은 수가 9이므로 4-5, 3-6끼리 붙여주는 것이 좋다.
물론, 5보다 작다면 그것이 불가능하므로 그대로 두면 된다.
다음으로, 소수가 나오게 하는 방법을 살펴보면 가능한 모든 인접한 수들을 홀수-짝수 꼴로 만들어야 한다. (2는 당연히 만들 수 없으므로 모든 소수는 홀수)
N이 짝수인 경우에는 홀수-짝수를 교대로 나오도록 하면 된다. 여기서 모든 수를 나오게 하기 위해서는
각 홀수들과 짝수들은 등차와 N과의 최대공약수가 2인 등차수열을 이루어야 한다. 두 수의 합이 반복되는 것이 좋으므로 등차가 서로 반대 방향(합치면 N)이 되어야 한다.
이렇게 하면 나오는 수가 최대 4개가 되고, 4개의 수가 모두 소수라면 그 수들을 출력하면 된다.
N이 홀수인 경우에는 N - 1까지의 수에 대해 짝수부터 오도록 하고 마지막에 N을 출력하면 된다. 단, 첫 번째 수는 N과 더하면 소수가 나와야 한다.
이때, 위 규칙은 8 미만에서는 적용할 수 없으므로 8 미만은 직접 푼다.

주요 알고리즘 : 수학, 에라토스테네스의 체, 구성적

출처 : 전시관 1 7번
*/

char s[16], sieve[1835008];
int primes[103000], pp = 0;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m, p = -1, q = -1, x, cnt = 0, tmp;
    scanf("%s %d", s, &n);
    if (s[0] == 'o') {
        if (n >= 6) {
            printf("4 2 ");
            for (int i = 8; i <= n; i += 2) printf("%d ", i);
            printf("6 3 1 ");
            for (int i = 7; i <= n; i += 2) printf("%d ", i);
            printf("5");
        }
        else if (n == 5) printf("4 2 3 1 5");
        else {
            for (int i = 2; i <= n; i += 2) printf("%d ", i);
            for (int i = 1; i <= n; i += 2) printf("%d ", i);
        }
        return 0;
    }
    else if (n < 8) {
        //8 미만에 대해서는 직접 처리해준다.
        switch (n) {
        case 2:
            printf("1 2");
            break;
        case 3:
            printf("1 2 3");
            break;
        case 4:
            printf("1 2 3 4");
            break;
        case 5:
            printf("1 2 5 3 4");
            break;
        case 6:
            printf("1 4 3 2 5 6");
            break;
        case 7:
            printf("1 2 3 4 7 6 5");
            break;
        }
        return 0;
    }

    for (int i = 2; i <= (n << 1); i++) {
        if (sieve[i]) continue;
        if (i < n) primes[pp++] = i;
        for (int j = i * 2; j <= (n << 1); j += i) sieve[j] = 1;
    }
    if (n & 1) {
        m = n - 1;
        x = 1;
        for (int i = 1; i <= m; i++) {
            if (!sieve[n + i]) {
                x = i;
                break;
            }
        }
    }
    else {
        m = n;
        x = 1;
    }

    for (int i = 1; i < pp; i++) {
        if (sieve[primes[i] + m]) continue; //N + p가 소수여야 한다.
        for (int j = 1; j < i; j++) {
            if (sieve[primes[j] + m]) continue; //N + q가 소수여야 한다.
            if (gcd(primes[i] - primes[j], m) == 2) {
                //또한, p - q와 N의 최대공약수가 2여야 한다.
                p = primes[i];
                q = primes[j];
                break;
            }
        }
        if (p >= 0) break;
    }
    if (p < 0) return 1;
    for (int i = 1; i <= m; i++) {
        printf("%d ", x);
        //tmp = x;
        if (i & 1) x = (q - x + m - 1) % m + 1; //홀수번째인 경우 q에서 이전 값을 뺀다.
        else x = (p - x + m - 1) % m + 1; //짝수번째인 경우 p에서 이전 값을 뺀다.
        //if (sieve[tmp + x]) cnt++;
    }
    if (n & 1) printf("%d", n);
    //printf("\n\ncomposites : %d", cnt);
    return 0;
}