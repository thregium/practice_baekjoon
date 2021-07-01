#include <stdio.h>

/*
문제 : N * M 크기의 격자를 왼쪽 위 꼭짓점에서 오른쪽 아래 꼭짓점으로 직선을 그어 나눌 때, 정확히 절반으로 나뉘는 칸의 수를 구한다.

해결 방법 : N과 M이 서로소가 아니라면 직선은 여러번 꼭짓점을 지나게 된다. 따라서, N과 M을 최대공약수로 나누어 서로소로 만든 다음 시작한다.
N과 M이 서로소인 경우에는 한 수는 홀수, 한 수는 짝수이거나 두 수 모두 홀수가 된다. 그런데, 한 수가 짝수인 경우에는
짝수인 줄의 중앙을 지나면서 절반으로 나뉘는 칸이 생기지 않게 된다. 두 수 모두 홀수라면 중앙의 칸에서 절반으로 나뉘는 칸이 생긴다.
따라서, 짝수인 경우에는 항상 0이고, 홀수인 경우에는 두 수의 최대공약수와 같게 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법

출처 : NAQ 2019 B번
*/

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    long long m, n, g;
    scanf("%lld %lld", &m, &n);
    g = gcd(m, n);
    if (((m / g) & 1) && ((n / g) & 1)) printf("%lld", g);
    else printf("0");
    return 0;
}