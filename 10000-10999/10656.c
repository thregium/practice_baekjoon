#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * M(N, M <= 50) 크기의 십자말풀이가 있다. 이 십자말풀이에서 단서가 있는 칸의 개수와 각각의 위치를 출력한다.
단서가 있는 칸은 가로 또는 세로로 이전 칸이 막혀있고 이후로 2칸 이상이 비어있는 경우이다.
각 위치는 가로->세로 순으로 오름차순이 되어야 한다.

해결 방법 : 문제에 주어진대로 구현한다. 각 행 -> 열 단위로 탐색하고 단서가 있을 수 있는지 구하면 된다.

주요 알고리즘 : 구현

출처 : USACO 2014D B2번
*/

char cw[64][64];
int clue[4096][2];
int cp = 0;

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crosswords.in", "r");
        fo = fopen("crosswords.out", "w");
    }
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", cw[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cw[i][j] == '#') continue;
            if (((j == 0 || cw[i][j - 1] == '#') && (cw[i][j + 1] == '.') && (cw[i][j + 2] == '.'))
                || ((i == 0 || cw[i - 1][j] == '#') && (cw[i + 1][j] == '.') && (cw[i + 2][j] == '.'))) {
                clue[cp][0] = i + 1;
                clue[cp++][1] = j + 1;
            }
        }
    }
    printf("%d\n", cp);
    for (int i = 0; i < cp; i++) {
        printf("%d %d\n", clue[i][0], clue[i][1]);
    }
    return 0;
}