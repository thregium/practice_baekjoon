#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� ������� M(M < N)���� �ٿ� ���ִ�. �� ���� ù ��� ��� �켱������ �����
���� �켱������ ���� ������� ���ʷ� ���ٰ� �� ��, K + 1��° ����� �� ��°�� ���� �Ǵ� �� ���Ѵ�.

�ذ� ��� : �켱���� ť�� �̿��Ѵ�. ���� ���� �̿��� �켱������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �켱���� ť

��ó : SSC 2020B E��
*/

int lend[103000];
vector<pair<int, int>> line[103000];
priority_queue<pair<pair<int, int>, int>> pq;

int main(void) {
    int n, m, k, ln, targ, x, r = 0;
    pair<int, int> p;
    scanf("%d %d %d", &n, &m, &k);
    ln = k % m;
    targ = k / m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p.first, &p.second);
        line[i % m].push_back(p);
        if (i < m) pq.push({ p, -i });
    }
    while (1) {
        x = -(pq.top().second);
        pq.pop();
        if (x == ln && lend[x] == targ) break;
        if ((lend[x] + 1) * m + x < n) {
            pq.push({ line[x][lend[x] + 1], -x });
            lend[x]++;
        }
        r++;
    }
    printf("%d", r);
    return 0;
}