#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

/*
���� : N * N(N <= 20) ũ���� ���ڿ��� �ýð� �̵��Ѵ�. �ýô� ó���� (X, Y)�� �ְ�, ���� ����� �մ� ��� �� ��ȣ�� �� ��ȣ�� ���� ���� �մԿ��� ����.
�մԿ��� �� ���� ���������� �̵��ϰ�, �մ��� �¿� �Ÿ� * 2��ŭ�� ���Ḧ �޴´�. ����� 1ĭ�� �̵��� �� ���� 1�� �پ���.
��� �մ��� �¿� �� ���� ������ ���� ���Ѵ�. ó���� ����� L��ŭ �ְ�, �߰��� ���ᰡ ���� �������ų� ��� �մ��� �������� ������ ���� �Ұ����ϴٸ� -1�� ����Ѵ�.
�մ��� ��� M(M <= 500)���̴�.

�ذ� ��� : �������������� BFS�� ���� �¿� �մ��� ã��, �ش� �������� �ٽ� BFS�� ���� ������������ �Ÿ��� ���Ѵ�. �̸� Mȸ �ݺ��� ���� ���� ���ᷮ�� ���ϸ� �Ǵµ�,
�� �ݺ����� �ʾ������� �¿� �մ��� ���ų� ���߿� ���ᰡ �ٴڳ��� ��� �߰��� ���� -1�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �ùķ��̼�
*/

int city[32][32], vis[32][32], dist[32][32], cl[512][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, nx, ny, cnt;
queue<pair<int, int>> q;

void clearmap(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    while (q.size()) q.pop();
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    else if (city[x][y] > 0 || vis[x][y]) return 0;
    else return 1;
}

int bfs1(int x, int y) {
    //���� ����� �մ� Ȯ��, ��ȯ���� 2^20 * �Ÿ� + 2^10 * X + Y, ���ٸ� -1
    clearmap();
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }

    int bestdist = 9999;
    x = -1;
    y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] && vis[i][j] && dist[i][j] < bestdist) {
                bestdist = dist[i][j];
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return -1;
    return bestdist * 1048576 + x * 1024 + y;
}

int bfs2(int x, int y) {
    //������������ �Ÿ� Ȯ��, ���� �Ұ��ÿ� -9999
    clearmap();
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    int n = -city[x][y];
    city[x][y] = 0;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        if (cl[n][0] == x && cl[n][1] == y) {
            nx = cl[n][0];
            ny = cl[n][1];
            return dist[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
    return -9999;
}

int main(void) {
    int m, l, x, y, a, b, c;
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &city[i][j]);
        }
    }
    scanf("%d %d", &x, &y);
    x--; //ĭ�� ���߱� ����
    y--;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        city[a - 1][b - 1] = -i; //�ش� ��ġ�� �մ��� �־��ش�.
        scanf("%d %d", &cl[i][0], &cl[i][1]);
        cl[i][0]--; //���� ���� ����
        cl[i][1]--;
    }

    for (int i = 1; i <= m; i++) {
        a = bfs1(x, y);
        if (a < 0) {
            l = -1; //�մ��� ��� ���� �ʾ����� �մ��� ���� ���
            break;
        }
        b = (a >> 20);
        c = bfs2((a >> 10) & 1023, a & 1023);
        if (c < 0) {
            l = -1; //���������� �� �� ���� ���
            break;
        }

        if (l < b + c) {
            l = -1; //���ᰡ ������ ���
            break;
        }
        else {
            l += c - b; //������ ���
            x = nx;
            y = ny;
        }
    }
    printf("%d", l);
    return 0;
}