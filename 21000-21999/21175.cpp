#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;

/*
���� : N(N <= 100)���� �������� �� �׷����� ĥ�ؾ� �Ѵ�. ĥ�ؾ� �ϴ� ������ ������� ���� ĥ�� �� �ִ�.
���� ���� ������� ���� ���������� ĥ�� �� ������, ĥ���� �ʰ� ������ ���� ����.
����, ȥ�յ� ���� ��쿡�� ������� ���ÿ� ���� �������� �������߸� ĥ�� �� �ִٰ� �� ��, ��� ������ ���ϴ´�� ĥ�� �� �ִ��� ���Ѵ�.

�ذ� ��� : �׷��� ���� ������� ��ġ�� �������� ���� ������� �����̴� ���� �������� ����.
����� ������ ������ �� �ִ� �������� ���������� ��ü�� ĥ�غ� ����, ��ĥ�ؾ� �ϴ� ��� ������ ĥ�������� ĥ�� �� �ִ� ���̰�,
ĥ������ ���� ������ �ִٸ� ĥ�� �� ���� ���̴�. ���⼭ ȥ�ջ��� ��쿡�� �� ������ ���� ��ġ�� �ִ� ��� ���ÿ� �������� �ϰ�,
������ ������ Ȯ���ϱ� ������ ������ ���� ��ȣ ���� �߰��ϴ� ���� ����.

�ֿ� �˰��� : �׷��� �̷�, DFS

��ó : PacNW 2020 C/T�� // MidC 2020 E�� // MidA 2020 G��
*/

char vis[128][128][128], evis[10240];
vector<tuple<int, int, char>> cor[128];
vector<int> goal;

void dfs(int r, int y, int b, int c) {
    if (c >= 0) evis[c] = 1;
    if (vis[r][y][b]) return;
    vis[r][y][b] = 1;
    char ch;
    for (int i : vector<int>({ r, y, b })) {
        for (auto j : cor[i]) {
            ch = get<2>(j);
            if ((ch == 'R' || ch == 'X') && i == r) dfs(get<1>(j), y, b, get<0>(j));
            else if ((ch == 'Y' || ch == 'X') && i == y) dfs(r, get<1>(j), b, get<0>(j));
            else if ((ch == 'B' || ch == 'X') && i == b) dfs(r, y, get<1>(j), get<0>(j));
            else if (ch == 'O' && i == r && i == y) dfs(get<1>(j), get<1>(j), b, get<0>(j));
            else if (ch == 'P' && i == r && i == b) dfs(get<1>(j), y, get<1>(j), get<0>(j));
            else if (ch == 'G' && i == y && i == b) dfs(r, get<1>(j), get<1>(j), get<0>(j));
        }
    }
}

int main(void) {
    int n, m, r, b, y, xi, xj, res = 1;
    char c;
    scanf("%d %d %d %d %d", &n, &m, &r, &b, &y);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &xi, &xj, &c);
        cor[xi].push_back(make_tuple(i, xj, c));
        cor[xj].push_back(make_tuple(i, xi, c));
        if (c != 'X') goal.push_back(i);
    }
    dfs(r, y, b, -1);
    for (int i : goal) {
        if (!evis[i]) res = 0;
    }
    printf("%d", res);
    return 0;
}