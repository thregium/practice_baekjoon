#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 200000)���� �������� �̷���� �׷����� �ִ�. 1���� ������ ����ġ�� 1�̰�,
������ ������ ���� ����ġ�� 0�̶�� ��� �������� �ִܰŸ� ���� ���Ѵ�. ��, �׷����� �ݵ�� ���� �׷����� �־�����.

�ذ� ��� : ����ġ�� 1�� ������ �������� �� ������ ���� �׷����� ��쿡�� ���ư��� �ǹǷ� �ִܰŸ� ���� 0�̴�.
������ �������� ��쿡�� ���� �׷��� ���� ����. ����, �� �������� ���� ����� ũ�⸦ ���ϰ�,
N - ũ��� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : ȫ�ʹ� 2021 E��
*/

char vis[103000];
vector<int> ed[103000];

int dfs(int x) {
    int r = 1;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) r += dfs(i);
    }
    return r;
}

int main(void) {
    int n, m, k, u, v;
    long long r;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        if (i == k) continue;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    r = dfs(1);
    printf("%lld", r * (n - r));
    return 0;
}