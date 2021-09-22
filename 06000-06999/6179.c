#include <stdio.h>

/*
문제 : N(N <= 1080)개의 톱니바퀴가 있다. (0, 0)에 위치한 톱니바퀴를 돌릴 때, 마지막으로 돌아가는 톱니바퀴의 위치를 구한다.
단, 각 톱니바퀴는 최대 2개의 톱니바퀴와만 붙어있고, (0, 0)에 위치한 톱니바퀴와 마지막 톱니바퀴는 최대 1개의 톱니바퀴와만 붙어있다.

해결 방법 : (0, 0)부터 돌릴 수 있는 톱니바퀴를 찾아가며 차례로 다음 톱니바퀴를 돌린다. 한 톱니바퀴가 돌아갈 때,
새로 돌아가게 되는 톱니바퀴는 그 톱니바퀴와의 거리가 두 톱니의 지름 합과 같은 경우이고, 이는 피타고라스의 정리를 통해 거리를 찾은 다음
지름과 비교해 구할 수 있다. 마지막으로 돌아가는 톱니바퀴가 답이 된다.
이때, 톱니바퀴를 돌리면서 이미 돌렸던 톱니로 돌아가지 않도록 돌렸던 톱니바퀴는 방문 처리를 해줘야 한다.

주요 알고리즘 : 구현, 기하학, 시뮬레이션

출처 : USACO 2008M B3번
*/

int rollers[1280][3], driving[1280];

int sqr(int a) {
    return a * a;
}

int main(void) {
    int n, checking = -1, nxt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &rollers[i][0], &rollers[i][1], &rollers[i][2]);
        if (rollers[i][0] == 0 && rollers[i][1] == 0) {
            if (checking >= 0) return 1;
            checking = i;
            driving[i] = 1;
        }
    }
    if (checking < 0) return 2;
    for (int i = 1; i < n; i++) {
        nxt = -1;
        for (int j = 0; j < n; j++) {
            if (driving[j]) continue;
            if (sqr(rollers[j][0] - rollers[checking][0]) + sqr(rollers[j][1] - rollers[checking][1]) == sqr(rollers[j][2] + rollers[checking][2])) {
                if (nxt >= 0) return 3;
                nxt = j;
                driving[j] = 1;
            }
        }
        checking = nxt;
    }
    printf("%d %d", rollers[checking][0], rollers[checking][1]);
    return 0;
}