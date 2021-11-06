#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : ���� H(1000 < H <= 30000)���� �ö󰡷��� �Ѵ�. �߰� ������ F(F <= 10000)�� �ִ�.
�� ������ ���̴� �Ÿ��� 1000 ������ ��� ���� �̵��� �����ϴ�. ó������ 1000 ������ ���̿� �ִ� �������� ����� �� �ְ�,
���� H - 1000 �̻��� ������ �����ϸ� ����⿡ �ö� �� ���� ��, ����⿡ �ö󰡱� ���� �������� �ϴ�
������ �ּ� ������ ���Ѵ�. ��, �׻� ����⿡ ���� ������ ��츸 �־�����.

�ذ� ��� : �� ������ ��ǥ�� �Է¹��� ��, ������� ������ �������� ��� ���ϰ� ��Ÿ����� ������ �̿���
��� ���� �ֿ� ���� �̵� �������� Ȯ���Ѵ�. �� �̵� ������ ���� ���� �������� �Ͽ� ��������� BFS�� ���� ����,
�������� �� �� �ִ� ������ �������� �� ������ �Ÿ��� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��Ÿ��� ����

��ó : USACO 2006O S3��
*/

int hh[10240][2], dist[10240], vis[10240];
vector<int> ed[10240];
queue<int> q;

int getdist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int bfs(int h) {
    int x, d;
    while (q.size()) {
        x = q.front();
        d = dist[x];
        if (hh[x][1] + 1000 >= h) return d;
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = d + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int main(void) {
    int h, f, r;
    scanf("%d %d", &h, &f);
    for (int i = 0; i < f; i++) {
        scanf("%d %d", &hh[i][0], &hh[i][1]);
        if (hh[i][1] <= 1000) {
            q.push(i);
            vis[i] = 1;
        }
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < f; j++) {
            if (i == j) continue;
            if (getdist(hh[i][0], hh[i][1], hh[j][0], hh[j][1]) <= 1000000) ed[i].push_back(j);
        }
    }
    r = bfs(h);
    if (r < 0) return 1;
    printf("%d", r + 1);
    return 0;
}