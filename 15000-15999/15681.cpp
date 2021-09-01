#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� Ʈ������ ������ ���� R�� ��Ʈ�̴�. �̶�, Q(Q <= 100000)���� ������ �����Ѵ�.
���� U�� ��Ʈ�� �ϴ� ����Ʈ���� ���ϴ� ������ ���� ���Ѵ�.

�ذ� ��� : ������ Ʈ��DP�� ���� ���� ���� �� �ִ�. �ش� ����� ��� �ڽ� ����� ����� 1�� ���� ���� �� ������ ���� �ȴ�.
��� ������ ���� �����ϰ� ������ ���� �� ���� ������ �����ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ʈ��DP

��ó : ������ 2018 PC��
*/

int mem[103000], vis[103000];
vector<int> ed[103000];

int dp(int x) {
    int r = 1;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (vis[i]) continue;
        r += dp(i);
    }
    return mem[x] = r;
}

int main(void) {
    int n, r, q, u, v;
    scanf("%d %d %d", &n, &r, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    dp(r);
    for (int i = 0; i < q; i++) {
        scanf("%d", &u);
        printf("%d\n", mem[u]);
    }
    return 0;
}