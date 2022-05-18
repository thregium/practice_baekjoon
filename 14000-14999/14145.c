#include <stdio.h>

/*
문제 : R * S(R, S <= 50) 크기의 밀밭에 밀들이 있다. 상하좌우로 인접한 덩어리들의 크기가 작은 것 부터
차례로 밀밭의 덩어리에 번호를 붙일 때, 번호를 붙인 지도를 출력한다.
각 덩어리는 모두 크기가 다르고, 덩어리는 최대 9개다.

해결 방법 : 플러드필을 통해 각 덩어리의 크기를 구하고, 다시 덩어리들을 확인하면서
덩어리의 번호를 계산한 다음, 그 덩어리들을 해당 번호로 바꾼다. 이를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : CPC 2009 I번
*/

char wheat[64][64], vis[64][64];
int size[64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || wheat[x][y] == '0') return 0;
    return 1;
}

int dfs(int x, int y, int dig) {
    int res = 1;
    vis[x][y] = 1;
    if (dig > 0) wheat[x][y] = '0' + dig;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) res += dfs(x + dxy[i][0], y + dxy[i][1], dig);
    }
    return res;
}

int main(void) {
    int wcnt = 0, wnum = 0, wdigit;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", wheat[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j] || wheat[i][j] == '0') continue;
            size[wcnt++] = dfs(i, j, 0);
        }
    }
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) vis[i][j] = 0;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j] || wheat[i][j] == '0') continue;
            wdigit = 0;
            for (int k = 0; k < wcnt; k++) wdigit += (size[k] <= size[wnum]);
            dfs(i, j, wdigit);
            wnum++;
        }
    }

    for (int i = 0; i < h; i++) {
        printf("%s\n", wheat[i]);
    }
    return 0;
}