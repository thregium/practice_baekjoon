#include <stdio.h>

/*
문제 : N(N <= 1000)개의 계산대가 있고 C(C <= 1000)명의 손님이 있다. 손님들은 가장 먼저 끝나는 계산대 가운데
가장 앞쪽 계산대로 간다고 할 때, 각 손님의 계산 시간이 주어지면 각 손님들이 가는 계산대의 번호를 구한다.

해결 방법 : 문제 그대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : PacNW 2018 S번
*/

int cashier[1024];

int main(void) {
    int n, c, t, fastest, fi;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &t);
        fi = -1;
        fastest = 987654321;
        for (int j = 0; j < n; j++) {
            if (cashier[j] < fastest) {
                fastest = cashier[j];
                fi = j;
            }
        }
        printf("%d ", fi + 1);
        cashier[fi] += t;
    }
    return 0;
}