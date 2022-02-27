#include <stdio.h>
#include <vector>
#include <queue>
#define INF 0x7A35090F
using namespace std;

/*
���� : N(N <= 200000)���� ���ÿ� �� ���� ���� M(M <= 200000)���� ��ΰ� �ִ�. �� ��� ���̸� ������ ����
�����(<= 10000)�� ���� �Ѵ�. 7�� ���ÿ��� �巡�ﺼ�� �ְ�, ���� 1�� ���ÿ� �ִ�.
��� ������ �巡�ﺼ�� ������ ���� ���� �ϴ� �ּ� ����� ���Ѵ�. ��, �巡�ﺼ ���� ����
���� ���ÿ� ���� �� �ִ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.

�ذ� ��� : 1�� ���ÿ� �巡�ﺼ�� �ִ� ���ÿ��� ��� ���÷��� �ּ� �����
���ͽ�Ʈ�� �˰����� �̿��� ã��, ��� �巡�ﺼ�� ã�� ����� ���Ʈ ������ ���� �õ��� ���鼭
������ ����� �ּ� ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ���Ʈ ����

��ó : MidC 2019 F��
*/

char vis[204800], chk[8];
int ball[8], dist[8][204800];
long long best = 1234567890987654321;
vector<pair<int, int>> ed[204800];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void track(int x, int c, long long r) {
    if (c == 8) {
        if (r < best) best = r;
        return;
    }
    for (int i = 1; i <= 7; i++) {
        if (chk[i]) continue;
        if (dist[x][ball[i]] == INF) continue;
        chk[i] = 1;
        track(i, c + 1, r + dist[x][ball[i]]);
        chk[i] = 0;
    }
}

int main(void) {
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        ed[a].push_back(pair<int, int>(b, t));
        ed[b].push_back(pair<int, int>(a, t));
    }
    for (int i = 1; i <= 7; i++) {
        scanf("%d", &ball[i]);
    }
    ball[0] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            vis[j] = 0;
        }
        dist[i][ball[i]] = 0;
        pq.push(pair<int, int>(0, ball[i]));
        while (pq.size()) {
            a = pq.top().second;
            t = pq.top().first;
            pq.pop();
            if (vis[a]) continue;
            else vis[a] = 1;
            for (auto& j : ed[a]) {
                if (dist[i][a] + j.second < dist[i][j.first]) {
                    dist[i][j.first] = dist[i][a] + j.second;
                    pq.push(pair<int, int>(dist[i][j.first], j.first));
                }
            }
        }
    }
    track(0, 1, 0);
    printf("%lld", best == 1234567890987654321 ? -1 : best);
    return 0;
}