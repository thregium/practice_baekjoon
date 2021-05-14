#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : Ʈ������ �� ���� ������ �̾Ƽ� ��� ������ ���� �����̰ų� ���� ������ �����ϵ��� �� ��, �̾ƾ� �� ������ �ּ� ������ ���Ѵ�.

�ذ� ��� : �� ������ ���� ���� ���� ���� ���� ������ �����Ѵ�. �ش� ������ ���� ��쿡�� ��� �ڽĳ�忡 ����
���� ���� ���� ���� ��� �� �� ���� ���� ������� �����ؼ� ���ϸ� �ǰ�, ���� ���� ��쿡�� ��� �ڽĳ�忡 ���� ���� ����� ���� ���Ѵ�.
�̸� �ݺ��� ��Ʈ ������ ���� ���� ���� ��Ʈ ��忡�� �� �� �� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ʈ��DP

��ó : ���� 2012�� ��4��
*/

int parents[1048576], early[1048576], notearly[1048576];
vector<int> edge[1048576];

int small(int a, int b) {
    return a < b ? a : b;
}

void dfs(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == parents[x]) continue;
        parents[edge[x][i]] = x;
        dfs(edge[x][i]);
    }
}

void earlyneed(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == parents[x]) continue;
        earlyneed(edge[x][i]);
    }
    int e = 1;
    int ne = 0;
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == parents[x]) continue;
        e += small(early[edge[x][i]], notearly[edge[x][i]]);
        ne += early[edge[x][i]];
    }
    early[x] = e;
    notearly[x] = ne;
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);
    earlyneed(1);
    printf("%d", small(early[1], notearly[1]));
    return 0;
}