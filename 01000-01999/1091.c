#include <stdio.h>

/*
문제 : N(N <= 48, 3의 배수)장의 카드가 있고, 이 카드를 3명에게 순서대로 분배한다.
이때, 카드를 섞는 방법과 목표 상태가 주어지면 카드를 주어진 방식으로 섞는 것을 반복하여
원하는 상태로 카드를 분배할 수 있는 지 구하고, 가능하다면 그렇게 하기 위해 섞어야 하는 최소 횟수를 구한다.
불가능하다면 -1을 출력한다.

해결 방법 : 모든 상태에서 많아야 수십-수백만 번 섞은 후에는 원래 상태로 돌아오게 된다. (증명 생략)
따라서, 원래 상태로 돌아올 때 까지 섞는 작업을 반복하며 목표 상태가 나오는 첫 횟수를 찾으면 된다.
원래 상태로 돌아올 때 까지 그러한 경우가 없다면 -1을 출력한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : SRM 415D2 3번
*/

int orig[64], cur[64], nxt[64], goal[64], shuf[64];

int compcard(int n, int* a, int* b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void shuffling(int n) {
    for (int i = 0; i < n; i++) nxt[i] = cur[shuf[i]];
    for (int i = 0; i < n; i++) cur[i] = nxt[i];
}

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &goal[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &shuf[i]);
    }
    for (int i = 0; i < n; i++) {
        orig[i] = i % 3;
        cur[i] = orig[i];
    }
    if (compcard(n, cur, goal)) {
        printf("0");
        return 0;
    }
    shuffling(n);
    while (!compcard(n, orig, cur)) {
        if (compcard(n, cur, goal)) {
            printf("%d", r);
            return 0;
        }
        shuffling(n);
        r++;
    }
    printf("-1");
    return 0;
}