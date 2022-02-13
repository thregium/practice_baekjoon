#include <stdio.h>

/*
문제 : 2019개의 칸으로 되어있는 판에 N(N <= 100)개의 말이 있다. 각 말의 위치는 서로 다르다.
M(M <= 100)번의 이동 후 각 말의 위치를 구한다.
각 이동은 A_i번째의 말을 앞으로 1칸 이동시키는 명령으로 구성된다.
단, 말이 2019번 칸에 있거나 앞 칸에 말이 있는 경우 이동하지 않는다.

해결 방법 : 각 말의 위치를 저장하고 1칸씩 옮기는 과정을 시뮬레이션한 후 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JOI 2019예 2번
*/

int x[128];

int main(void) {
    int n, m, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        if (x[a] == 2019 || x[a + 1] == x[a] + 1) continue;
        else x[a]++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", x[i]);
    }
    return 0;
}