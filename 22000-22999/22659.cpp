#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 100)���� ���ð� �ְ�, ���� ���̿��� K(K < 5000)���� ����� ���η� ���õ��� ����ȴ�.
�̶�, A�� ���ÿ��� H�� ���÷� ������ �̼۽�Ű�� ���� ���� �ð��� ã��, �Ұ����ϴٸ� Help!�� ����Ѵ�.
������ �õ� ���·� ��ݵǾ�� �ϸ�, �õ��� M(M <= 100)�� �ð����� �����ȴ�.
L(L <= N)���� ���ÿ����� ��ð� �ü��� �־ �õ� ���� �ð��� �ð� 1�� 1�� �ø� �� �ִ�.
���ÿ� �����ϴ� ���� �õ��� Ǯ������ ��ð��ü��� �ְų� �������� ������ ��� ��ð� �����ϴ�.

�ذ� ��� : ���ͽ�Ʈ�� ���� �� ���ÿ� �õ� ���� �ð����� �ִ� ���� �ð��� Ȯ���ϸ� ���� ã�Ƴ�����.
�õ� ���� �ð��� ó������ M�̰� �̵��ø��� �̵��� �Ÿ���ŭ �پ���.
��ð� �ü��� �ִٸ� �װ����� ���������� ũ�� M ������ ��� ������ �õ� ���� �ð��� �ٲپ� ����
�ִ� ���� �ð��� �����ϰ� �켱���� ť�� �ִ´�. �� ���ø����� �̵��� �Ϲ� ���ͽ�Ʈ��� ����������
�õ� ���� �ð��� ���� ��� ������.
H�� ������ ���� ���ٸ� �õ��� ������ų �� ���� ���� Help!�� ����ϰ�,
�� �ܿ��� H�� ������ �ִ� �ð� ��� ���� ª�� ���� ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : JAG 2008 D��
*/

int dist[128][128], rerf[128]; //dist: �� ���� ��ȣ�� ���� �ð� �� �Ÿ�, rerf: ��ð� �ü� ����
vector<pair<int, int>> ed[128]; //(���� ����, �Ÿ�)
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq; //(�Ÿ�, (���� ��ȣ, ���� �ð�)) �Ÿ� ª�� �� ����

int main(void) {
    int n, m, l, k, a, h, x, y, t;
    while (1) {
        scanf("%d %d %d %d %d %d", &n, &m, &l, &k, &a, &h);
        if (n == 0) break;
        for (int i = 0; i < l; i++) {
            scanf("%d", &x);
            rerf[x] = 1;
        }
        for (int i = 0; i < k; i++) {
            scanf("%d %d %d", &x, &y, &t);
            ed[x].push_back(pair<int, int>(y, t));
            ed[y].push_back(pair<int, int>(x, t));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dist[i][j] = INF;
            }
        }

        pq.push(make_pair(0, make_pair(a, m)));
        while (pq.size()) {
            t = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();
            if (t > dist[x][y]) continue;
            else dist[x][y] = t;
            if (rerf[x]) {
                //��õ��� ������ ���
                for (int i = y + 1; i <= m; i++) {
                    if (i - y + t < dist[x][i]) {
                        pq.push(make_pair(t + i - y, make_pair(x, i)));
                        dist[x][i] = t + i - y;
                    }
                }
            }
            for (auto &i : ed[x]) {
                if (y - i.second >= 0 && t + i.second < dist[i.first][y - i.second]) {
                    //�ð� m ���� ���� ���ÿ� ���� �����ϸ� �Ÿ��� ���ŵǴ� ���
                    pq.push(make_pair(t + i.second, make_pair(i.first, y - i.second)));
                    dist[i.first][y - i.second] = t + i.second;
                }
            }
        }

        l = INF;
        for (int i = 0; i <= m; i++) {
            if (dist[h][i] < l) l = dist[h][i];
        }

        if (l == INF) printf("Help!\n");
        else printf("%d\n", l);
        
        for (int i = 0; i < n; i++) {
            rerf[i] = 0;
            ed[i].clear();
        }
    }
    return 0;
}
