#include <stdio.h>

/*
문제 : 10000 이하의 세 자연수 N, M, T가 주어질 때, AN + BM + C = T를 만족시키는 음이 아닌 정수 A, B, C 가운데
C를 가장 적게 하고, C가 같다면 A + B를 가장 크게 하는 경우의 A + B와 C의 값을 구한다.

해결 방법 : A로 가능한 모든 경우에 대해 B를 최대한 크게 하고 C를 살펴본다.
이때의 A와 B, C를 이용해 C가 작은 것, 같다면 A + B가 큰 것을 구하고, 그때의 A + B, C를 출력하면 된다.

주요 알고리즘 : 수학, 브루트 포스
*/

int main(void) {
    int n, m, t, res, rh = 0, x;
    scanf("%d %d %d", &n, &m, &t);
    res = t;
    for (int i = t / n; i >= 0; i--) {
        x = (t - i * n) / m;
        if (t - i * n - x * m < res) {
            res = t - i * n - x * m;
            rh = x + i;
        }
        else if (t - i * n - x * m == res) {
            if (x + i > rh) rh = x + i;
        }
    }
    printf("%d %d", rh, res);
    return 0;
}