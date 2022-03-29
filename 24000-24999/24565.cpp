#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : H * W(H, W <= 100) ũ���� ���ڿ� �������� �ִ�. ��� �� �� ������ ����� �ٴ��� �ƴ� ��� ��������
�Ʒ��� �����ִ� ������ �ʿ��ϴ� �� ��, �ʿ��� ������ �ּ� ������ ���Ѵ�.
�� �� ������ ���ƾ� 2�����̴�.

�ذ� ��� : �� �������� �������� ���� ���Ʒ��� ������ ��� ������ �Ʒ��� ���ϴ� ������ �׾��ش�.
�ٴڿ� �ִ� �������� ������ �ٴ� ������ �߰��� �� �������� ������ �̾��ָ� ���� �� ���� �ִ� �����鿡��
�ٴ� �������� ���ϴ� �ִ� ��ο� ����.

�̴� �� �� ������ 1���� ��� �ܼ� BFS�� Ǯ �� ������,
2���� ��쿡�� ��� �������� ���� �� �� �� �������� ������������ �Ÿ��� ���������� �ٴ� ����������
�Ÿ� ��� �ּڰ��� ���ϸ� �ȴ�. ���������� �ٴ� ���������� �Ÿ��� ���ϱ� �����Ƿ�
������ ������ �ٴ� �������� ��� �������� �Ÿ��� ���ϰ� �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ECNA 2021 K��
*/

int piece[128][128], dist[3][10240], vis[10240], stt[8];
vector<int> ed[10240];
queue<int> q;

void bfs(int x, int dn) {
    for (int i = 0; i < 10240; i++) vis[i] = 0;
    q.push(x);
    vis[x] = 1;
    dist[dn][x] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                q.push(i);
                dist[dn][i] = dist[dn][x] + 1;
                vis[i] = 1;
            }
        }
    }
}

int main(void) {
    int h, w, ssz = 0, exi, res = 103000;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &piece[i][j]);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (piece[i][j] != piece[i + 1][j]) {
                ed[piece[i][j]].push_back(piece[i + 1][j]);
                //ed[piece[i + 1][j]].push_back(piece[i][j]);
            }
        }
    }
    for (int i = 0; i < w; i++) {
        exi = 0;
        for (int j = 0; j < ssz; j++) {
            if (piece[0][i] == stt[j]) exi = 1;
        }
        if (!exi) stt[ssz++] = piece[0][i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10240; j++) dist[i][j] = 103000;
    }
    for (int i = 1; i <= ssz; i++) {
        bfs(stt[i - 1], i);
    }
    for (int i = 0; i < 10240; i++) ed[i].clear();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (piece[i][j] != piece[i + 1][j]) {
                //ed[piece[i][j]].push_back(piece[i + 1][j]);
                ed[piece[i + 1][j]].push_back(piece[i][j]);
            }
        }
    }

    bfs(0, 0);
    if (ssz == 1) printf("%d", dist[1][0]);
    else {
        for (int i = 0; i < 10240; i++) {
            if (dist[0][i] + dist[1][i] + dist[2][i] < res) {
                res = dist[0][i] + dist[1][i] + dist[2][i];
            }
        }
        printf("%d", res);
    }
    return 0;
}