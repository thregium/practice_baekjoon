#include <stdio.h>
#include <vector>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� Ʈ������ �� ���� �մ� ��ο��� ���� ����ġ�� ���� ������ ū ������ ����ġ�� ���Ѵ�.

�ذ� ��� : �� ���� ������ LCA�� ���ϸ鼭 ���� ����ġ�� ���� ������ ���� ū ������ ���� Ȯ���Ѵ�.
��� �迭�� ���� ������ �Բ� ������ �ִ�� �ּ� ����ġ�� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, LCA

��ó : CHCI 2006F2 2��
*/

int level[103000];
vector<pair<int, int>> ed[103000];
tuple<int, int, int> par[103000][20];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

void dfs(int x, int p, int d, int l) {
    par[x][0] = make_tuple(p, d, d);
    level[x] = l;
    for (auto i : ed[x]) {
        if (i.first == p) continue;
        dfs(i.first, x, i.second, l + 1);
    }
}

int main(void) {
    int n, a, b, c, k, lo, hi;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }
    dfs(1, 0, 0, 1);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            get<0>(par[j][i]) = get<0>(par[get<0>(par[j][i - 1])][i - 1]);
            get<1>(par[j][i]) = small(get<1>(par[j][i - 1]), get<1>(par[get<0>(par[j][i - 1])][i - 1]));
            get<2>(par[j][i]) = big(get<2>(par[j][i - 1]), get<2>(par[get<0>(par[j][i - 1])][i - 1]));
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        lo = INF, hi = 0;
        for (int j = 19; j >= 0; j--) {
            if (level[a] - level[b] >= (1 << j)) {
                lo = small(lo, get<1>(par[a][j]));
                hi = big(hi, get<2>(par[a][j]));
                a = get<0>(par[a][j]);
            }
            else if (level[b] - level[a] >= (1 << j)) {
                lo = small(lo, get<1>(par[b][j]));
                hi = big(hi, get<2>(par[b][j]));
                b = get<0>(par[b][j]);
            }
        }
        if (a == b) {
            printf("%d %d\n", lo, hi);
            continue;
        }
        for (int j = 19; j >= 0; j--) {
            if (get<0>(par[a][j]) == get<0>(par[b][j])) continue;
            lo = small(lo, get<1>(par[a][j]));
            hi = big(hi, get<2>(par[a][j]));
            a = get<0>(par[a][j]);
            lo = small(lo, get<1>(par[b][j]));
            hi = big(hi, get<2>(par[b][j]));
            b = get<0>(par[b][j]);
        }
        lo = small(lo, get<1>(par[a][0]));
        hi = big(hi, get<2>(par[a][0]));
        lo = small(lo, get<1>(par[b][0]));
        hi = big(hi, get<2>(par[b][0]));
        printf("%d %d\n", lo, hi);
    }
    return 0;
}