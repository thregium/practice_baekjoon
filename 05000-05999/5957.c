#include <stdio.h>

/*
문제 : N(N <= 10000)개의 접시가 3개의 더미 가운데 첫 더미에 높은 번호부터 차례로 쌓여있다.
C_i번 줄의 더미에서 위의 D_i개의 접시를 역순으로 옆 줄에 쌓는 것을 반복해 3번째 더미에 모든 접시가 쌓였을 때의
3번째 더미의 순서를 출력한다. 단, 접시가 없을 때 쌓는 경우는 없음이 보장된다.

해결 방법 : 각 접시 더미를 스택으로 구현한 다음, 더미를 역순으로 쌓는 것을 앞쪽 더미에서 pop()한 것을 뒤쪽 더미로 push()하는
것을 D_i회 반복하는 식으로 구현하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 스택

출처 : USACO 2011J B2번
*/

int dishes[3][10240];
int sz[3];

int main(void) {
    int n, ci, di, t;
    scanf("%d", &n);
    sz[0] = n;
    for (int i = 0; i < n; i++) {
        dishes[0][i] = n - i;
    }
    while (1) {
        scanf("%d %d", &ci, &di);
        if (sz[ci - 1] < di) return 1;
        for (int i = 0; i < di; i++) {
            t = dishes[ci - 1][--sz[ci - 1]];
            dishes[ci][sz[ci]++] = t;
        }
        if (sz[2] == n) {
            for (int i = n - 1; i >= 0; i--) {
                printf("%d\n", dishes[2][i]);
            }
            break;
        }
    }
    return 0;
}