#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 500)개의 길이 L(L <= 20000)의 정렬된 문자열 가운데 정렬된 순서가 되는 가장 짧은 구간을 구한다.
단, 해당 구간에서 정렬했을 때 같은 값이 있어서는 안 된다.

해결 방법 : 인접한 2개씩의 문자열을 비교해봐서 모두가 정렬된 상태면 정렬된 순서이다.
따라서, 다이나믹 프로그래밍을 통해 모든 인접한 쌍과 시작 지점에 대해 정렬된 상태를 만드는 가장 가까운 지점을 찾는다.
(이때, 역정렬된 부분은 무한대로 초기화한다.) 그 다음으로 각 시작점에 대해 가장 가까운 지점이 가장 먼 곳을 찾으면
그 곳이 해당 시작점에서 정렬된 순서가 되는 가장 짧은 구간이다. 이를 모든 시작점에 대해 구하고 가장 짧은 것을 구하면 된다.

주요 알고리즘 : 문자열, DP

출처 : GCPC 2020 L번
*/

char names[512][20480];
int mem[512][20480];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, l, s = 0, e = 100000, t;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    for (int i = 1; i < n; i++) {
        mem[i][l] = INF;
        for (int j = l - 1; j >= 0; j--) {
            if (names[i][j] > names[i - 1][j]) mem[i][j] = j;
            else if (names[i][j] == names[i - 1][j]) mem[i][j] = mem[i][j + 1];
            else mem[i][j] = INF;
        }
    }
    for (int i = 0; i < l; i++) {
        t = 0;
        for (int j = 1; j < n; j++) {
            t = big(t, mem[j][i]);
        }
        if (t - i < e - s) {
            s = i;
            e = t;
        }
    }
    printf("%d %d", s + 1, e + 1);
    return 0;
}