#include <stdio.h>

/*
문제 : N(N <= 10000)분동안 차량이 터널을 통과한 기록이 주어진다. 처음 차량의 수는 M대이다. 각 분마다 차량이 터널에
진입과 진출한 기록이 주어지면 가장 차량이 많았을 때 차량의 수를 구한다.
단, 있을 수 없는 경우(차량의 수가 음수가 되는 경우)에는 0을 출력한다.

해결 방법 : M에서 시작하여 매 분마다 진입 - 진출한 차수를 현재 차수에 더해주며 가장 차량의 수가 많을 때를 구한다.
이때, 차량의 수가 음수가 되면 즉시 0을 출력하고 프로그램을 종료해야 한다.

주요 알고리즘 : 구현

출처 : JOI 2006모2 1번
*/

int main(void) {
    int n, m, in, ou, r = 0;
    scanf("%d%d", &n, &m);
    r = m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &in, &ou);
        m += in - ou;
        if (m < 0) {
            printf("0");
            return 0;
        }
        if (m > r) r = m;
    }
    printf("%d", r);
    return 0;
}