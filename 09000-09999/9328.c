#include <stdio.h>
#include <ctype.h>

/*
문제 : H * W(H, W <= 100) 크기의 건물에서 최대 몇 개의 문서($)를 얻을 수 있는지 구한다. 시작 지점은 건물의 가장 바깥쪽의
빈 공간(.)이나 문(대문자)이고, 각 문들은 문에 해당하는 열쇠(소문자)가 있어야 한다. 벽(*)은 통과할 수 없으며,
처음에 일부 열쇠를 갖고 있는 상태일 수도 있다. 이동은 상하좌우로만 할 수 있다.

해결 방법 : 열쇠를 갖고 있는 상태는 알파벳 문자가 26자이므로 비트마스킹을 통해 구현할 수 있다. 열쇠 상태를 전역 변수로 지정해놓고
바깥쪽 지역에서 진입 가능한 칸이 있다면 해당 칸으로 들어와 플러드필을 돌린다. 이 과정에서 새로운 열쇠를 얻었다면
결과가 나오더라도 다시 한번 돌려본다. 이를 새로운 열쇠를 얻을 수 없을 때 까지(비둘기집의 원리에 의해 최대 26회) 반복한다.
마지막에 나온 결과가 얻을 수 있는 최대 문서 수이다.

주요 알고리즘 : 그래프 이론, 플러드필, 비트마스킹, 브루트포스, 구현

출처 : BAPC 2013P K번
*/

char building[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w, key, newkey = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    else if (vis[x][y] || building[x][y] == '*') return 0;
    else if (building[x][y] == '.')  return 1;
    else if (isupper(building[x][y])) {
        if (key & (1 << (building[x][y] - 'A'))) return 2;
        else return 0;
    }
    else if (islower(building[x][y])) {
        if (key & (1 << (building[x][y] - 'a'))) return 3;
        else {
            key |= 1 << (building[x][y] - 'a');
            newkey++;
            return 4;
        }
    }
    else if (building[x][y] == '$') return 9;
    else return -1;
}

int dfs(int x, int y, int docs) {
    vis[x][y] = 1;
    if (building[x][y] == '$') docs++;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) docs += dfs(x + dxy[i][0], y + dxy[i][1], 0);
    }
    return docs;
}

int main(void) {
    int t, r;
    char keys[32] = { 0, };
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", building[i]);
        }
        key = 0;
        scanf("%s", keys);
        for (int i = 0; keys[i]; i++) {
            if (keys[i] == '0') break;
            else key += (1 << (keys[i] - 'a'));
        }

        newkey = 1;
        while (newkey) {
            r = 0;
            newkey = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) vis[i][j] = 0;
            }

            for (int i = 0; i < h; i++) {
                if (isvalid(i, 0)) r += dfs(i, 0, 0);
                if (isvalid(i, w - 1)) r += dfs(i, w - 1, 0);
            }
            for (int i = 0; i < w; i++) {
                if (isvalid(0, i)) r += dfs(0, i, 0);
                if (isvalid(h - 1, i)) r += dfs(h - 1, i, 0);
            }
        }

        printf("%d\n", r);
    }
    return 0;
}