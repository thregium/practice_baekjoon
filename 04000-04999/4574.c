#include <stdio.h>

char buff1[4], buff2[4];
long long dominos[16][16], puzzle[9][9], row[9][10], col[9][10], box[3][3][10];
int res = 0;

/*
���� : ������ �ǿ� 1 ~ 9������ ���� ���� �����ְ�, ������ ĭ�� ���̳�� ä��� �Ѵ�. ���̳�� 1, 2���� 8, 9���� ���� �ٸ� �� ���� ���� �ִ�
���� �� ������ �ְ�, �̹� ä���� �ִ� ���̳밡 ���� �� �ִ�. ������ ��Ģ�� �Ϲ� ������� ���ٸ� ���� ĭ�� ä�� ����� ���Ѵ�.
��, ��� ������ ������ �ϳ����̴�.

�ذ� ��� : �Ϲ����� ������� ����� ������� ��Ʈ��ŷ�� ���� Ǯ �� �ִ�. ĭ�� ������� ä��� ��İ� ���� �������� ���� ������ �����
���̳븦 ������� ä��� ����� �ִ�. �� �ڵ忡���� ���ڸ� ����Ͽ���.

�ֿ� �˰��� : ����, ��Ʈ��ŷ

��ó :MidC 2011 D��
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