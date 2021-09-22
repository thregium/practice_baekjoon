#include <stdio.h>

/*
문제 : N(N <= 5000)개의 정수로 이루어진 수열이 주어질 때, 가장 긴 증가하는 부분수열의 길이를 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결할 수 있다. 각 수로 끝날 때의 길이를 저장한 다음,
현재 수보다 작은 앞의 수들 가운데 가장 길이가 긴 수열의 뒤에 붙이면 된다.

주요 알고리즘 : DP

출처 : USACO 2006X 5번
*/

int cows[5120], mem[5120];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cows[i]);
    }
    for (int i = 1; i <= n; i++) {
        mem[i] = 1;
        for (int j = 1; j < i; j++) {
            if (cows[j] < cows[i] && mem[j] + 1 > mem[i]) mem[i] = mem[j] + 1;
        }
        if (mem[i] > r) r = mem[i];
    }
    printf("%d", r);
    return 0;
}