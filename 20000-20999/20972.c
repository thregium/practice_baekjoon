#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * N(N <= 1000)크기의 사각형 안에 있는 모든 2 * 2 사각형에 소들이 2마리씩 있도록 소들을 배치하려 한다.
각 지점의 가치가 주어질 때, 소들이 있는 지점의 가치 합이 가장 크도록 배치했을 때의 가치를 구한다.

해결 방법 : 사각형 중 한 줄의 사각형들을 배치하면 그 다음 줄은 앞 줄과 완전히 반대로 배치해야 모든 2 * 2 사각형의 소들을 2마리씩 배치할 수 있다.
이를 반복하면 첫 두 줄의 배치를 반복하게 되고, 가로와 세로의 2가지 경우가 있다. 따라서, 가로와 세로에 각각 두 줄씩 반복한 값들을 놓고,
N개의 칸에 대해 더 큰 값을 고른 것을 각각 더하면, 가로와 세로의 경우에서 가장 큰 값을 얻을 수 있고, 둘 중 더 큰 값이 가장 큰 값이 된다.

주요 알고리즘 : 그리디 알고리즘, 애드 혹

출처 : USACO 2021J S3번
*/

int b[1024][1024], ver[2][1024], hor[1024][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("f.in", "r");
        fo = fopen("f.out", "w");
    }
    int n, v = 0, h = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
            ver[i & 1][j] += b[i][j];
            hor[i][j & 1] += b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        v += big(ver[0][i], ver[1][i]);
        h += big(hor[i][0], hor[i][1]);
    }
    printf("%d", big(v, h));
    return 0;
}