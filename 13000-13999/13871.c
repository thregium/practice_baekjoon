#include <stdio.h>

/*
문제 : 원형으로 놓인 N(N <= 100)개의 기둥이 있고, 로봇이 1번 기둥에 있다. C(C <= 1000)번의 시계방향 또는 반시계방향으로
1칸 이동하는 명령을 수행하는 동안 S번 기둥에 도달하는 횟수가 몇 번인지 구한다.
단, 시작과 끝에 S번 기둥에 도달하는 것도 센다.

해결 방법 : 먼저 S번 기둥에 있다면 결괏값을 1로 올린다. 그리고 C번동안 명령을 확인한 후 시계방향 이동인 경우 번호에 1을 더하고.
반시계방향 이동인 경우 번호에 1을 뺀다. 기둥 번호가 0이 되면 N번으로, N + 1이 되면 1번으로 이동한다.
이동할 때 마다 S번 기둥인 경우 결괏값에 1을 더한다. 전부 이동한 다음 결괏값을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Latin 2016 F번
*/

int main(void) {
    int n, c, s, x, p = 1, r = 0;
    scanf("%d %d %d", &n, &c, &s);
    if (p == s) r++;
    for (int i = 0; i < c; i++) {
        scanf("%d", &x);
        p += x;
        if (p < 1) p = n;
        else if (p > n) p = 1;
        if (p == s) r++;
    }
    printf("%d", r);
    return 0;
}