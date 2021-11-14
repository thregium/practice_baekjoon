#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 3000)���� �������� �̷���� �׷������� ��� ������ ��� ������ ������
���� ������ ���� �� ������ �ʴ� ��ΰ� �ִ��� ���Ѵ�.

�ذ� ��� : �Ѻױ׸��Ⱑ �������� ���� �����̴�. �̾��� ������ ������ Ȧ���� ������ 2�� ������ ��� �����ϴ�.
��, ��� �������� ���� ���� ��ҿ� �־�� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���Ϸ� ȸ��

��ó : ���Ǵ�/�߾Ӵ� 2018 D��
*/

char vis[3072];
vector<int> ed[3072];

void dfs(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) dfs(i);
    }
}

int main(void) {
    int v, e, va, vb, o = 0;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &va, &vb);
        ed[va].push_back(vb);
        ed[vb].push_back(va);
    }
    for (int i = 1; i <= v; i++) {
        o += (ed[i].size() & 1);
    }
    if (o > 2) {
        printf("NO");
        return 0;
    }
    dfs(1);
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}