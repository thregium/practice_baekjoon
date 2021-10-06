#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * N(N <= 18) 크기의 판에 대문자들이 쓰여 있다. 가장 왼쪽 위 칸에서 출발하여 오른쪽 또는 아래쪽으로 이동하며
나온 문자열들 중 팰린드롬인 것의 가짓수를 구한다. 경로가 다르더라도 문자열이 같다면 같은 것이다.

해결 방법 : 직접 왼쪽 위에서 오른쪽 아래까지 이동하면 가짓수가 지나치게 많아지므로 시간 초과가 나올 것이다.
따라서, 가운데 칸(/방향의 대각선에 있는 칸)들에서 출발하여 왼쪽 위 칸과 오른쪽 아래 칸으로 이동한다.
그러면 나올 수 있는 가짓수는 많아야 2^17가지에 불과하므로 최악의 경우도 해결 가능하다.

각 이동 후 두 이동에서 나온 문자열들을 각각 정렬한다. 그 다음, 이분 탐색을 이용해 첫 번째 이동에서 나온
문자열 가운데 두 번째 이동에서도 존재하는 문자열들을 결과 배열에 옮긴다.
위 내용을 각 가운데 칸에 대해 반복한 다음, 결과 배열을 정렬하고 겹치는 문자열들을 제외한 문자열들의 개수를 세면 답이 된다.

주요 알고리즘 : 문자열, 밋 인 더 미들, 이분 탐색

출처 : USACO 2015O B4번
*/

char field[32][32], tpath[32], path1[103000][20], path2[103000][20], pal[262144][20];
int p1p = 0, p2p = 0;

void track1(int n, int x, int y, int pi) {
    tpath[pi] = field[x][y];
    if (x > 0) track1(n, x - 1, y, pi + 1);
    if (y > 0) track1(n, x, y - 1, pi + 1);
    if (x == 0 && y == 0) {
        strcpy(path1[p1p], tpath);
        p1p++;
    }
    tpath[pi] = '\0';
}

void track2(int n, int x, int y, int pi) {
    tpath[pi] = field[x][y];
    if (x < n - 1) track2(n, x + 1, y, pi + 1);
    if (y < n - 1) track2(n, x, y + 1, pi + 1);
    if (x == n - 1 && y == n - 1) {
        strcpy(path2[p2p], tpath);
        p2p++;
    }
    tpath[pi] = '\0';
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("palpath.in", "r");
        fo = fopen("palpath.out", "w");
    }
    int n, pp = 0, r = 0;
    void* v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", field[i]);
    }
    for (int i = 0; i < n; i++) {
        p1p = 0, p2p = 0;
        track1(n, i, n - i - 1, 0);
        track2(n, i, n - i - 1, 0);
        if (p1p > 100000 || p2p > 100000) return 1;
        qsort(path1, p1p, sizeof(char) * 20, strcmp);
        qsort(path2, p2p, sizeof(char) * 20, strcmp);
        for (int j = 0; j < p1p; j++) {
            if (j > 0 && !strcmp(path1[j], path1[j - 1])) continue;
            v = bsearch(path1[j], path2, p2p, sizeof(char) * 20, strcmp);
            if (v) {
                strcpy(pal[pp], path1[j]);
                pp++;
            }
        }
    }
    qsort(pal, pp, sizeof(char) * 20, strcmp);
    for (int i = 0; i < pp; i++) {
        if (i > 0 && !strcmp(pal[i], pal[i - 1])) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}