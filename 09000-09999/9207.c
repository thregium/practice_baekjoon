#include <stdio.h>

/*
���� : �־��� ������ ��� �ָ��׾� �ǿ��� ���� ������ �ּҷ� ���̵��� ������ ��, ���� ������
������ Ƚ���� ���Ѵ�. ó�� �ִ� ���� ������ 8�� ���ϴ�.

�ذ� ��� : ���� �����̴� ��� ��츦 �õ��غ��鼭 ���� ������ �ּ��� ���� �� ������ ���ϸ� �ȴ�.
������ Ƚ���� �׻� ���� ������ ó�� ���¿����� �� �������� �� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : GCPC 2013 F��
*/

char board[8][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int best = 9, mov;

int isvalid(int x, int y, int d) {
    if (board[x + dxy[d][0]][y + dxy[d][1]] != 'o') return 0;
    else if (board[x + dxy[d][0] * 2][y + dxy[d][1] * 2] != '.') return 0;
    return 1;
}

void track(int m) {
    int cnt = 0;
    for (int i = 2; i <= 6; i++) {
        for (int j = 2; j <= 10; j++) {
            if (board[i][j] == 'o') {
                cnt++;
                for (int k = 0; k < 4; k++) {
                    if (isvalid(i, j, k)) {
                        board[i][j] = '.';
                        board[i + dxy[k][0]][j + dxy[k][1]] = '.';
                        board[i + dxy[k][0] * 2][j + dxy[k][1] * 2] = 'o';
                        track(m + 1);
                        board[i][j] = 'o';
                        board[i + dxy[k][0]][j + dxy[k][1]] = 'o';
                        board[i + dxy[k][0] * 2][j + dxy[k][1] * 2] = '.';
                    }
                }
            }
        }
    }
    if (cnt < best) {
        best = cnt;
        mov = m;
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 2; i <= 6; i++) {
            scanf("%s", board[i] + 2);
        }
        best = 9, mov = -1;
        track(0);
        printf("%d %d\n", best, mov);
    }
    return 0;
}