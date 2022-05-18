#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
���� : N(N <= 10000)���� ������ M(M <= 20000)���� �������� �̷���� ���� �׷����� �־�����.
�� ������ ����ġ(<= 10^6, �ڿ���)�� �� ������ ����ġ(<= 10^6, �ڿ���)�� �־��� ��,
������ ���� �ٸ� �� ���� ���� ����� ����ġ ��� ���� ���� ���� ���Ѵ�.
����� ����ġ�� ������, ������ ����ġ�� ���� ����� ��� ������ ����ġ�� ���� �Ͱ� ����.

�ذ� ��� : ������ �������ϰ� ������ ������, ������ ������ �������� ������.
�� ��, �������� ����ġ�������� ���ͽ�Ʈ�� ���� ����������� �ִܰŸ��� ���Ѵ�.
�� �ִܰŸ� + ������ ����ġ�� �ϸ� ����� ����ġ�� �ǰ�, �ִܰŸ��� �� ���� ����
�ϳ��� ������, ������ �ϳ��� ������ ��� ������ ã�� �ȴ�.
N�� M�� �۱� ������ ����� �̸� �ݺ��ϸ� �ſ� ���� Ȯ���� ������ ã�� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ������ȭ

��ó : CTU 2021 C��
*/

char dir[256];
int vwt[10240], sf[10240], vis[10240];
long long dist[10240];
vector<pair<int, int>> ed[10240];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(void) {
    int n, m, a, b, w, x;
    long long r = INF;
    srand(time(NULL));
    for (int tt = 101; tt <= 138; tt++) {
        //sprintf(dir, "E:\\PS\\ICPC\\Europe\\CTU\\2021\\cruise-in-out\\secret\\%d.in", tt);
        //freopen(dir, "r", stdin);
        r = INF;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &vwt[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &w);
            ed[a].push_back({ b, w });
            ed[b].push_back({ a, w });
        }

        for (int rndn = 0; rndn < 39; rndn++) {
            for (int i = 0; i < n; i++) {
                sf[i] = (rand() & 1);
                vis[i] = 0;
                if (!sf[i]) {
                    pq.push({ vwt[i], i });
                    dist[i] = vwt[i];
                }
                else dist[i] = INF;
            }
            while (pq.size()) {
                x = pq.top().second;
                pq.pop();
                if (vis[x]) continue;
                else vis[x];

                for (auto& i : ed[x]) {
                    if (i.second + dist[x] < dist[i.first]) {
                        dist[i.first] = i.second + dist[x];
                        pq.push({ dist[i.first], i.first });
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (!sf[i]) continue;
                if (vwt[i] + dist[i] < r) r = vwt[i] + dist[i];
            }
        }

        /*
        sprintf(dir, "E:\\PS\\ICPC\\Europe\\CTU\\2021\\cruise-in-out\\secret\\%d.ans", tt);
        freopen(dir, "r", stdin);
        scanf("%d", &x);
        printf("%lld : %d\n", r, x);
        */
        printf("%lld", r);

        for (int i = 0; i < n; i++) {
            ed[i].clear();
        }
        break;
    }
    return 0;
}