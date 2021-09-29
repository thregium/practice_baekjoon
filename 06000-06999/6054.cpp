#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 1000)���� �̾�޸��⸦ �Ѵ�. �� ����� �� ������ ���µ� �ɸ��� �ð��� L_i(L_i <= 1000)�̰�,
�� ����� M_i���� �ٸ� ������� ������ �Ѱ��ش�. ��, �̹� �� �� �� ����� �ٽ� ���� �ʴ´�.
1�� ������� ����� ��, ��� ����� �����ϴµ� �ɸ��� �ð��� ���Ѵ�. ��� ����� �� ������ ���� ����ȴ�.

�ذ� ��� : 1�� ������� �� ����, �ٸ� ����鿡�� ������ �Ѱ��ִ� ������ �켱���� ť�� �̿��� �����Ѵ�.
�� ���� �� ����� ������ �ð��� �켱���� ť�� ���� ����, ���� ���� �����ϴ� ������� ���ʷ� ������ �ѱ��.
������ �Ѱܹ��� ����� ���� �� �ִ� ���� ���� �ð��� ������ �ް� �ȴ�. �׷��� �� ���� �� ����,
������ �ٽ� �Ѱ��ִ� ���� �ݺ��Ѵ�.
��� ����� ������ ������ ������ �ð� ��� ���� ���� ���� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, �켱���� ť

��ó : USACO 2010O B3��
*/

int finished[1024], lap[1024], sign[1024][1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, x, t, res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &lap[i], &sign[i][0]);
        for (int j = 1; j <= sign[i][0]; j++) {
            scanf("%d", &sign[i][j]);
        }
        finished[i] = INF;
    }

    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        x = pq.top().second;
        t = pq.top().first;
        pq.pop();
        if (x > 1 && t + lap[x] >= finished[x]) continue;
        else finished[x] = t + lap[x];
        for (int i = 1; i <= sign[x][0]; i++) {
            if (finished[sign[x][i]] > t + lap[x]) {
                pq.push(pair<int, int>(t + lap[x], sign[x][i]));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (finished[i] > res) res = finished[i];
    }
    printf("%d", res);
    return 0;
}