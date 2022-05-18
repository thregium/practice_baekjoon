#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� Ʈ���� �־�����. �� �������� ������ e_i(e_i <= 100000)��
���̵��� �ִ�. Ʈ���� �� ������ 10000 ������ �����̰�, ������ ������ �� ��� �������� ������ ���̿� ����.
�̶�, ��� ���̵��� �������� �ִ��� ����� 1�� �������� �ִܰŸ��� �̵��Ѵٸ�
�� ���̵��� ���ߴ� ������ ��ȣ�� ���� ����Ѵ�.

�ذ� ��� : ��� �迭�� �̿��� �ذ� �����ϴ�. �� �������� 2^i�� ���� ������ �ű������ �Ÿ���
������ ����, �������� �������� �Ǵ� ��� �ö󰡸鼭 �ö� ������ ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �ڷ� ����, ��� �迭

��ó : ������ 2017M H��
*/

int eng[103000], par[24][103000];
long long cost[24][103000];
vector<pair<int, int>> ed[103000];

void dfs(int x, int p) {
    for (auto& i : ed[x]) {
        if (i.first == p) continue;
        par[0][i.first] = x;
        cost[0][i.first] = i.second;
        dfs(i.first, x);
    }
}

int main(void) {
    int n, a, b, c, pos;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &eng[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }
    dfs(1, -1);
    par[0][1] = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (!par[i - 1][j]) par[i][j] = 0;
            else {
                par[i][j] = par[i - 1][par[i - 1][j]];
                cost[i][j] = cost[i - 1][par[i - 1][j]] + cost[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        pos = i;
        for (int j = 20; j >= 0; j--) {
            if (!par[j][pos]) continue;
            if (eng[i] >= cost[j][pos]) {
                eng[i] -= cost[j][pos];
                pos = par[j][pos];
            }
        }
        printf("%d\n", pos);
    }
    return 0;
}