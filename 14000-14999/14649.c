#include <stdio.h>

/*
문제 : 100개의 돌로 이루어진 일렬로 된 징검다리가 있고, N(N <= 100)명이 왼쪽 또는 오른쪽을 보고 서 있다.
각 돌을 밟은 횟수를 3으로 나눈 나머지가 0, 1, 2가 되는 돌의 개수를 각각 구한다.

해결 방법 : 각 위치에서 출발해 이동을 시뮬레이션하며 각 돌을 밟은 횟수를 직접 세면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 선린 1회 E번
*/

int stones[128], cnt[4];

int main(void) {
    int p, n, s;
    char d;
    scanf("%d%d", &p, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &s, &d);
        if (d == 'L') {
            for (int j = s - 1; j > 0; j--) {
                stones[j]++;
            }
        }
        else {
            for (int j = s + 1; j <= 100; j++) {
                stones[j]++;
            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        cnt[stones[i] % 3]++;
    }
    for (int i = 0; i < 3; i++) {
        printf("%.2f\n", p / 100.0 * cnt[i]);
    }
    return 0;
}