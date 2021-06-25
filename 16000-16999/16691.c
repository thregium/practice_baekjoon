#include <stdio.h>

/*
문제 : 자연수 M(M <= 10^6)이 주어질 때, M부터 X - 1까지의 합이 X + 1부터 N까지의 합과 같도록 하는 가장 작은 N을 구한다.
단, 모든 N은 1000만 이하에서 나온다.

해결 방법 : 등차수열의 합 공식을 이용해 합을 빠르게 구하도록 한다. N과 X를 각각 M + 2, M + 1부터 차례대로 움직이면서
X + 1부터 N까지의 합이 M부터 X - 1까지의 합보다 작다면 N의 값을 올린다. 이때 합이 같아지는 지점이 생긴다면
해당하는 수들을 출력하고 프로그램을 종료하면 된다.

주요 알고리즘 : 수학, 투 포인터

출처 : PacNW 2018 R번
*/

long long sigma(long long a, long long b) {
    return ((b - a + 1) * (a + b)) >> 1;
}

int main(void) {
    int m, n;
    scanf("%d", &m);
    n = m + 2;
    for (int i = m + 1;; i++) {
        while (sigma(m, i - 1) > sigma(i + 1, n)) n++;
        if (sigma(m, i - 1) == sigma(i + 1, n)) {
            printf("%d %d %d", m, i, n);
            return 0;
        }
    }
    return 0;
}
