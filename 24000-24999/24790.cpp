#include <stdio.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;

/*
���� : �κ��� 8 * 8 ũ���� ������ ���� �Ʒ��� �������� ���� �ִ�. ������ �־��� �̵� ��ɵ��� �̿��Ͽ�
���̾Ƹ�忡 �����ϴ� �ִ� �Ÿ��� ��� ����� ����Ѵ�.
���̾Ƹ�忡 ���� �Ұ����ϴٸ� "no solution"�� ����Ѵ�.

�ذ� ��� : BFS�� ���� �κ��� ��ġ�� ���⸶���� �Ÿ��� ���ϰ�, �Ÿ��� �پ��� ��������
�ٽ� �������� �� ������ �ȴ�. ������ �ִ� ĭ�� F ���� X�� ����ϴ� ������ �ذ� �����ϴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����, ������

��ó : VTH 2016 H��
*/

char board[16][16], vis[8][8][4], res[1024];
int dist[8][8][4];
tuple<int, int, int, int> last[8][8][4];
queue<tuple<int, int, int>> q;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) return 0;
    else if (vis[x][y][d]) return 0;
    else if (board[x][y] == 'C') return 0;
    else if (board[x][y] == 'I') return -1;
    else return 1;
}

int main(void) {
    int x, y, d, diax = -1, diay = -1, diad = -1, op;
    for (int i = 0; i < 8; i++) {
        scanf("%s", board[i]);
    }
    board[7][0] = '.';
    q.push({ 7, 0, 0 });
    vis[7][0][0] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());
        if (board[x][y] == 'D') {
            diax = x, diay = y, diad = d;
            break;
        }
        q.pop();
        if (isvalid(x + dxy[d][0], y + dxy[d][1], d)) {
            if (isvalid(x + dxy[d][0], y + dxy[d][1], d) < 0) {
                last[x + dxy[d][0]][y + dxy[d][1]][d] = { x, y, d, 2 };
            }
            else {
                last[x + dxy[d][0]][y + dxy[d][1]][d] = { x, y, d, 1 };
            }
            vis[x + dxy[d][0]][y + dxy[d][1]][d] = 1;
            dist[x + dxy[d][0]][y + dxy[d][1]][d] = dist[x][y][d] + 1;
            q.push({ x + dxy[d][0], y + dxy[d][1], d });
        }
        if (!vis[x][y][(d + 3) & 3]) {
            vis[x][y][(d + 3) & 3] = 1;
            dist[x][y][(d + 3) & 3] = dist[x][y][d] + 1;
            last[x][y][(d + 3) & 3] = { x, y, d, 3 };
            q.push({ x, y, (d + 3) & 3 });
        }
        if (!vis[x][y][(d + 1) & 3]) {
            vis[x][y][(d + 1) & 3] = 1;
            dist[x][y][(d + 1) & 3] = dist[x][y][d] + 1;
            last[x][y][(d + 1) & 3] = { x, y, d, 4 };
            q.push({ x, y, (d + 1) & 3 });
        }
    }
    
    if (diax < 0) {
        printf("no solution");
        return 0;
    }
    while (!(diax == 7 && diay == 0 && diad == 0)) {
        op = get<3>(last[diax][diay][diad]);
        if (op == 1) strcat(res, "F");
        else if (op == 2) strcat(res, "FX");
        else if (op == 3) strcat(res, "L");
        else if (op == 4) strcat(res, "R");
        x = get<0>(last[diax][diay][diad]);
        y = get<1>(last[diax][diay][diad]);
        d = get<2>(last[diax][diay][diad]);
        diax = x, diay = y, diad = d;
    }
    for (int i = strlen(res) - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
    return 0;
}