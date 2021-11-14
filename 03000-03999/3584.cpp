#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 10000)���� �������� �̷���� Ʈ���� �־�����, �� ������ �־�����
�� ���� ���� Ʈ���� ���� ���� ��� ���� ���� ���� �ִ� ���� ���Ѵ�.

�ذ� ��� : �켱 �� ������ �θ� ��带 ���Ѵ�. �� ����, Ʈ���� ������ ��忡�� �����
���̻� �θ� ��尡 ���� ��Ʈ ��忡 �����ϸ� �ش� ��Ʈ���� �����ؼ� �� ������ ������ ���Ѵ�.
������ ���� ����, �� ���� ��� ������ ���� �������� �θ� ���� ���ư��� ������ ���� ������ ������ �����.
�׸��� ���� ��尡 ������ �� ���� �� ������ �θ�� ���� ���� �ݺ��Ѵ�.

�� ��尡 ������ ���� ��尡 �ּ� ���� �����̴�.
�ʱ�ȭ�� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, Ʈ��, LCA

��ó : Daejeon 2002 A��
*/

int par[10240], level[10240];
vector<int> child[10240];

void dfs(int x, int lv) {
    level[x] = lv;
    for (int i : child[x]) {
        if (!level[i]) dfs(i, lv + 1);
    }
}

int main(void) {
    int t, n, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            child[a].push_back(b);
            par[b] = a;
        }
        a = 1;
        while (par[a]) a = par[a];
        dfs(a, 1);
        scanf("%d %d", &a, &b);
        while (level[b] > level[a]) b = par[b];
        while (level[a] > level[b]) a = par[a];
        while (a != b) {
            a = par[a];
            b = par[b];
        }
        printf("%d\n", a);

        for (int i = 1; i <= n; i++) {
            par[i] = 0;
            level[i] = 0;
            child[i].clear();
        }
    }
    return 0;
}