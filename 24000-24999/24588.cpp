#include <stdio.h>
#include <queue>
#include <unordered_set>
using namespace std;

/*
���� : R * C(R, C <= 750) ũ���� ü���� ���� ��� �� 1���� ���� ����Ʈ���� �ִ�.
��� ����Ʈ���� ��ġ�� �־��� ��, ���� ��ǥ �������� �ű� �� �ִ� �� ���Ѵ�.
ó���� ���� ���ݹ޴� ���°� �ƴϸ�, ���ݹ޴� ĭ���δ� �̵� �Ұ����ϴ�. ���� ����Ʈ�� �پ���� ���� ������
���� ��� �ٽ� ������ ���� �ִ�. (�ð����� 11��)

�ذ� ��� : ���� ������ ĭ���� ť�� �ְ� BFS�� ���� �̵� ������ ĭ���� Ȯ���Ѵ�.
�̵� ������ �ִ� ĭ�� ���ݹ޴� ���� ��� �ӽ� �迭�� �����Ѵ�. �̵��� ĭ�� ����Ʈ�� �ִٸ�
�� ����Ʈ�� �����ϴ� ĭ���� ���� Ƚ���� 1 ���̰�, �׷� ���� ���� Ƚ���� 0�� �� ĭ�� �ӽ� �迭����
üũ�� ĭ�� ��� �� ĭ�� ť�� �ű��.
�ð� ������ 11���̱� ������ O(R + C)(RC)�� �ð� ���⵵�ε� ��� �����ϴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : MidAtl 2021 L�� // NCNA 2021 H��
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