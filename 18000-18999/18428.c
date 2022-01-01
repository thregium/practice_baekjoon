#include <stdio.h>

/*
���� : N * N(3 <= N <= 6) ũ���� �濡 �л��� ������ �ִ�. ������ ������ ���� �����¿� ĭ���� �� �� �ִٸ�,
��ֹ��� 3�� ���� ��� �л��� �� �� ���� �� �� �ִ� �� ���Ѵ�.

�ذ� ��� : ��ֹ��� 3�� ���� ��� ����� ���Ʈ ������ �غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ
*/

char s[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int res = 0;

int isvalid(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (s[x][y] == 'T' || s[x][y] == 'O') return 0;
    return 1;
}

void track(int n, int x) {
    if (x == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] != 'T') continue;
                for (int d = 0; d < 4; d++) {
                    for (int st = 1; isvalid(n, i + dxy[d][0] * st, j + dxy[d][1] * st); st++) {
                        if (s[i + dxy[d][0] * st][j + dxy[d][1] * st] == 'S') return;
                    }
                }
            }
        }
        res = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'X') {
                s[i][j] = 'O';
                track(n, x + 1);
                s[i][j] = 'X';
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &s[i][j]);
        }
    }
    track(n, 0);
    printf("%s", res ? "YES" : "NO");
    return 0;
}