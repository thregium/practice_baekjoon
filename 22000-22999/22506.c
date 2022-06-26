#include <stdio.h>

/*
���� : R * C(R, C <= 50) ũ���� ������ ��� ������ �ִ�. �� ����� Ʈ�� ���·� �̷���� �ִ�.
�̶�, �� ���� ���� �� ���� �� ��, ���� �ð��� ���� ���� ���� ���� �Ҹ��� ���� �־�����,
M(M <= 1000)���� ������ �����鼭 �Ҹ��ϴ� ���·��� �ּڰ��� ���Ѵ�.
�� ������ �� ������ �ݵ�� ���� �����־�� �ϰ�, ���� ������ ������ �Ŀ��� ��� ���� ������ �Ѵ�.
�� ĭ�� �̵��� �� ���� �����ð� 1�� �Ҹ�Ǹ� ���� �Ѱų� �� ������ �ð��� �Ҹ���� �ʴ´�.

�ذ� ��� : �켱 �÷����ʰ� �������� �̿��Ͽ� �̵� ��θ� ����� �ش�.
�� ����, �̵� ����� �ڿ������� Ȯ���ϸ� �� ������ �������� �����ϴ� �ð��� Ȯ���Ѵ�.
�ٽ� ó������ �̵� ��θ� ���󰡸� �� ������ ó�� �湮�� ��� ���� �Ѱ� ���� ����� ���Ѵ�.
�湮�ϰ� ���� ������ ������ �ٽ� �湮���� �ʴ´ٸ� �״�� ������ �ǰ�,
�ٽ� �湮�Ѵٸ� �׵��� ���� �� �δ� �Ͱ� ���� Ű�� ���� ���Ͽ� �� �� ������ �� �Ҹ��ϴ� ����
�����Ͽ� �� ����� ���ϸ� �ȴ�. �̸� �ݺ��Ͽ� �������� ����� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, Ʈ��, �׸��� �˰���

��ó : JAG 2011S3 C��
*/

int on[64][64], off[64][64], cost[64][64], dest[1024][2], last[64][64];
char room[64][64];
short path[2621440];
short stk[2560];
int nxt[2621440];
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int pcnt = 0, r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (room[x][y] == '#') return 0;
    return 1;
}

void takepath(int x, int y, int px, int py, int ex, int ey, int top) {
    int nx, ny;
    stk[top] = x * 64 + y;
    if (x == ex && y == ey) {
        for (int j = 0; j < top; j++) path[pcnt++] = stk[j];
        return;
    }
    for (int i = 0; i < 4; i++) {
        nx = x + dxy[i][0];
        ny = y + dxy[i][1];
        if (!isvalid(nx, ny)) continue;
        if (nx == px && ny == py) continue;
        takepath(nx, ny, x, y, ex, ey, top + 1);
    }
}

int main(void) {
    int m, x, y;
    long long res = 0;
    scanf("%d %d %d", &r, &c, &m);
    for (int i = 0; i < r; i++) {
        scanf("%s", room[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &on[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &off[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &dest[i][0], &dest[i][1]);
        if (i == 0) continue;
        takepath(dest[i - 1][0], dest[i - 1][1], -1, -1, dest[i][0], dest[i][1], 0);
    }
    path[pcnt++] = dest[m - 1][0] * 64 + dest[m - 1][1];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) last[i][j] = pcnt;
    }
    for (int i = pcnt - 1; i >= 0; i--) {
        nxt[i] = last[path[i] >> 6][path[i] & 63];
        last[path[i] >> 6][path[i] & 63] = i;
    }
    for (int i = 0; i < pcnt; i++) {
        x = path[i] >> 6;
        y = (path[i] & 63);
        if (i == last[x][y]) res += on[x][y] + off[x][y];
        if (nxt[i] == pcnt) continue;
        if ((nxt[i] - i) * (long long)cost[x][y] < on[x][y] + off[x][y]) {
            res += (nxt[i] - i) * (long long)cost[x][y];
        }
        else res += on[x][y] + off[x][y];
    }
    printf("%lld\n", res);
    return 0;
}