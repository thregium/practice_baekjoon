#include <stdio.h>

/*
���� : N * N(N <= 100) ũ���� ����ã�� �ǿ��� �׵θ� �κп� ������ ������ ���� ���� �־�����.
�� �� ����ã�� �ǿ� ���� �� �ִ� ������ �ִ� ������ ���Ѵ�.

�ذ� ��� : ����ã������ �׵θ��� �������� ���� ���� ���� ���ڰ� ������� �� �ִ�.
�׵θ��� ������ ���� �� ���������� �׵θ��� ���ư��� ã���� ���ڰ� �ִ��� �� �� ���� ĭ�� �ִ� 1�����̹Ƿ� ��� ĭ�� ���� ���θ� �� �� �ִ�.
���� �� �� ������ ��ġ�� ������ �ִ� ������ �� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���?
*/

char minefield[128][128];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

void find(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (minefield[x + dxy[i][0]][y + dxy[i][1]] == '*') cnt++;
    }
    if (cnt == minefield[x][y] - '0') {
        for (int i = 0; i < 8; i++) {
            if (minefield[x + dxy[i][0]][y + dxy[i][1]] == '#') minefield[x + dxy[i][0]][y + dxy[i][1]] = '.';
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            if (minefield[x + dxy[i][0]][y + dxy[i][1]] == '#') minefield[x + dxy[i][0]][y + dxy[i][1]] = '*';
        }
    }

}

int main(void) {
    int t, n, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", minefield[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            find(1, i);
        }
        for (int i = 2; i <= n; i++) {
            find(i, n);
        }
        for (int i = n - 1; i >= 1; i--) {
            find(n, i);
        }
        for (int i = n - 1; i > 1; i--) {
            find(i, 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (minefield[i][j] == '*' || minefield[i][j] == '#') cnt++;
                minefield[i][j] = '\0';
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}