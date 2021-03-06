#include <stdio.h>
#define DIV 9901

/*
문제 : 2 * N(N <= 100000) 크기의 우리가 있을 때, 사자들을 가로로도 세로로도 인접하지 않도록
배치하는 경우의 수를 구한다. 사자는 몇 마리가 되어도 상관 없다.

해결 방법 : 각 줄 마다 사자를 배치하는 방법은 사자가 위쪽, 아래쪽 중 한 칸에 있거나 해당 줄에 없는 3 가지이다.
사자가 있는 경우에는 이전 줄에도 같은 위치에 사자가 있다면 배치할 수 없고, 없는 경우에는 제약이 없다.
이를 다이나믹 프로그래밍으로 점화식을 구해 풀면 된다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int mem[102400][4];

int main(void) {
    int n;
    scanf("%d", &n);
    mem[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        mem[i][0] = (mem[i - 1][0] + mem[i - 1][1] + mem[i - 1][2]) % DIV;
        mem[i][1] = (mem[i - 1][0] + mem[i - 1][2]) % DIV;
        mem[i][2] = (mem[i - 1][0] + mem[i - 1][1]) % DIV;
    }
    printf("%d", (mem[n][0] + mem[n][1] + mem[n][2]) % DIV);
    return 0;
}