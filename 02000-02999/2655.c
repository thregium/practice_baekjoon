#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 벽돌에 대해 넓이와 무게, 높이가 주어진다. 넓이와 무게는 각각 모두 다르고, 넓이와 무게가
감소하는 순으로 벽돌을 쌓을 때 높이가 가장 높도록 벽돌을 쌓는 방법을 출력한다.

해결 방법 : 각 벽돌을 넓이에 대해 내림차순으로 정렬한 다음, 각 번째의 벽돌에 대해 이전 무게의 값이 더 무거운
것들 가운데 가장 높이가 높은 것을 기준으로 DP를 진행한다. 전부 끝난 다음,
가장 높이가 높은 곳 부터 역순으로 방법을 찾아나가면 된다.

주요 알고리즘 : DP, 역추적, 정렬

출처 : 정올 1998 중3번
*/

int brick[128][4], mem[128], last[128], build[128];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0, p;
    scanf("%d", &n);
    brick[0][0] = 103000, brick[0][2] = 103000;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &brick[i][0], &brick[i][1], &brick[i][2]);
        brick[i][3] = i;
    }
    qsort(brick + 1, n, sizeof(int) * 4, cmp1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (brick[j][2] > brick[i][2]) {
                if (mem[j] + brick[i][1] > mem[i]) {
                    mem[i] = mem[j] + brick[i][1];
                }
            }
        }
    }

    p = 0;
    for (int i = 1; i <= n; i++) {
        if (mem[i] > mem[p]) p = i;
    }
    while (mem[p]) {
        build[r++] = brick[p][3];
        if (r > 1 && build[r - 1] == build[r - 2]) return 1;
        for (int i = p - 1; i >= 0; i--) {
            if (mem[i] + brick[p][1] == mem[p] && brick[i][2] > brick[p][2]) {
                p = i;
                break;
            }
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d\n", build[i]);
    }
    return 0;
}