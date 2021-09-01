#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 1000)���� �������� �̷���� �׷������� �� ������ 1�� �������� ����ϴ� K(K <= 100)��° �ִܰ�θ� ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� �����ϵ�, �ִܰŸ��� �����ϴ� �迭�� �ִܰŸ� ���� ���� ���� �� �ֵ���
�ִ� ���� ���·� �����Ѵ�. �ִܰŸ��� �����ϰ� �Ǵ� ���� ���� ũ�Ⱑ K �̸��̰ų� �Ÿ��� ���� �ִ񰪺��� ���� ����̴�.
���� �Ÿ��� ������� ����, ũ�Ⱑ K�� �Ѿ�� ������ �ִ��� ���д�. �� ����, ��ü ť�� �ش� ��ġ�� ���� ����ְ�
���ͽ�Ʈ�� ��� �����Ѵ�. �׷��� ��� ���� K��° ���� �ִܰ�θ� ���� �� �ִ�.

����� Ȯ���� ������ �� ������ ���� ���� ũ�Ⱑ K���� Ȯ���Ѵ�. �� �̸��� ��� �ش� ������ �����ϴ� ��ΰ� K�� ������ ���̴�.
���� K��� ���� �ִ��� ���� �ȴ�.


�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, �켱���� ť
*/

vector<pair<int, int>> roads[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> dist[1024];

int main(void) {
    int n, m, k, a, b, c;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        roads[a].push_back(pair<int, int>(b, c));
    }
    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        a = pq.top().second;
        c = pq.top().first;
        pq.pop();
        if (dist[a].size() < k || c < dist[a].top()) dist[a].push(c);
        else continue;
        for (auto i : roads[a]) {
            if (dist[i.first].size() < k || c + i.second < dist[i.first].top()) {
                pq.push(pair<int, int>(c + i.second, i.first));
                if (dist[i.first].size() > k) pq.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) printf("-1\n");
        else printf("%d\n", dist[i].top());
    }
    return 0;
}
