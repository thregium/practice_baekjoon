#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : ���� N(N <= 2000)��, ���� M(M <= 50000)���� ���� ����ġ �׷������� ���� S���� ����� G-H�� �մ� ������ ������
�ִܰ�ΰ� �ִ� ������ C(C <= 100)���� ���� �߿��� ��� ã�´�. �̸� T(T<= 100)ȸ �ݺ��Ѵ�. �� ������ ����ġ�� 1000 �����̴�.

�ذ� ��� : ��� �������� �Է¹��� ���� �� ������ ����ġ�� 2��� �ø���. �� ���� G-H�� �մ� ������ ����ġ�� 1 ���δ�.
�׷��� �Ǹ� S���� ����� �ִܰŸ��� G-H�� ������(�Ǵ� �ִܰŸ� �� �ϳ���) ��� �������� ����ġ�� Ȧ���� �ǰ�
������ �������� ����ġ�� ¦���� �ȴ�. �� ���¿��� ���ͽ�Ʈ�� ���� �� ����ġ�� Ȧ���� �������� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : BAPC 2013 D��
*/

int dist[2048], cand[128], res[128];
vector<pair<int, int>> ed[2048];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, c, s, g, h, a, b, d;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &m, &c);
        scanf("%d %d %d", &s, &g, &h);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &d);
            if ((a == g && b == h) || (a == h && b == g)) {
                ed[a].push_back(pair<int, int>(d * 2 - 1, b));
                ed[b].push_back(pair<int, int>(d * 2 - 1, a));
            }
            else {
                ed[a].push_back(pair<int, int>(d * 2, b));
                ed[b].push_back(pair<int, int>(d * 2, a));
            }
        }
        for (int i = 0; i < c; i++) {
            scanf("%d", &cand[i]);
        }

        b = 0;
        for (int i = 1; i <= n; i++) dist[i] = INF;
        pq.push(pair<int, int>(0, s));
        while (pq.size()) {
            a = pq.top().second;
            d = pq.top().first;
            pq.pop();
            if (d >= dist[a]) continue;
            dist[a] = d;
            for (int i = 0; i < ed[a].size(); i++) {
                pq.push(pair<int, int>(ed[a][i].first + d, ed[a][i].second));
            }
        }
        for (int i = 0; i < c; i++) {
            if (dist[cand[i]] == INF) continue;
            if (dist[cand[i]] & 1) res[b++] = cand[i];
        }
        qsort(res, b, sizeof(int), cmp1);
        for (int i = 0; i < b; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");

        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}