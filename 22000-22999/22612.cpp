#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
���� : W * H(H, W <= 50) ũ���� �� �������� �ִ�. ���� �ǿ��� '.', '#'�� �ְ� '%'�� 1���� �ִ�.
����, ���� �ǿ��� 'L', ������ �ǿ��� 'R'�� ���� �����ϰ� �ִ�. �̶�, �� ���� ������ '%'�� ���ÿ�
�����ϰ� ���� �� �ִ� �� ���Ѵ�. ���� ���� �¿��Ī���� �����̸� ���̳� ������ �𼭸��� ���
������ �� ������ ��ȿ�� �������̴�. ���� �� �� �ϳ��� %�� �����ؼ��� �� �ȴ�.

�ذ� ��� : ���� ��ġ�� ������ �θ� �÷������� �ϸ� �ȴ�. �� �� �Ϻΰ� �������� ���ϴ� ����
�̵��� �������� ���� ���� ���� ���� ��ġ�� ����� ��ġ �� �ϳ��� �����ϴ� ������ ó�� �����ϴ�.
����, �� �� �ϳ��� '%'�� �������� �ʵ��� �����ϰ�, ���� ������ �����ؾ� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : JAG 2009D E��
*/

char left[64][64], right[64][64], vis[64][64][64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int bxy[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int w, h;
queue<pair<pair<int, int>, pair<int, int>>> q;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (d && right[x][y] == '#') return 0;
    else if (!d && left[x][y] == '#') return 0;
    else return 1;
}

int bfs(int xl, int yl, int xr, int yr) {
    q.push(make_pair(make_pair(xl, yl), make_pair(xr, yr)));
    int nxl, nyl, nxr, nyr;
    while (q.size()) {
        xl = q.front().first.first, yl = q.front().first.second;
        xr = q.front().second.first, yr = q.front().second.second;
        q.pop();
        if ((left[xl][yl] == '%') && (right[xr][yr] == '%')) {
            while (q.size()) q.pop();
            return 1;
        }
        for (int i = 0; i < 4; i++) {
            nxl = isvalid(xl + dxy[i][0], yl + dxy[i][1], 0) ? xl + dxy[i][0] : xl;
            nyl = isvalid(xl + dxy[i][0], yl + dxy[i][1], 0) ? yl + dxy[i][1] : yl;
            nxr = isvalid(xr + bxy[i][0], yr + bxy[i][1], 1) ? xr + bxy[i][0] : xr;
            nyr = isvalid(xr + bxy[i][0], yr + bxy[i][1], 1) ? yr + bxy[i][1] : yr;
            if (vis[nxl][nyl][nxr][nyr]) continue;
            if ((left[nxl][nyl] == '%') ^ (right[nxr][nyr] == '%')) continue;
            vis[nxl][nyl][nxr][nyr] = 1;
            q.push(make_pair(make_pair(nxl, nyl), make_pair(nxr, nyr)));
        }
    }
    return 0;
}

int main(void) {
    int xl = -1, yl = -1, xr = -1, yr = -1;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s %s", left[i], right[i]);
            for (int j = 0; j < w; j++) {
                if (left[i][j] == 'L') {
                    xl = i;
                    yl = j;
                }
                if (right[i][j] == 'R') {
                    xr = i;
                    yr = j;
                }
            }
        }
        printf("%s\n", bfs(xl, yl, xr, yr) ? "Yes" : "No");

        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
