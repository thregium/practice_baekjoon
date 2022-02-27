#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 100000)���� ���̳�� M(M <= 100000)���� ���̳� ���� ����(X�� �������� Y�� ������)�� �־�����,
���̳븦 ���� ���ʶ߸��� ���� ���ʶ߷��� �ϴ� ���̳��� �ּ� ������ ���Ѵ�.

�ذ� ��� : ��� �ϳ��� ���ʶ߷��� ���� ���� �������� ���̳��� ������ SCC�̹Ƿ� SCC�� ���� ����,
�� SCC ������ ���踦 �������� �̾� DAG�� ���� ����, ���� ������ 0�� SCC�� ������ ���ϸ� �ȴ�.
�ʱ�ȭ�� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, SCC

��ó : Waterloo 20080927 D��
*/

int order[103000], stack[103000], fin[103000];
int cnt = 1, sp = 0, cp = 0;
vector<int> ed[103000], scc[103000];
int color[103000], ins[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int dfs(int x) {
    //���� ������ ���� �� ������ ��ȯ, ���� ���� �ܿ� ���� ��� SCC ����
    order[x] = cnt++;
    stack[sp++] = x;

    int r = order[x];
    for (int nxt : ed[x]) {
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
        for (int i : scc[cp]) {
            color[i] = cp;
        }
        cp++;
    }

    return r;
}

int main(void) {
    int t, v, e, a, b, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &v, &e);
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            ed[a].push_back(b);
        }
        for (int i = 1; i <= v; i++) {
            if (order[i]) continue;
            dfs(i);
        }
        for (int i = 1; i <= v; i++) {
            for (int j : ed[i]) {
                if (color[i] != color[j]) ins[color[j]]++;
            }
        }
        for (int i = 0; i < cp; i++) {
            if (ins[i] == 0) r++;
        }
        printf("%d\n", r);

        for (int i = 1; i <= v; i++) {
            order[i] = 0;
            fin[i] = 0;
            color[i] = 0;
            ed[i].clear();
        }
        for (int i = 0; i < cp; i++) {
            scc[i].clear();
            ins[i] = 0;
        }
        cnt = 1, sp = 0, cp = 0, r = 0;
    }
    return 0;
}