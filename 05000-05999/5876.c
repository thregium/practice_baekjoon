#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * N(N <= 5) 크기의 '('과 ')'로 이루어진 배열이 있다. 이때, 이 배열에서 왼쪽 위 칸부터 움직이며
이루는 문자열이 완벽한 괄호를 이루는 가장 긴 경로의 길이를 구한다. 한 번 움직인 칸은 다시 돌아갈 수 없다.
완벽한 괄호는 모든 '('가 왼쪽에 나오고 모든 ')'가 오른쪽에 나오면서 '('와 ')'가 같은 문자열이다.

해결 방법 : (0, 0)에서부터 백트래킹을 통해 가장 긴 경로의 길이를 구한다.
만약 ')'가 한 번이라도 나온 이후 '('가 나오는 경우 탐색을 바로 종료한다. '('와 ')'가 같아지는 지점에서도
'(' + ')'의 개수가 결괏값보다 많은 경우 결괏값을 갱신하고 탐색을 종료한다. (이후로 완벽한 괄호를 만들 수 없음을 알 수 있다.)

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : USACO 2012N B3번
*/

char hshoe[8][8], vis[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, res = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void track(int x, int y, int p, int q) {
    if (hshoe[x][y] == '(') {
        if (q > 0) return;
        else p++;
    }
    else if (hshoe[x][y] == ')') q++;

    if (p == q) {
        if (p + q > res) res = p + q;
        return;
    }
    else if (p < q) return;

    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) track(x + dxy[i][0], y + dxy[i][1], p, q);
    }
    vis[x][y] = 0;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hshoe.in", "r");
        fo = fopen("hshoe.out", "w");
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", hshoe[i]);
    }
    track(0, 0, 0, 0);
    printf("%d", res);
    return 0;
}