#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 1000)���� ����� �ְ�, 2���� ������ ���� M��, P(N <= M, P <= 1000)�� �ִ�.
�� ���ǵ��� 2���� ������ ���� 10000 ���� ���� ���� �ִ�.
�̶�, �� ����� ���� ����� ���ǰ� ����� �ֺ��� ���ʷ� ��Ī��ų ��, ��� ��Ī�� �Ÿ� ���� ���Ѵ�.
���� ����� ���� ������ ��� �� ��ȣ�� ��� ����, ������ �����̶�� �� ��ȣ�� ���� ���� ��Ī��Ų��.

�ذ� ��� : �켱���� ť�� ��� ��ġ�� ���� ���� ���� ������ ��Ƶΰ� �� ��ġ�� ����
����� ������ ��ġ���� ���� ��� �� �Ÿ��� ����� ���ϰ� ����� ������ �湮 ó���� �Ѵ�.
�̸� �� ���� ���ǿ� ���� �ݺ��ϰ� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �켱���� ť

��ó : ECNA 2019 A��
*/

int posj[1024][2], post[1024][2], chkj[1024], chkt[1024];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;

double getdist(int a, int b) {
    return sqrt(pow(abs(posj[a][0] - post[b][0]), 2) + pow(abs(posj[a][1] - post[b][1]), 2));
}

int main(void) {
    int n, m, p, a, b;
    double dist, res = 0.0;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &posj[i][0], &posj[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &post[i][0], &post[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pq.push({ getdist(i, j), {i, j} });
        }
    }
    while (pq.size()) {
        a = pq.top().second.first;
        b = pq.top().second.second;
        dist = pq.top().first;
        pq.pop();
        if (chkj[a] || chkt[b]) continue;
        res += dist;
        chkj[a] = 1, chkt[b] = 1;
    }
    for (int i = 0; i < 1024; i++) {
        chkj[i] = 0, chkt[i] = 0;
    }

    for (int i = 0; i < p; i++) {
        scanf("%d %d", &post[i][0], &post[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            pq.push({ getdist(i, j), {i, j} });
        }
    }
    while (pq.size()) {
        a = pq.top().second.first;
        b = pq.top().second.second;
        dist = pq.top().first;
        pq.pop();
        if (chkj[a] || chkt[b]) continue;
        res += dist;
        chkj[a] = 1, chkt[b] = 1;
    }
    printf("%.9f", res);
    return 0;
}