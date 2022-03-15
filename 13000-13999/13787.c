#include <stdio.h>
#include <ctype.h>

/*
���� : H * W(H, W <= 100) ũ���� ���ڿ� '.', '#', (E, S, W, N �� �ϳ��� ���ĺ�)�� �־�����.
���ĺ��� ���� ĭ���� ���ĺ��� �������� ����� �� �������� '#' �Ǵ� ������ ������ ���� �� ���� �̵��ϸ�,
������ �Ǹ� �ð�������� ������ �ʴ� ������� ���ư� ���� �� �������� ������ �ٲپ� �̵��Ѵ�.
�̶�, L(L <= 10^18)�� �̵��� �� ��� ĭ�� ��� ��ġ�� �ְ� �Ǵ� �� ���Ѵ�.

�ذ� ��� : ������ ���´� �� ĭ�� �� �������� �ִ� 100 * 100 * 4�����̴�. �� ��� ��찡 Ȯ�ε� �Ŀ���
�ݵ�� ������ �湮�� ���¸� �ٽ� �湮�ϰ� �ǰ�, �� ���¿��� �ٸ� ���·� �̵��ϴ� �͵�
�׻� �����ϱ� ������ �ݺ��� �Ͼ�� �ȴ�.
����, �ݺ� ���� ã�� ����, ù �ݺ� ������ �ٸ� �ݺ����� ���� �����ϰ�(�ݺ� ����� ���� ������ ���ϱ�)
�̵��� �ùķ��̼��ϸ� ���� ������ ã�� �� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : JAG 2011P A��
*/

char maze[128][128];
int dist[128][128][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char dirc[4] = "ESWN";

int isvalid(int h, int w, int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (maze[x][y] == '#') return 0;
    return 1;
}

int main(void) {
    int h, w, sx, sy, sd, x, y, d, xn, yn, tm, lp;
    long long l;
    while (1) {
        scanf("%d %d %lld", &h, &w, &l);
        if (h == 0) break;
        sx = -1, sy = -1, sd = -1;
        for (int i = 0; i < h; i++) {
            scanf("%s", maze[i]);
            for (int j = 0; j < w; j++) {
                if (isupper(maze[i][j])) {
                    sx = i, sy = j;
                    if (maze[i][j] == 'E') sd = 0;
                    else if (maze[i][j] == 'S') sd = 1;
                    else if (maze[i][j] == 'W') sd = 2;
                    else if (maze[i][j] == 'N') sd = 3;
                }
            }
        }
        if (sx < 0) return 1;

        x = sx, y = sy, d = sd, tm = 1;
        while (1) {
            while (1) {
                xn = x + dxy[d][0];
                yn = y + dxy[d][1];
                if (isvalid(h, w, xn, yn)) break;
                else d = ((d + 1) & 3);
            }
            x = xn, y = yn;
            if (dist[x][y][d]) {
                lp = tm - dist[x][y][d];
                tm = dist[x][y][d];
                break;
            }
            else dist[x][y][d] = tm++;
        }

        if (l > tm) l = (l - tm) % lp + tm;
        x = sx, y = sy, d = sd, tm = 1;
        while (1) {
            while (1) {
                xn = x + dxy[d][0];
                yn = y + dxy[d][1];
                if (isvalid(h, w, xn, yn)) break;
                else d = ((d + 1) & 3);
            }
            x = xn, y = yn;
            if (tm == l) {
                printf("%d %d %c\n", x + 1, y + 1, dirc[d]);
                break;
            }
            else dist[x][y][d] = tm++;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                maze[i][j] = '\0';
                for (int k = 0; k < 4; k++) dist[i][j][k] = 0;
            }
        }
    }
    return 0;
}