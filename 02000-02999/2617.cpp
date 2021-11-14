#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : ���԰� ���� �ٸ� N(N < 100, Ȧ��)���� ������ Mȸ�� �񱳰� �־��� ��, ���԰� �߾Ӱ��� �� �� ���� ������ ������ ���Ѵ�.

�ذ� ��� : �� ������ ���� Ȯ���� �� ���ſ� ������ ���� ������ ������ ���� ���� ���Ѵ�. �� �� �� ������ N / 2����
ū ���� ���´ٸ� �� ������ �߾Ӱ��� ������ �ƴϴ�. Ȯ���� ���ſ� ������ �� ������ ���� �� ���ſ� ������ ���⸸����
DFS�� �ϸ� �湮�ϰ� �Ǵ� �������̴�. ������ ������ ���� �ݴ�� �ϸ� ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : ���� 2003 ��1��
*/

vector<int> v1[512], v2[512];
int vis[512];

int dfs1(int a) {
    int r = 1;
    vis[a] = 1;
    for (int i = 0; i < v1[a].size(); i++) {
        if (!vis[v1[a][i]]) r += dfs1(v1[a][i]);
    }
    return r;
}

int dfs2(int a) {
    int r = 1;
    vis[a] = 1;
    for (int i = 0; i < v2[a].size(); i++) {
        if (!vis[v2[a][i]]) r += dfs2(v2[a][i]);
    }
    return r;
}

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (dfs1(i) - 1 > (n >> 1) || dfs2(i) - 1 > (n >> 1)) r++;
        for (int j = 0; j <= n; j++) vis[j] = 0;
    }
    printf("%d", r);
    return 0;
}