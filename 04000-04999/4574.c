#include <stdio.h>

char buff1[4], buff2[4];
long long dominos[16][16], puzzle[9][9], row[9][10], col[9][10], box[3][3][10];
int res = 0;

/*
문제 : 스도쿠 판에 1 ~ 9까지의 수가 각각 적혀있고, 나머지 칸을 도미노로 채우려 한다. 도미노는 1, 2부터 8, 9까지 서로 다른 두 수가 적혀 있는
것이 한 종류씩 있고, 이미 채워져 있는 도미노가 있을 수 있다. 나머지 규칙은 일반 스도쿠와 같다면 남은 칸을 채운 결과를 구한다.
단, 모든 문제의 정답은 하나뿐이다.

해결 방법 : 일반적인 스도쿠와 비슷한 방식으로 백트래킹을 통해 풀 수 있다. 칸을 순서대로 채우는 방식과 조금 느리지만 비교적 간단한 방식인
도미노를 순서대로 채우는 방식이 있다. 이 코드에서는 후자를 사용하였다.

주요 알고리즘 : 구현, 백트래킹

출처 :MidC 2011 D번
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void track(int d1, int d2) {
    while (dominos[d1][d2] || d2 > 9) {
        d2++;
        if (d2 > 9) {
            d1++;
            d2 = d1 + 1;
        }
        if (d1 >= 9) {
            res = 1;
            return;
        }
    }
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 8; y++) {
            if (puzzle[x][y] || puzzle[x][y + 1]) continue;
            if (!row[x][d1] && !row[x][d2] && !col[y][d1] && !col[y + 1][d2] && !box[x / 3][y / 3][d1] && !box[x / 3][(y + 1) / 3][d2]) {
                puzzle[x][y] = d1, puzzle[x][y + 1] = d2;
                row[x][d1] = 1, row[x][d2] = 1, col[y][d1] = 1, col[y + 1][d2] = 1, box[x / 3][y / 3][d1] = 1, box[x / 3][(y + 1) / 3][d2] = 1;
                track(d1, d2 + 1);
                if (res) return;
                row[x][d1] = 0, row[x][d2] = 0, col[y][d1] = 0, col[y + 1][d2] = 0, box[x / 3][y / 3][d1] = 0, box[x / 3][(y + 1) / 3][d2] = 0;
                puzzle[x][y] = 0, puzzle[x][y + 1] = 0;
            }
            if (!row[x][d1] && !row[x][d2] && !col[y][d2] && !col[y + 1][d1] && !box[x / 3][y / 3][d2] && !box[x / 3][(y + 1) / 3][d1]) {
                puzzle[x][y] = d2, puzzle[x][y + 1] = d1;
                row[x][d1] = 1, row[x][d2] = 1, col[y][d2] = 1, col[y + 1][d1] = 1, box[x / 3][y / 3][d2] = 1, box[x / 3][(y + 1) / 3][d1] = 1;
                track(d1, d2 + 1);
                if (res) return;
                row[x][d1] = 0, row[x][d2] = 0, col[y][d2] = 0, col[y + 1][d1] = 0, box[x / 3][y / 3][d2] = 0, box[x / 3][(y + 1) / 3][d1] = 0;
                puzzle[x][y] = 0, puzzle[x][y + 1] = 0;
            }
        }
    }
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 9; y++) {
            if (puzzle[x][y] || puzzle[x + 1][y]) continue;
            if (!row[x][d1] && !row[x + 1][d2] && !col[y][d1] && !col[y][d2] && !box[x / 3][y / 3][d1] && !box[(x + 1) / 3][y / 3][d2]) {
                puzzle[x][y] = d1, puzzle[x + 1][y] = d2;
                row[x][d1] = 1, row[x + 1][d2] = 1, col[y][d1] = 1, col[y][d2] = 1, box[x / 3][y / 3][d1] = 1, box[(x + 1) / 3][y / 3][d2] = 1;
                track(d1, d2 + 1);
                if (res) return;
                row[x][d1] = 0, row[x + 1][d2] = 0, col[y][d1] = 0, col[y][d2] = 0, box[x / 3][y / 3][d1] = 0, box[(x + 1) / 3][y / 3][d2] = 0;
                puzzle[x][y] = 0, puzzle[x + 1][y] = 0;
            }
            if (!row[x][d2] && !row[x + 1][d1] && !col[y][d1] && !col[y][d2] && !box[x / 3][y / 3][d2] && !box[(x + 1) / 3][y / 3][d1]) {
                puzzle[x][y] = d2, puzzle[x + 1][y] = d1;
                row[x][d2] = 1, row[x + 1][d1] = 1, col[y][d1] = 1, col[y][d2] = 1, box[x / 3][y / 3][d2] = 1, box[(x + 1) / 3][y / 3][d1] = 1;
                track(d1, d2 + 1);
                if (res) return;
                row[x][d2] = 0, row[x + 1][d1] = 0, col[y][d1] = 0, col[y][d2] = 0, box[x / 3][y / 3][d2] = 0, box[(x + 1) / 3][y / 3][d1] = 0;
                puzzle[x][y] = 0, puzzle[x + 1][y] = 0;
            }
        }
    }
}

int main(void) {
    int n, x, y;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %s %d %s", &x, buff1, &y, buff2);
            puzzle[buff1[0] - 'A'][buff1[1] - '1'] = x;
            row[buff1[0] - 'A'][x] = 1;
            col[buff1[1] - '1'][x] = 1;
            box[(buff1[0] - 'A') / 3][(buff1[1] - '1') / 3][x] = 1;
            puzzle[buff2[0] - 'A'][buff2[1] - '1'] = y;
            row[buff2[0] - 'A'][y] = 1;
            col[buff2[1] - '1'][y] = 1;
            box[(buff2[0] - 'A') / 3][(buff2[1] - '1') / 3][y] = 1;
            if (y < x) swap(&x, &y);
            dominos[x][y] = 1;
        }
        for (int i = 1; i <= 9; i++) {
            scanf("%s", buff1);
            puzzle[buff1[0] - 'A'][buff1[1] - '1'] = i;
            row[buff1[0] - 'A'][i] = 1;
            col[buff1[1] - '1'][i] = 1;
            box[(buff1[0] - 'A') / 3][(buff1[1] - '1') / 3][i] = 1;
        }

        res = 0;
        track(1, 2);

        printf("Puzzle %d\n", tt);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d", puzzle[i][j]);
                puzzle[i][j] = 0;
                row[i][j + 1] = 0;
                col[i][j + 1] = 0;
                box[i / 3][i % 3][j + 1] = 0;
                dominos[i + 1][j + 1] = 0;
            }
            printf("\n");
        }
    }
    return 0;
}