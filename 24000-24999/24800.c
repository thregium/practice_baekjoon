#include <stdio.h>

/*
문제 : N(N <= 100)명의 사람이 S(S <= 100)음절 코코넛 게임을 한다. 처음에는 각 사람이 1손으로 시작하고,
S번째 사람은 처음에는 손을 2개로 바꾸고, 그 후로 그 손이 2번 더 불리면 그 손을 접는다.
마지막으로 남은 사람의 번호를 구한다.

해결 방법 : 문제에 주어진대로 구현한다. 손 위치의 변화에 주의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : VTH 2017 H번
*/

int hand[256];

int main(void) {
    int s, n, rem, x = -1, last = -1, end = 0;
    scanf("%d %d", &s, &n);
    for (int i = 0; i < n; i++) hand[i * 2] = 1;
    while (end < n * 2) {
        rem = s;
        while (rem) {
            x = (x + 1) % (n * 2);
            if (hand[x] == 0) continue;
            rem--;
        }
        last = x;
        if (hand[x] == 1) {
            hand[x] = 2, hand[x + 1] = 2;
            x--;
        }
        else if (hand[x] == 2) hand[x] = 3;
        else if (hand[x] == 3) {
            end++;
            hand[x] = 0;
        }
    }
    printf("%d", (last >> 1) + 1);
    return 0;
}