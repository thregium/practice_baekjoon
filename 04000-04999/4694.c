#include <stdio.h>

/*
���� : 4 * 4 ũ���� ���񿡼� �������� �־��� ��, ������ ���ߴ� ����� ����Ѵ�. �� �������� 4 * 4 ũ�� �����̴�.

�ذ� ��� : ��Ʈ��ŷ�� ���� �� �������� ���� �� �ִ� ��� ���� ���ƺ���. ���� ����� ���ٸ� Ž���� �����ϰ�,
���� ����� �ִٸ� �ش� ��ġ�� ������ ���� ���� ������ ���캻 ���� ���ƿͼ� ���� ����� ã�´�.
��� ������ ���µ� �����ߴٸ� �� ĭ�� �ִ��� Ȯ���ϰ� �� ĭ�� ���ٸ� ������ ���̹Ƿ� Ž���� �����ϰ� �ش� ����� ����Ѵ�.

�ֿ� �˰��� : ����, ��Ʈ��ŷ

��ó : MidC 1995 3��
*/

int sz[64][2], puzzle[4][4];
char piece[64][8][8];
int success = 0;

void track(int n, int p) {
    int t;
    if (p >= n) {
        t = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!puzzle[i][j]) t++;
            }
        }
        if (t) return;
        success = 1;
        return;
    }

    for (int i = 0; i <= 4 - sz[p][0]; i++) {
        for (int j = 0; j <= 4 - sz[p][1]; j++) {
            t = 0;
            for (int x = 0; x < sz[p][0]; x++) {
                for (int y = 0; y < sz[p][1]; y++) {
                    if (puzzle[i + x][j + y] && piece[p][x][y]) t = 1;
                }
            }
            if (t) continue;
            for (int x = 0; x < sz[p][0]; x++) {
                for (int y = 0; y < sz[p][1]; y++) {
                    if (piece[p][x][y]) puzzle[i + x][j + y] = p + 1;
                }
            }
            track(n, p + 1);
            if (success) return;
            for (int x = 0; x < sz[p][0]; x++) {
                for (int y = 0; y < sz[p][1]; y++) {
                    if (piece[p][x][y]) puzzle[i + x][j + y] = 0;
                }
            }
        }
    }
}

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\puzzle.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        success = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &sz[i][0], &sz[i][1]);
            for (int j = 0; j < sz[i][0]; j++) {
                scanf("%s", piece[i][j]);
                for (int k = 0; k < sz[i][1]; k++) {
                    if (piece[i][j][k] == '1') piece[i][j][k] = 1;
                    else piece[i][j][k] = 0;
                }
            }
        }

        track(n, 0);
        if (!success) {
            printf("No solution possible\n\n");
            continue;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d", puzzle[i][j]);
                puzzle[i][j] = 0;
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}