#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100)���� ������� �Ⱦ��ϴ� ���谡 �־��� ��, �Ⱦ��ϴ� ������� ���� ������ ���� �ʵ���
2���� ������ ������ ����� ����Ѵ�. ������ ����� �ݵ�� �����Ѵ�.

�ذ� ��� : �־��� �׷����� �ݵ�� �̺� �׷��� �����̴�. ����, �̺� �׷����� �÷����� �����ϸ�
�װ��� �� ����� ���� ������ �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �̺� �׷���
*/

int color[128], ccnt[2];
vector<int> ed[128];

void dfs(int x, int c) {
    color[x] = c;
    for (int i : ed[x]) {
        if (color[i] < 0) dfs(i, !c);
    }
}

int main(void) {
    int n, m, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            ed[i].push_back(x);
            ed[x].push_back(i);
        }
        color[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] < 0) dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) ccnt[color[i]]++;
    printf("%d\n", ccnt[0]);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) printf("%d ", i);
    }
    printf("\n%d\n", ccnt[1]);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) printf("%d ", i);
    }
    return 0;
}