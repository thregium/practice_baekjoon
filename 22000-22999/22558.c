#include <stdio.h>

/*
���� : H * W(H, W <= 30) ũ���� ���ĺ� �빮�ڷ� �̷���� ��ϵ��� �׿� �ְ�,
�� �� ĭ���� �� ĭ���� �Ǿ��ִ�. ���� �Ǵ� �¿�� N(2 <= N <= 30)�� �̻��� ���� ������� ����Ǹ�
�� ��ϵ��� ������� ���� ��ϵ��� �Ʒ��� ��������. �̴� ���������� �Ͼ��.
�̶�, �¿�� 2���� ĭ�� �ٲپ�(��ĭ ����) ��� ��ϵ��� ���� �� �ִ� �� ���Ѵ�.
�� ó������ ����� N�� �̻� �����ϰ� ������� �ʾҴ�.

�ذ� ��� : ��� �¿�� ������ 2���� ĭ�� ���� �ٲپ� �� ���� ��� ��ϵ��� ������� �� Ȯ���Ѵ�.
Nĭ �̻��� �����ϰ� �Ǿ��ִ� ĭ�� �ִٸ� �̸� ���� ����(�ٷ� ����� �ȵǰ� ã�� ��ġ�� ǥ���� ����
�� ĭ���� ������ �Ѵ�.) ��� ��ϵ��� ������. �� �����͸� ����ϸ� ������ ������� �ʾƵ� �����ϴ�.
���� ĭ, ���� ����� ������ �� ������ �����Ѵ�. �̸� ��ϵ��� ������� ���� �� ���� �ݺ��� ��
�ݺ��� ������ ��� ��ϵ��� ������� �� Ȯ���Ѵ�. �ѹ��̶� ��� ������ٸ� ���� �� �ִ� ���̰�,
�׷��� ��찡 ���ٸ� ���� �� ���� ���̴�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���Ʈ ����

��ó : JAG 2010S 3��
*/

char orig[32][32], board[32][32], temp[32][32];

void swapc(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int findnbyn(int h, int w, int n) {
    int r = 0, c;
    for (int i = 0; i < h; i++) {
        c = 1;
        for (int j = 1; j <= w; j++) {
            if (board[i][j] != '.' && board[i][j] == board[i][j - 1]) c++;
            else {
                if (c >= n) {
                    for (int k = j - 1; k >= j - c; k--) temp[i][k] = '*';
                    r++;
                }
                c = 1;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        c = 1;
        for (int j = 1; j <= h; j++) {
            if (board[j][i] != '.' && board[j][i] == board[j - 1][i]) c++;
            else {
                if (c >= n) {
                    for (int k = j - 1; k >= j - c; k--) temp[k][i] = '*';
                    r++;
                }
                c = 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (temp[i][j] == '*') board[i][j] = '.';
            temp[i][j] = '.';
        }
    }
    return r;
}

void fall(int h, int w) {
    int r = 1;
    while (r) {
        r = 0;
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '.' && board[i - 1][j] != '.') {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = '.';
                    r++;
                }
            }
        }
    }
}

int checkres(int h, int w, int n, int x, int y, int d) {
    //if (orig[x][y] == '.' || (!d && orig[x + 1][y] == '.') || (d && orig[x][y + 1] == '.')) return 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) board[i][j] = orig[i][j];
    }
    swapc(&board[x][y], d ? &board[x][y + 1] : &board[x + 1][y]);

    fall(h, w);
    while (findnbyn(h, w, n)) {
        fall(h, w);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) if (board[i][j] != '.') return 0;
    }
    return 1;
}

int main(void) {
    int h, w, n, r = 0;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < h; i++) {
        scanf("%s", orig[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //if (i < h - 1) r |= checkres(h, w, n, i, j, 0);
            if (j < w - 1) r |= checkres(h, w, n, i, j, 1);
        }
    }
    printf("%s\n", r ? "YES" : "NO");
    return 0;
}