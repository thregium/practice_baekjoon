#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N * M(N * M <= 100000) 크기의 격자에 1, 2가 적혀있다. 1과 2가 체크 무늬를 이루는 경우는 없다.
이때, 1인 칸과 이미 방문한 칸으로만 이동 가능한 것과 2인 칸과 이미 방문한 칸으로만 이동 가능한 것이
있다면, 모든 칸을 방문하기 위해 둘을 몇 번 바꿔타야 하는 지 구한다. 처음 타는 것도 포함한다.

해결 방법 : 1인 덩어리와 2인 덩어리를 각각 찾아서 개수를 세 준다. 1인 덩어리와 2인 덩어리 가운데
더 적은 것을 미리 전부 지워주고 나면 나머지는 한 번에 처리 가능하기 때문에 둘 중 더 적은 것 + 1이
답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : Tehran 2012 G번
*/

char s[103000];
string grain[103000];
vector<int> vis[103000];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, wheat, corn;

void dfs(int x, int y) {
    int xt, yt;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        xt = x + dxy[i][0];
        yt = y + dxy[i][1];
        if (xt < 0 || yt < 0 || xt >= n || yt >= m) continue;
        if (grain[xt][yt] != grain[x][y] || vis[xt][yt]) continue;
        dfs(xt, yt);
    }
}

int main(void) {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            grain[i].assign(s);
            vis[i].clear();
            for (int j = 0; j < m; j++) vis[i].push_back(0);
        }

        wheat = 0, corn = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    dfs(i, j);
                    if (grain[i][j] == '1') wheat++;
                    else corn++;
                }
            }
        }
        if (wheat < corn) printf("%d\n", wheat + 1);
        else printf("%d\n", corn + 1);
    }
    return 0;
}