#include <stdio.h>

/*
문제 : N(N <= 1000)개의 변수에 대한 수 범위(0 <=, <= 100, 정수)가 주어질 때, 이 범위의 정수 순서쌍들로
만들어지는 모든 f(x)의 값 합을 구한다. f(x)는 (sum(x)^4 + 2 * sum(x)^2) mod 5 + 1이다.
답은 10^6 이내로 주어진다.

해결 방법 : f(x)의 값은 최소 1이다. 따라서, 가능한 순서쌍은 최대 10^6개임을 알 수 있다.
그러므로 브루트 포스로 모든 경우에 대해 합을 구하고, 5로 나눈 나머지 + 1을 더해나가며 답을 찾으면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : NOIS 2012 1번
*/

int vw[1024][2];
int r = 0;

void track(int n, int p, int s) {
    if (n == p) {
        long long t = (long long)s * s % 5;
        r += (t * (t + 2)) % 5 + 1;
    }
    for (int i = vw[p][0]; i <= vw[p][1]; i++) {
        track(n, p + 1, s + i);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &vw[i][0], &vw[i][1]);
    }
    track(n, 0, 0);
    printf("%d", r);
    return 0;
}