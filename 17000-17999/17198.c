#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 10 * 10 크기의 격자에 서로 다른 세 지점 B, R, L이 있다고 한다.
격자가 주어질 때 B에서 L로 최단거리로 지나갈 때 지나가야 하는 칸의 수를 출력한다. 단, B와 L은 포함하지 않는다. 또한, R이 있는 지점으로는 갈 수 없다.

해결 방법 : 격자에서 B, R, L의 좌표를 각각 찾는다. 만약 R이 수평이나 수직으로 B와 L 사이에 있는 경우 2칸 우회해야 하고,
그렇지 않은 경우 최단경로로 갈 수 있다. 최단 거리는 두 좌표의 절대값의 차이로 구할 수 있다. 여기서는 양 끝을 포함하지 않으므로 그 값에서 1이 줄어든다.

주요 알고리즘 : 구현, 케이스 워크

출처 : USACO 2019O B1번
*/

char map[16][16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("buckets.in", "r");
        fo = fopen("buckets.out", "w");
    }
    int bx = -1, by = -1, rx = -1, ry = -1, lx = -1, ly = -1;
    for (int i = 0; i < 10; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'B') {
                bx = i;
                by = j;
            }
            if (map[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (map[i][j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }
    if ((bx == lx && bx == rx && ((ry < by && ry > ly) || (ry > by && ry < ly))) || (by == ly && by == ry && ((rx < bx && rx > lx) || (rx > bx && rx < lx)))) {
        //L, R, B가 모두 직선상에 있으면서, R이 L과 B 사이에 있는 경우 (이렇게 쓰지 말자)
        printf("%d", abs(bx - lx) + abs(by - ly) + 1); //2칸 우회해야 한다.
    }
    else {
        printf("%d", abs(bx - lx) + abs(by - ly) - 1); //최단 경로로 갈 수 있다.
    }
    return 0;
}