#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
���� : N(N <= 8) ������ �ڿ����� �̷���� ������ �ִ�. �� �������� K(K <= N)���� ������ ������ ���� ��,
������ �����ϱ� ���� ������� �ϴ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : ������ �������� �����Ƿ� ��� ������ ��쿡 ���� BFS�� �Ÿ��� ���ϸ� �ȴ�.
������ �Ÿ��� �ʿ� �־� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��

��ó : SRM 297 D1 1�� / D2 2��
*/

map<vector<int>, int> dist;
queue<vector<int>> q;

int main(void) {
    int n, k, x;
    vector<int> v, w;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    dist.insert({ v, 0 });
    q.push(v);
    while (q.size()) {
        v = q.front();
        q.pop();
        for (int i = 0; i <= n - k; i++) {
            w = v;
            for (int is = i, ie = i + k - 1; is < ie; is++, ie--) {
                x = w[is];
                w[is] = w[ie];
                w[ie] = x;
            }
            if (dist.find(w) == dist.end()) {
                dist.insert({ w, dist[v] + 1 });
                q.push(w);
            }
        }
    }
    v.clear();
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }
    if (dist.find(v) == dist.end()) printf("-1");
    else printf("%d", dist[v]);
    return 0;
}
