#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : 수직선상에 N(N <= 10^6)개의 1 또는 0이 있다. 각 1 또는 0의 좌표는 10^9 이하의 음이 아닌 정수이며 서로 겹치지 않을 때,
시점과 종점에 1 또는 0이 있으면서 구간 내에 있는 1과 0의 수가 같고 가장 시점과 종점의 차이가 큰 구간의 길이를 구한다.

해결 방법 : 각 1과 0의 위치를 정렬한 다음, 변수를 특정한 값(100만 이상의 자연수)으로 설정한다.
그 후, 1이 나오면 변수를 1 올리고 0이 나오면 1 낮추는 것을 반복하며 각 수마다 나오는 첫 위치와 마지막 위치를 각자 확인한다.
이때, 첫 위치는 변수를 바꾸기 전에 확인하고 마지막 위치는 변수를 바꾼 다음 확인해야 한다.
확인한 다음에는 모든 수(초기값 - 100만 ~ 초기값 + 100만)에 대해 첫 위치와 마지막 위치의 차이가 가장 큰 곳의
두 위치 차이를 구해서 그 값을 출력하면 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2007M S2번
*/

int a[1048576][2], front[1048576 * 2], back[1048576 * 2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s = 1048576, r = -1;
    //freopen("E:\\PS\\Olympiad\\USA\\2_Silver\\2007_03\\USACO 2007 March\\allmar07\\balance.10.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][1], &a[i][0]);
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < 1048576 * 2; i++) {
        front[i] = INF;
        back[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] < front[s]) front[s] = a[i][0];
        if (a[i][1]) s++;
        else s--;
        if (a[i][0] > back[s]) back[s] = a[i][0];
    }
    for (int i = 0; i < 1048576 * 2; i++) {
        if (back[i] - front[i] > r) r = back[i] - front[i];
    }
    if (r <= 0) return 1;
    printf("%d", r);
    return 0;
}