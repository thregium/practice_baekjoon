#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : ������ V(V <= 10000)���� �׷������� ��� SCC���� �����Ѵ�.

�ذ� ��� : Ÿ�� �˰����� �̿��Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, SCC
*/

int order[10240], stack[10240], fin[10240];
int cnt = 1, sp = 0, cp = 0;
vector<int> edge[10240], scc[10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int dfs(int x) {
    //���� ������ ���� �� ������ ��ȯ, ���� ���� �ܿ� ���� ��� SCC ����
    order[x] = cnt++;
    stack[sp++] = x;

    int r = order[x];
    for (int nxt : edge[x]) {
        //������ �����鿡 ���� üũ
        if (order[nxt] == 0) r = small(r, dfs(nxt)); //���� �湮���� ���� ������ ���
        else if (!fin[nxt]) r = small(r, order[nxt]); //���� SCC�� ���� ���� ������ ���
    }

    if (r == order[x]) {
        //SCC ����
        while (1) {
            scc[cp].push_back(stack[--sp]);
            fin[stack[sp]] = 1;
            if (stack[sp] == x) break; //X�� ���� �� ���� ������ ���ҵ��� ����
        }
        sort(scc[cp].begin(), scc[cp].end());
        cp++;
    }

    return r;
}

int main(void) {
    int v, e, a, b;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
    }
    for (int i = 1; i <= v; i++) {
        if (order[i]) continue;
        dfs(i);
    }
    sort(scc, scc + cp);
    printf("%d\n", cp);
    for (int i = 0; i < cp; i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            printf("%d ", scc[i][j]);
        }
        printf("-1\n");
    }
    return 0;
}