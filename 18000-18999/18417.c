#include <stdio.h>
#define INF 1012345678

/*
문제 : N * N(N <= 500) 크기의 두 배열이 주어질 때, 첫번째 배열을 두번째 배열로 바꾸기 위해
필요한 최소 연산 횟수를 구한다.
1. 배열의 특정 원소를 원하는 값으로 바꾼다.
2. 배열을 왼쪽으로 90도 돌린다. 3. 배열을 오른쪽으로 90도 돌린다.

해결 방법 : 배열을 돌리지 않는다면 답은 두 배열의 다른 원소 개수이다.
배열을 돌리는 경우는 최대 4가지이므로 4가지 모든 경우를 고려해보고 그 중 가장 작은 것을 고르면 된다.

주요 알고리즘 : 구현?

출처 : JOI 2020예2 1번
*/

char s[512][512], t[512][512], p[512][512], tmp[512][512];

int small(int a, int b) {
    return a < b ? a : b;
}

int getdiff(int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r += (t[i][j] != p[i][j]);
        }
    }
    return r;
}

void rotl(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[n - j - 1][i] = p[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) p[i][j] = tmp[i][j];
    }
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; j++) p[i][j] = s[i][j];
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", t[i]);
    }
    r = small(r, getdiff(n));
    rotl(n);
    r = small(r, getdiff(n) + 1);
    rotl(n);
    r = small(r, getdiff(n) + 2);
    rotl(n);
    r = small(r, getdiff(n) + 1);
    printf("%d\n", r);
    return 0;
}