#include <stdio.h>

/*
���� : 8 * 8 ũ���� �ǿ��� �־��� ���� �����̴� ����� ��� ����Ѵ�. ���� �������� ������ �� �ִ�.
�� ���� �������� ��Ȯ�� �ش� ������ �ִ� ���� �� ��ŭ�� ĭ�� �̵��ؾ� �Ѵ�. �߰��� �ִ� �ڽ��� ���� �پ���� �� ������
����� ���� �پ���� �� ����. �ݴ��, ����� ���� �������� �ִ� ��� ���� �� ������, �ڽ��� ���� �ִ� �����δ� �� �� ����.
������ �� �ִ� ����� ���ٸ� "No moves are possible"�� ����Ѵ�.

�ذ� ��� : �� ĭ���� �ڽ��� ���� �ִ� ĭ�� ã�´�. �� ĭ���� 8�� �������� ���� ���� �Űܺ���.
���� �ű� �Ÿ��� Ȯ���ϰ�, �� �Ÿ���ŭ �̵����� �� �� �ȿ� �ִ��� Ȯ���Ѵ�. �� ������ ���� ��� �̵��� �Ұ����ϴ�.
�� �����̶�� �߰��� ����� ���� �ְų� ������ ���� �ڽ��� ���� �ִ��� Ȯ���Ѵ�. �� �� �ƴ϶�� �ش� ����� ����ϸ� �ȴ�.
�̸� �ݺ��� �� ����� ���� ��� "No moves are possible"�� ����ϰ�, �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : MidC 1996 D��
*/

char board[16][16];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) return 0;
    return 1;
}

int main(void) {
    int cnt, okay, res;
    char c, o;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM4\\BOARD.IN", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM4\\BOARD_T.OUT", "w", stdout);
    while (1) {
        for (int i = 0; i < 8; i++) {
            if (scanf("%s", board[i]) == EOF) return 0;
        }
        scanf(" %c", &c);
        if (c == 'O') o = 'X';
        else if (c == 'X') o = 'O';
        else return 1;

        res = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != c) continue;
                for (int k = 0; k < 8; k++) {
                    cnt = 0;
                    okay = 1;
                    for (int l = -8; l <= 8; l++) {
                        if (!isvalid(i + dxy[k][0] * l, j + dxy[k][1] * l)) continue;
                        if (board[i + dxy[k][0] * l][j + dxy[k][1] * l] != '.') cnt++;
                    }
                    if (!isvalid(i + dxy[k][0] * cnt, j + dxy[k][1] * cnt)) continue;
                    for (int l = 1; l <= cnt; l++) {
                        if (l < cnt && board[i + dxy[k][0] * l][j + dxy[k][1] * l] == o) {
                            okay = 0;
                            break;
                        }
                        if (l == cnt && board[i + dxy[k][0] * l][j + dxy[k][1] * l] == c) {
                            okay = 0;
                            break;
                        }
                    }
                    if (okay) {
                        printf("%c%d-%c%d\n", i + 'A', j + 1, i + dxy[k][0] * cnt + 'A', j + dxy[k][1] * cnt + 1);
                        res++;
                    }
                }
            }
        }
        if (res == 0) printf("No moves are possible\n");
        printf("\n");
    }
    return 0;
}