#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#define INF 103000.0
using namespace std;

/*
���� : 10 * 10 ũ���� ���簢�� ���� �ִ�. �� �� �ȿ� ���� 0�� �̻� 18�� ���Ϸ� �ִ�.
�� ���� Y�࿡ �����ϰ�, ������ 2�� �ִ�. �� ���� X��ǥ�� ������ ���۰� ���� Y��ǥ���� �־��� ��,
(0, 5) ��ġ���� (10, 5) ��ġ�� �̵��ϴµ� ��� �ִܰŸ��� ���Ѵ�.

�ذ� ��� : �� ������ ������ �� ���� �� �� ��ġ�� Ȯ���Ѵ�. ������ �Ǵ� �������� �ǹ� �ִ� ����
�ش� ��ҵ� ������ �� �� �ִ�. ����, �� ���� �̿��� ���ͽ�Ʈ�� �Ѵ�.
������, ������ ������ ��� ������ ���̿� ���� �̵��� �������� Ȯ���ϰ�, �̵��� �����ϴٸ� �ش� �� ���̸� �������� �մ´�.
�� �� �ش� �������� �̿��� ���������� ���������� �Ÿ��� ���ͽ�Ʈ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ������

��ó : MidC 1996 B��
*/

double wall[32][8], dist[32][8];
vector<pair<double, pair<int, int>>> ed[32][8];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getdist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double getcross(double x1, double y1, double x2, double y2, double xp) {
    return y1 + (y2 - y1) / (x2 - x1) * (xp - x1);
}

void initdist(int n) {
    //���� �̵� ������ �� ������ �Ÿ��� ���Ѵ�.
    int t;
    double cross;
    for (int i = 1; i <= 4; i++) {
        wall[0][i] = 5.0;
        wall[n + 1][i] = 5.0;
    }
    wall[n + 1][0] = 10.0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 8; j++) {
            ed[i][j].clear();
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int ii = 1; ii <= 4; ii++) {
            for (int j = i + 1; j <= n + 1; j++) {
                for (int jj = 1; jj <= 4; jj++) {
                    //�������� ������ ������ ��� ������ �� �� ���̸� �̾��.
                    t = 0;
                    for (int k = i + 1; k < j; k++) {
                        cross = getcross(wall[i][0], wall[i][ii], wall[j][0], wall[j][jj], wall[k][0]);
                        if (cross < wall[k][1] || cross > wall[k][4] || (cross > wall[k][2] && cross < wall[k][3])) {
                            t = 1; //�߰��� ���� �ɸ� ��� �̵� �Ұ����ϴ�.
                            break;
                        }
                    }
                    if (t) continue;
                    ed[i][ii].push_back(pair<double, pair<int, int>>(getdist(wall[i][0], wall[i][ii], wall[j][0], wall[j][jj]),
                        pair<int, int>(j, jj))); //�̵� ������ ��� ������ �߰��Ѵ�.
                }
            }
        }
    }
}

void solve(int n) {
    //���ͽ�Ʈ�� ���� ������������ �Ÿ��� ���Ѵ�.
    int x, y;
    double d;
    dist[0][1] = 0.0;
    pq.push(pair<double, pair<int, int>>(0.0, pair<int, int>(0, 1)));
    while (pq.size()) {
        x = pq.top().second.first;
        y = pq.top().second.second;
        d = pq.top().first;
        pq.pop();
        for (auto i : ed[x][y]) {
            if (dist[i.second.first][i.second.second] > d + i.first) {
                dist[i.second.first][i.second.second] = d + i.first;
                pq.push(pair<double, pair<int, int>>(d + i.first, pair<int, int>(i.second.first, i.second.second)));
            }
        }
    }
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 4; j++) {
                scanf("%lf", &wall[i][j]);
            }
        }
        qsort(wall + 1, n, sizeof(double) * 8, cmp1); //���� ������ �������ش�.
        initdist(n);
        solve(n);
        printf("%.2f\n", dist[n + 1][1]);
    }
    return 0;
}