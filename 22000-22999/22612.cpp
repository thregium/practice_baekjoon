#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
문제 : W * H(H, W <= 50) 크기의 두 격자판이 있다. 양쪽 판에는 '.', '#'이 있고 '%'가 1개씩 있다.
또한, 왼쪽 판에는 'L', 오른쪽 판에는 'R'이 각각 유일하게 있다. 이때, 이 둘을 움직여 '%'에 동시에
도달하게 만들 수 있는 지 구한다. 둘은 서로 좌우대칭으로 움직이며 벽이나 격자판 모서리에 닿아
움직일 수 없더라도 유효한 움직임이다. 또한 둘 중 하나만 %에 도달해서는 안 된다.

해결 방법 : 둘의 위치를 변수로 두며 플러드필을 하면 된다. 둘 중 일부가 움직이지 못하는 경우는
이동이 가능한지 먼저 살핀 다음 원래 위치와 변경된 위치 중 하나를 선택하는 것으로 처리 가능하다.
또한, 둘 중 하나만 '%'에 도달하지 않도록 유의하고, 방향 설정도 주의해야 한다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : JAG 2009D E번
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
