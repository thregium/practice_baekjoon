#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 200000)���� ������ �����ϰ�, �� ����� �� ���� Ȥ�� �Ϻο� ���� �����ǰ� M(M <= 200000)���� �����Ѵ�.
�� �����Ǵ� K(K < N)���� ���� �ٸ� ������ ������ � ��ῡ ������ ���� ���� R�� �����,
��� �����ǿ� ���� ������ ���� �ִ� 400000���̴�. ó�� �ִ� ������ ����� ��ġ�� �ʰ� �־��� ��, ���� �� �ִ� ���
������ ������ ���Ѵ�. ��, ó���� �ִ� ������ ���Ѵ�� �� �� ������, ���� ������ ���࿡ ���� �����ǰ� ���� �� ���� �� �ִ�.

�ذ� ��� : �� ���࿡�� �����Ǹ� ���� ������ �̾� ������ ���� ���迡 ���� �׷����� �����.
�̶� ���� ������ ���࿡ ���� �����ǰ� ���� �� ���� �� �����Ƿ� ������ �ƴ� �����Ǹ� ���ؾ� �Ѵ�. �� �������� �������
�迭�� ������ ������ �ȴ�. �׷����� ���� �������� ó���� �ִ� ������� ť�� ���� ����, �������� ������ BFS�� ������ �ȴ�.
���� Ȯ������ �������� ���� �� �ִ� ��� �����ǵ鿡 ���� ���������� 1 ���ҽ�Ų �� ���������� 0�� �� �����ǵ��� Ȯ���ϸ�
���� Ȯ������ ���� ������ �����Ƕ�� ť�� �ٽ� ����ִ´�. �̸� ť�� �� �� ���� �ݺ��� ����
���ݱ��� Ȯ���ߴ� ������� ������������ �ٽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���� ����

��ó : ��ϴ� 2020 H��
*/

int x[204800], ins[204800], vis[204800], dest[204800];
vector<int> make[204800], res;
unordered_set<int> us[204800];
queue<int> q;

int main(void) {
    int n, m, k, r, p;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x[j]);
        }
        scanf("%d", &r);
        dest[i] = r;
        for (int j = 0; j < k; j++) {
            if (us[x[j]].find(i) != us[x[j]].end()) continue;
            make[x[j]].push_back(i);
            us[x[j]].insert(i);
            ins[i]++;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &p);
        if (us[0].find(p) != us[0].end()) continue;
        us[0].insert(p);
        q.push(p);
        vis[p] = 1;
    }
    while (q.size()) {
        p = q.front();
        res.push_back(p);
        q.pop();
        for (int i : make[p]) {
            ins[i]--;
            if (ins[i] == 0 && !vis[dest[i]]) {
                q.push(dest[i]);
                vis[dest[i]] = 1;
            }
        }
    }
    printf("%d\n", res.size());
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
        if (i > 0 && res[i] == res[i - 1]) return 1;
    }
    return 0;
}