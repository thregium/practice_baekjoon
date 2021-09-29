#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 1000)명이 있고, 각각은 F_i번 사람에게 연락을 한다. 이때, 연락을 이어나가다 루프가 생기지 않는 사람의 수를 구한다.
F_i가 0인 경우는 그 사람에서 연락이 끝나는 것이다.

해결 방법 : N명의 사람에 대해 각 사람이 연락을 하다가 이미 도달한 사람에게 다시 도달하는지 확인한다. 도달하지 않는 경우
결괏값에 1을 더한다. 이를 방문 배열을 초기화하며 반복하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : USACO 2013F B1번
*/

int mv[1024], vis[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("relay.in", "r");
        fo = fopen("relay.out", "w");
    }
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mv[i]);
    }
    for (int i = 1; i <= n; i++) {
        x = i;
        while (1) {
            vis[x] = 1;
            if (x == 0) {
                r += 1;
                break;
            }
            x = mv[x];
            if (vis[x]) break;
        }
        for (int j = 0; j <= n; j++) vis[j] = 0;
    }
    printf("%d", r);
    return 0;
}