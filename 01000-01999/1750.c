#include <stdio.h>
#define MOD 10000003

/*
문제 : N(N <= 50)개의 자연수(<= 100000)로 이루어진 집합의 공집합이 아닌 부분집합 가운데
모든 수의 최대공약수가 1이 되는 집합의 개수를 구한다.

해결 방법 : 각 수가 나올 때 마다 그 수까지 확인했을 때 각 최대공약수별로 집합의 개수를 세면 된다.
이 과정에서 다이나믹 프로그래밍과 유클리드 호제법을 이용하면 된다.

주요 알고리즘 : 수학, 정수론, DP, 유클리드 호제법
*/

int s[64], mem[64][103000];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100000; j++) {
            mem[i][j] = (mem[i][j] + mem[i - 1][j]) % MOD;
            mem[i][gcd(j, s[i])] = (mem[i][gcd(j, s[i])] + mem[i - 1][j]) % MOD;
        }
        mem[i][s[i]] = (mem[i][s[i]] + 1) % MOD;
    }
    printf("%d", mem[n][1]);
    return 0;
}