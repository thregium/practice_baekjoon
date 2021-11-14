#include <stdio.h>

/*
문제 : N(N <= 100000)의 길이에서 M(M <= N)개의 점이 있다.
0 이상 N 이하의 모든 구간을 포함하기 위한 M에서의 최소 거리는 몇인지 구한다.
모든 점의 위치는 0 이상 N 이하며 중복되지 않고 오름차순으로 주어진다.

해결 방법 : 양 끝의 거리 가운데 큰 값 또는 모든 점 사이의 거리 가운데 가장 큰 값 / 2 가운데 더 큰 값을 찾으면 된다.
수를 입력받으며 값을 찾아나가면 된다.

주요 알고리즘 : 그리디 알고리즘?, 스위핑

출처 : 인하대 2019 D번
*/

int pos[103000];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &pos[i]);
    }
    r = n - pos[m - 1];
    r = big(r, pos[0]);
    for (int i = 1; i < m; i++) {
        r = big(r, (pos[i] - pos[i - 1] + 1) >> 1);
    }
    printf("%d", r);
    return 0;
}