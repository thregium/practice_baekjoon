#include <stdio.h>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : H * W(H, W <= 30) ũ���� ������ �κ��� �� ���� ������ �������� ���� �ִ�.
�� ĭ�� ����� 5���� �� �ϳ���, ����, ��ȸ��, ����, ��ȸ��, ������ 5�����̴�.
�ٸ� ����� �����ϱ� ���ؼ��� p_i(1 <= p_i <= 9)��ŭ�� ����� �ʿ��ϴ�.
�̶�, �� ������ �Ʒ� ĭ���� �̵��ϱ� ���� �����ؾ� �ϴ� �ּ� ����� ���Ѵ�.

�ذ� ��� : �� ĭ�� �κ��� ������ �������� �ϰ�, ���������� ����ϴ� ���ͽ�Ʈ�� ���� ���� ���Ѵ�.
�� �������� ��� �ൿ�� �� ���鼭 �ش� ĭ�� �ִ� �ൿ�� �� ��� ��� 0���� �̵�, �� �� �ൿ�� ���
�ش� ��븸ŭ���� �̵��Ѵ�. �� �������� ����� ��ǥ�� ���ϴ� �Ϳ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : JDC 2008 D��
*/

int board[32][32], dist[32][32][4], vis[32][32][4], price[5];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
//dist, x, y, dir
int h, w;

int isvalid(int* x, int* y, int* dir, int inst) {
    int nx, ny, ndir;
    ndir = *dir;
    if (inst == 1) ndir = ((ndir + 1) & 3);
    else if (inst == 2) ndir = ((ndir + 2) & 3);
    else if (inst == 3) ndir = ((ndir + 3) & 3);
    if (inst < 4) {
        nx = *x + dxy[ndir][0];
        ny = *y + dxy[ndir][1];
    }
    else {
        nx = *x;
        ny = *y;
    }
    *dir = ndir;
    *x = nx;
    *y = ny;

    if (nx < 0 || ny < 0 || nx >= h || ny >= w) return 0;
    if (vis[nx][ny][ndir]) return 0;
    else return 1;
}

int main(void) {
    int ndist, x, y, dir, nx, ny, ndir, res;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        for (int i = 0; i < 4; i++) {
            scanf("%d", &price[i]);
        }
        price[4] = INF;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < 4; k++) {
                    dist[i][j][k] = INF;
                    vis[i][j][k] = 0;
                }
            }
        }

        pq.push({ 0, 0, 0, 0 });
        dist[0][0][0] = 0;
        while (pq.size()) {
            ndist = get<0>(pq.top());
            x = get<1>(pq.top());
            y = get<2>(pq.top());
            dir = get<3>(pq.top());
            pq.pop();
            if (vis[x][y][dir]) continue;
            else vis[x][y][dir] = 1;

            for (int i = 0; i < 5; i++) {
                nx = x, ny = y, ndir = dir;
                if (isvalid(&nx, &ny, &ndir, i)) {
                    if (dist[nx][ny][ndir] > dist[x][y][dir] + (i == board[x][y] ? 0 : price[i])) {
                        dist[nx][ny][ndir] = dist[x][y][dir] + (i == board[x][y] ? 0 : price[i]);
                        pq.push({ dist[nx][ny][ndir], nx, ny, ndir });
                    }
                }
            }
        }

        res = INF;
        for (int i = 0; i < 4; i++) {
            if (dist[h - 1][w - 1][i] < res) res = dist[h - 1][w - 1][i];
        }
        printf("%d\n", res);
    }
    return 0;
}