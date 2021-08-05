#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : R * C(R, C <= 1000) ũ���� ������ ���ٵ��� �ִ�. �������� ��� ���� ���ٿ��� �ٸ� ���� �������� �̵��Ϸ� �Ѵ�.
�̶�, ���� ���ٸ� ������ �̵��ϰ�, �ֺ� 5 * 5 ���� ���� �̵� �����ϸ�, �� �̵����� ������ ������ �Һ��� �����Ѵٸ�,
�ش� �������� �� �� �ִ��� Ȯ���ϰ�, �����ϴٸ� �׶��� �ּ� ������ �Һ��� ���Ѵ�.
���� ������ W(W <= 1000)���� ���簢�� ���� ���·� �־�����.

�ذ� ��� : 2���� ���� ���� �̿��� �� ĭ�� ���� ���ٿ� ���Ե� Ƚ���� ���Ѵ�. �� Ƚ���� 0�� ������ ���� ������ ���̴�.
�� �������δ� ���� ���ٺ��� ���� ���ٱ����� �ִܰŸ��� ���ͽ�Ʈ�� ���� ã���� �ȴ�.
�̶�, �ð����ѻ� �̸� �ִܰŸ� ������ �켱���� ť�� ������ ������Ʈ�� �ָ�, �����ִ� �������� �ʴ� ���� �������� ����
����� �� ������ ã�Ƴ��� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ����ȭ

��ó : Latin 2006 B��
*/

short wc[1024][1024], wet[1024][1024];
int dist[1024][1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
long long moves[5][5] = { {7, 6, 5, 6, 7}, {6, 3, 2, 3, 6}, {5, 2, 0, 2, 5}, {6, 3, 2, 3, 6}, {7, 6, 5, 6, 7} };

int main(void) {
    long long r, c, rs, cs, re, ce, w, x1, y1, x2, y2;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2006\\frog.in", "r", stdin);
    while (1) {
        scanf("%lld %lld", &r, &c);
        if (r == 0) break;
        for (long long i = 1; i <= r; i++) {
            for (long long j = 1; j <= c; j++) {
                wc[i][j] = 0;
                wet[i][j] = 0;
                dist[i][j] = INF;
            }
        }
        scanf("%lld %lld %lld %lld", &rs, &cs, &re, &ce);
        pq.push(pair<int, int>(0, (rs << 10) + cs));
        scanf("%lld", &w);
        for (long long i = 0; i < w; i++) {
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            /*for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    wet[x][y] = 1;
                }
            }
        }
        */
            
            wc[x1][y1]++;
            wc[x1][y2 + 1]--;
            wc[x2 + 1][y1]--;
            wc[x2 + 1][y2 + 1]++;
        }
        for (long long i = 1; i <= r; i++) {
            for (long long j = 1; j <= c; j++) {
                wet[i][j] = wet[i][j - 1] + wc[i][j];
            }
        }
        for (long long i = 1; i <= c; i++) {
            for (long long j = 1; j <= r; j++) {
                wet[j][i] += wet[j - 1][i];
            }
        }
        
        while (!pq.empty()) {
            x1 = (pq.top().second >> 10);
            y1 = (pq.top().second & 1023);
            w = pq.top().first;
            pq.pop();
            if (w > dist[x1][y1]) continue;
            else dist[x1][y1] = w;
            if (x1 == re && y1 == ce) break;
            for (long long i = 0; i < 5; i++) {
                for (long long j = 0; j < 5; j++) {
                    if (!moves[i][j]) continue;
                    x2 = x1 + i - 2;
                    y2 = y1 + j - 2;
                    if (x2 < 1 || y2 < 1 || x2 > r || y2 > c || wet[x2][y2]) continue;
                    if (dist[x2][y2] > w + moves[i][j]) {
                        pq.push(pair<int, int>(w + moves[i][j], (x2 << 10) | y2));
                        dist[x2][y2] = w + moves[i][j];
                    }
                }
            }
        }
        while (pq.size()) pq.pop();
        if (dist[re][ce] == INF) printf("impossible\n");
        else printf("%d\n", dist[re][ce]);
    }
    return 0;
}