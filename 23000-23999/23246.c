#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명의 클라이밍 선수들의 리드, 스피드, 볼더링 순위가 주어질 때 금, 은, 동메달을 받는 선수를 출력한다.
순위 곱이 낮은 순 -> 순위 합이 낮은 순 -> 등 번호가 낮은 순으로 순위가 정해진다.

해결 방법 : 문제에 주어진 조건대로 정렬한다.

주요 알고리즘 : 구현, 정렬

출처 : Seoul 2021I I번
*/

int player[128][4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int ax = *((int*)a + 1);
    int bx = *((int*)b + 1);
    int ay = *((int*)a + 2);
    int by = *((int*)b + 2);
    int az = *((int*)a + 3);
    int bz = *((int*)b + 3);
    if (ax * ay * az != bx * by * bz) return ax * ay * az > bx * by * bz ? 1 : -1;
    if (ax + ay + az != bx + by + bz) return ax + ay + az > bx + by + bz ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &player[i][0], &player[i][1], &player[i][2], &player[i][3]);
    }
    qsort(player, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < 3; i++) {
        printf("%d ", player[i][0]);
    }
    return 0;
}