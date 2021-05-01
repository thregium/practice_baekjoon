#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * N(N <= 10) 크기의 판에 서로 다른 직사각형 9개를 겹쳐 그렸을 때, 맨 밑에 있을 수 있는 직사각형의 최대 개수를 구한다.

해결 방법 : 가능한 모든 순서로 직사각형들을 그려본다. 그리는 동안 다른 직사각형 위에 겹쳐 그리지 않았다면 맨 밑에 있을 수 있는 직사각형이다.
전부 그린 다음 그림이 주어진 그림과 같다면 정확히 그린 그림이므로, 위에서 센 맨 밑의 직사각형 수를 최댓값과 비교해서 최댓값을 업데이트한다.
이를 모든 순서에 대해 반복해 최대 개수를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2017O B3번
*/

char paint[16][16], temp[16][16];
int rect[10][4], perm[9], vis[10];
int n, best = 0;

void npaint(void) {
    int p = 0, t, r = 1;
    for (int i = 0; i < 9; i++) {
        if (rect[perm[i]][1] < 0) continue;
        t = 0;
        for (int j = rect[perm[i]][0]; j <= rect[perm[i]][1]; j++) {
            for (int k = rect[perm[i]][2]; k <= rect[perm[i]][3]; k++) {
                if (temp[j][k] - '0') t++; //이미 다른 직사각형이 아래 있는 경우
                temp[j][k] = perm[i] + '0'; //새로운 그림 그리기
            }
        }
        if (!t) p++; //맨 밑의 직사각형이 될 수 있는 경우
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] != paint[i][j]) r = 0; //그림이 다른 경우
            temp[i][j] = '0';
        }
    }
    if (r && p > best) {
        best = p; //결과 업데이트
    }
}

void track(int x, int r) {
    //순서 트래킹
    if (r == x) {
        npaint();
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        perm[r] = i;
        track(x, r + 1);
        vis[i] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("art.in", "r");
        fo = fopen("art.out", "w");
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", paint[i]);
    }
    for (int i = 1; i <= 9; i++) {
        rect[i][0] = 11;
        rect[i][1] = -1;
        rect[i][2] = 11;
        rect[i][3] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paint[i][j] - '0' > 0) {
                //전처리(각 직사각형의 크기)
                if (i < rect[paint[i][j] - '0'][0]) rect[paint[i][j] - '0'][0] = i;
                if (i > rect[paint[i][j] - '0'][1]) rect[paint[i][j] - '0'][1] = i;
                if (j < rect[paint[i][j] - '0'][2]) rect[paint[i][j] - '0'][2] = j;
                if (j > rect[paint[i][j] - '0'][3]) rect[paint[i][j] - '0'][3] = j;
            }
            temp[i][j] = '0'; //전처리(임시 그림)
        }
    }
    track(9, 0);
    printf("%d", best);
    return 0;
}