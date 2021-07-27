#include <stdio.h>

/*
문제 : N(N <= 20000)명중 5가지의 역할을 가장 잘 하는 사람을 뽑아야 한다. 이때, 한 사람이 여러 역할을 할 수는 없고,
각 역할은 한 사람씩만 할 수 있다. 각 사람의 5가지 역할에 대한 실력이 주어질 때, 실력의 합의 최고치를 구한다.

해결 방법 : 5가지의 역할을 비트마스킹을 통해 이미 뽑았는지 여부에 따른 최고치를 각각 저장한다.
각 사람의 능력치가 주어질 때 마다, 그 사람을 각 역할에 뽑아보고 최고치보다 높다면 최고치를 갱신한다.
이를 반복하고 N명이 전부 뽑히면 그때의 모든 사람을 뽑았을 때의 최고치를 출력하면 된다.

주요 알고리즘 : DP, 비트DP

출처 : POSTECH 2019 G번
*/

int mem[20480][32];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, a, b, c, d, e;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        for (int j = 0; j < 32; j++) {
            mem[i][j] = mem[i - 1][j];
            if (j & 1) mem[i][j] = big(mem[i][j], mem[i - 1][j ^ 1] + a);
            if (j & 2) mem[i][j] = big(mem[i][j], mem[i - 1][j ^ 2] + b);
            if (j & 4) mem[i][j] = big(mem[i][j], mem[i - 1][j ^ 4] + c);
            if (j & 8) mem[i][j] = big(mem[i][j], mem[i - 1][j ^ 8] + d);
            if (j & 16) mem[i][j] = big(mem[i][j], mem[i - 1][j ^ 16] + e);
        }
    }
    printf("%d", mem[n][31]);
    return 0;
}