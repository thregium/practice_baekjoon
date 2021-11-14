#include <stdio.h>

/*
문제 : N(N <= 100000)개의 구간이 있고, 각 구간의 길이(<= 50000)가 주어질 때, 구간을 처음부터 끝까지 왕복한다면
거리 K는 어느 구간인지 구한다. 구간 사이에 걸친 경우 다음 구간으로 생각한다.

해결 방법 : 매번 거리를 확인하면서 이번 구간 끝의 거리가 K를 넘어가는 순간의 구간을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션
*/

int l[103000];

int main(void) {
    int n;
    long long k, t = 0;
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 1; i <= n; i++) {
        t += l[i];
        if (k < t) {
            printf("%d", i);
            return 0;
        }
    }
    for (int i = n; i >= 1; i--) {
        t += l[i];
        if (k < t) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}