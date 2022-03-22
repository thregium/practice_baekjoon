#include <stdio.h>

/*
���� : 8 * 8 ũ���� �ǿ��� �־��� ��ɾ��� �κ��� ������ ��, �߸��� �Է��� ���� �ʰ�
���̾Ƹ�忡 �� �� �ִ� �� ���θ� ���Ѵ�.

�ذ� ��� : �־��� ��ɾ���� �����Ѵ�. ���� ĭ�� ��ġ�� �̸� �����ϴ� �Լ��� ����� ����.
���� �̵��� ���� �迭�� ����ϴ� ���� ����.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : VTH 2016 C��
*/

char board[16][16], prog[103000];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) return 0;
    if (board[x][y] == 'C') return -1;
    if (board[x][y] == 'I') return -2;
    return 1;
}

int main(void) {
    int x = 7, y = 0, d = 0, bug = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%s", board[i]);
    }
    board[7][0] = '.';
    scanf("%s", prog);
    for (int i = 0; prog[i]; i++) {
        if (prog[i] == 'F') {
            if (isvalid(x + dxy[d][0], y + dxy[d][1]) > 0) {
                x += dxy[d][0];
                y += dxy[d][1];
            }
            else {
                bug = 1;
                break;
            }
        }
        else if (prog[i] == 'L') d = ((d + 3) & 3);
        else if (prog[i] == 'R') d = ((d + 1) & 3);
        else if (prog[i] == 'X') {
            if (isvalid(x + dxy[d][0], y + dxy[d][1]) == -2) {
                board[x + dxy[d][0]][y + dxy[d][1]] = '.';
            }
            else {
                bug = 1;
                break;
            }
        }
        else return 1;
    }
    if (bug || board[x][y] != 'D') printf("Bug!");
    else printf("Diamond!");
    return 0;
}