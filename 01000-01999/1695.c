#include <stdio.h>

/*
문제 : N(N <= 5000) 길이의 배열이 있을 때, 이 배열을 팰린드롬으로 만들기 위해 넣어야 하는 원소의 최소 개수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 이용한다. 전체 범위에서 시작해서 범위의 양 끝을 확인한다.
양 끝이 같은 글자라면 넣을 필요가 없고, 다른 글자라면 왼쪽 또는 오른쪽에 새 글자를 넣는 방법 중 더 좋은 것을 고르면 된다.
글자 수가 1개 이하가 되면 답은 0임을 기저 사례로 활용한다.

주요 알고리즘 : DP
*/

int a[5120], mem[5120][5120];

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int s, int e) {
    if (s >= e) return mem[s][e] = 0;
    if (mem[s][e] >= 0) return mem[s][e];
    if (a[s] == a[e]) return mem[s][e] = dp(s + 1, e - 1);
    else return mem[s][e] = small(dp(s + 1, e), dp(s, e - 1)) + 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < n; j++) mem[i][j] = -1;
    }
    printf("%d", dp(0, n - 1));
    return 0;
}