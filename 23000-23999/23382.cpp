#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 200000)���� ������ M(M <= 200000)���� �������� �̷���� ���� �׷����� �־��� ��,
�� �׷����� ��� ������ �� ���� �����鼭 ������ ������ �������� �Ÿ��� 3 ������ �湮 ������ ���� ����Ѵ�.

�ذ� ��� : �� �׷����� Ʈ���� �ٲ� ����, ������ ���� ��Ʈ�� �ϰ�, ���̰� Ȧ����°�� ���� ���鼭,
¦����°�� ���� �����鼭 �湮�ϸ� �׻� ��� ��� �Ÿ� 3 �̳��� ��� ���� �湮�� �����ϴ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, Ʈ��

��ó : BAPC 2021 H�� // UKIEPC 2021 H��
*/

int vis0[204800], vis[204800];
vector<int> ed[204800], tred[204800];

void maketree(int x) {
    vis0[x] = 1;
    for (int i : ed[x]) {
        if (!vis0[i]) {
            tred[x].push_back(i);
            maketree(i);
        }
    }
}

void travel(int x, int p, int l) {
    if ((l & 1) && !vis[x]) {
        printf("%d ", x);
        vis[x]++;
    }
    for (int i : tred[x]) {
        if (i == p) continue;
        travel(i, x, l + 1);
    }
    if (!vis[x]) {
        printf("%d ", x);
        vis[x]++;
    }
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    maketree(1);
    travel(1, 0, 1);
    return 0;
}