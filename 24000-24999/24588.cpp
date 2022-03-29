#include <stdio.h>
#include <queue>
#include <unordered_set>
using namespace std;

/*
문제 : R * C(R, C <= 750) 크기인 체스판 위에 흰색 룩 1개와 검은 나이트들이 있다.
룩과 나이트들의 위치가 주어질 때, 룩을 목표 지점으로 옮길 수 있는 지 구한다.
처음에 룩은 공격받는 상태가 아니며, 공격받는 칸으로는 이동 불가능하다. 룩은 나이트를 뛰어넘을 수는 없지만
룩을 잡고 다시 지나갈 수는 있다. (시간제한 11초)

해결 방법 : 룩이 도착한 칸들을 큐에 넣고 BFS를 통해 이동 가능한 칸들을 확인한다.
이동 범위에 있는 칸이 공격받는 중인 경우 임시 배열에 저장한다. 이동한 칸에 나이트가 있다면
그 나이트가 공격하는 칸들의 공격 횟수를 1 줄이고, 그로 인해 공격 횟수가 0이 된 칸이 임시 배열에서
체크된 칸인 경우 그 칸을 큐로 옮긴다.
시간 제한이 11초이기 때문에 O(R + C)(RC)의 시간 복잡도로도 통과 가능하다.

주요 알고리즘 : 그래프 이론, BFS

출처 : MidAtl 2021 L번 // NCNA 2021 H번
*/

char board[768][768], vis[768][768];
int att[768][768];
int dxyk[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int dxyr[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
unordered_set<int> cand;
queue<pair<int, int>> q;
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    else if (vis[x][y]) return -2;
    else if (board[x][y] == 'K') return -1;
    else return 1;
}

int bfs(int x, int y) {
    int xt, yt;
    q.push({ x, y });
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        if (board[x][y] == 'T') return 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            xt = x + dxyr[i][0], yt = y + dxyr[i][1];
            while (xt >= 0 && yt >= 0 && xt < r && yt < c) {
                if (att[xt][yt]) {
                    cand.insert(xt * 1024 + yt);
                    if (board[xt][yt] == 'K') break;
                }
                else {
                    if (!vis[xt][yt]) {
                        q.push({ xt, yt });
                        if (board[xt][yt] == 'K') {
                            for (int j = 0; j < 8; j++) {
                                if (!isvalid(xt + dxyk[j][0], yt + dxyk[j][1])) continue;
                                att[xt + dxyk[j][0]][yt + dxyk[j][1]]--;
                                if (att[xt + dxyk[j][0]][yt + dxyk[j][1]] == 0 &&
                                    cand.find((xt + dxyk[j][0]) * 1024 + yt + dxyk[j][1]) != cand.end()) {
                                    q.push({ xt + dxyk[j][0], yt + dxyk[j][1] });
                                }
                            }
                        }
                    }
                }
                vis[xt][yt] = 1;
                xt += dxyr[i][0], yt += dxyr[i][1];
            }
        }
    }
    return 0;
}

int main(void) {
    int x = -1, y = -1;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'R') {
                x = i, y = j;
            }
        }
    }
    if (x < 0) return 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 8; k++) {
                if (isvalid(i + dxyk[k][0], j + dxyk[k][1]) == -1) att[i][j]++;
            }
        }
    }
    if (att[x][y] > 0) return 2;
    printf("%s", bfs(x, y) ? "yes" : "no");
    return 0;
}