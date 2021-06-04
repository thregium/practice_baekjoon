#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 5000)���� ������ �ִ� Ʈ���� 1�� ��忡�� ����� ��, ���� �� �Ÿ��� �ִ� ����� �Ÿ��� ���Ѵ�.

�ذ� ��� : Ʈ���� ��� ��忡 ���� �Ÿ��� ���캻 ���� ���� �� ���� ū ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, Ʈ��

��ó : ���縯�� 1ȸD2 3��
*/

long long maxdist = 0;
int vis[5120];
vector<pair<int, int>> v[5120];

void dfs(int x, long long dist) {
    vis[x] = 1;
    if (dist > maxdist) maxdist = dist;
    for (pair<int, int> p : v[x]) {
        if (vis[p.first]) continue;
        else dfs(p.first, dist + p.second);
    }
}

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(pair<int, int>(b, c));
        v[b].push_back(pair<int, int>(a, c));
    }
    dfs(1, 0);
    printf("%lld", maxdist);
    return 0;
}