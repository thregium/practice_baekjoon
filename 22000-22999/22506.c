#include <stdio.h>

/*
문제 : R * C(R, C <= 50) 크기의 지역에 방과 벽들이 있다. 각 방들은 트리 형태로 이루어져 있다.
이때, 각 방의 불을 켤 때와 끌 때, 단위 시간당 켜져 있을 때의 전력 소모량이 각각 주어지면,
M(M <= 1000)개의 지점을 지나면서 소모하는 전력량의 최솟값을 구한다.
각 지점에 들어갈 때에는 반드시 불이 켜져있어야 하고, 최종 지점에 도착한 후에는 모든 불이 꺼져야 한다.
각 칸을 이동할 때 마다 단위시간 1씩 소모되며 불을 켜거나 끌 때에는 시간이 소모되지 않는다.

해결 방법 : 우선 플러드필과 역추적을 이용하여 이동 경로를 만들어 준다.
그 다음, 이동 경로의 뒤에서부터 확인하며 각 지점에 다음으로 도달하는 시간을 확인한다.
다시 처음부터 이동 경로를 따라가며 그 지점을 처음 방문한 경우 불을 켜고 끄는 비용을 더한다.
방문하고 나올 때에는 다음에 다시 방문하지 않는다면 그대로 나오면 되고,
다시 방문한다면 그동안 불을 켜 두는 것과 껐다 키는 것을 비교하여 둘 중 전력을 덜 소모하는 것을
선택하여 그 비용을 더하면 된다. 이를 반복하여 최종적인 결과를 구한다.

주요 알고리즘 : 그래프 이론, 플러드필, 트리, 그리디 알고리즘

출처 : JAG 2011S3 C번
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