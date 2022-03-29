#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 N(N <= 100000)이 주어질 때, 1을 더하거나 곱하거나 이어붙이는 연산만을 사용하여
N을 만들 때, N을 만들기 위해 필요한 1의 개수의 최솟값을 구한다. (제한시간 15초)
단, 이어붙이는 경우 뒤쪽 수는 0으로 시작할 수 없다.

해결 방법 : 다이나믹 프로그래밍을 통해 답을 구할 수 있다. N이 1인 경우 답을 1로 하고,
그보다 큰 값인 경우에는 더하거나 곱하거나 이어붙이는 모든 경우를 시도해 보며
답을 찾아나간다. 제한시간이 길기 때문에 더하는 과정을 전부 시도해봐도 상관 없다.
이어붙이는 경우 뒤쪽 수가 0으로 시작하지 않도록 주의한다.

주요 알고리즘 : DP

출처 : ECNA 2021 A번
*/

int mem[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int getres(int x) {
    if (mem[x]) return mem[x];
    else if (x == 1) return mem[x] = 1;
    else if (x < 1) exit(1);

    int res = 103000, flag = 0;
    for (int i = x / 10, j = x % 10, k = 10; i;) {
        if (j > 0 && !flag) res = small(res, getres(i) + getres(j));
        j += k * (i % 10);
        if (i % 10) flag = 0;
        else flag = 1;
        i /= 10;
        k *= 10;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = small(res, getres(i) + getres(x / i));
        }
    }
    for (int i = 1; i <= x - i; i++) {
        res = small(res, getres(i) + getres(x - i));
    }
    return mem[x] = res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", getres(n));
    return 0;
}