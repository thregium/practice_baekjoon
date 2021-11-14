#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 5000)���� ������ ���� Ʈ������ �� �������� ����ġ(<= 10^9)�� �־�����. �̶�, �� ���� ������ ����ġ��
�ִ� ����� ����ġ ��� �ּ� ����ġ�� ���ǵȴٸ� ���� v���� ����ġ�� K(K <= 10^9) �̻��� ������ ������ Q(Q <= 5000)�� ���Ѵ�.

�ذ� ��� : V���� DFS�� �ϸ鼭 ����ġ�� K �̻��� �������� ������ �� �� �ִ� ������ ������ ���ϸ� �ȴ�.
�Ź� �湮 üũ�� �缳�� ����� �Կ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, Ʈ��

��ó : USACO 2018J S3��
*/

int vis[5120];
vector<pair<int, int>> ed[5120];

int dfs(int k, int x) {
    int r = 1;
    vis[x] = 1;
    for (auto i : ed[x]) {
        if (vis[i.first] || i.second < k) continue;
        r += dfs(k, i.first);
    }
    return r;
}

int main(void) {
    int n, q, a, b, c;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }
    for (int qq = 0; qq < q; qq++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dfs(a, b) - 1);
        for (int i = 1; i <= n; i++) vis[i] = 0;
    }
    return 0;
}