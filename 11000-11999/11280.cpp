#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int scc_ord[20480], scc_stk[20480], scc_fin[20480], trfs[10240];
int scc_vcnt = 0, scc_top = 0, scc_cnt = 0;
vector<int> ed[20480], scc[20480];

int absn(int a) {
    if (a < 0) return -a;
    else return a;
}

int sign(int a) {
    if (a < 0) return 1;
    else return 0;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int scc_dfs(int x) {
    //���� ������ ���� �� ������ ��ȯ, ���� ���� �ܿ� ���� ��� SCC ����
    scc_ord[x] = scc_vcnt++;
    scc_stk[scc_top++] = x;

    int r = scc_ord[x];
    for (int nxt : ed[x]) {
        //������ �����鿡 ���� üũ
        if (scc_ord[nxt] == 0) r = small(r, scc_dfs(nxt)); //���� �湮���� ���� ������ ���
        else if (!scc_fin[nxt]) r = small(r, scc_ord[nxt]); //���� SCC�� ���� ���� ������ ���
    }

    if (r == scc_ord[x]) {
        //SCC ����
        while (1) {
            scc[scc_cnt].push_back(scc_stk[--scc_top]);
            scc_fin[scc_stk[scc_top]] = 1;
            if (scc_stk[scc_top] == x) break; //X�� ���� �� ���� ������ ���ҵ��� ����
        }
        sort(scc[scc_cnt].begin(), scc[scc_cnt].end());
        scc_cnt++;
    }

    return r;
}

int main(void) {
    int n, m, a, b, res = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[absn(a) * 2 + (!sign(a))].push_back(absn(b) * 2 + sign(b));
        ed[absn(b) * 2 + (!sign(b))].push_back(absn(a) * 2 + sign(a));
    }
    for (int i = 2; i <= n * 2 + 1; i++) {
        if (!scc_ord[i]) {
            scc_dfs(i);
        }
    }

    for (int i = 0; i < scc_cnt; i++) {
        for (int j = 1; j < scc[i].size(); j++) {
            if ((scc[i][j] & 1) && scc[i][j - 1] + 1 == scc[i][j]) res = 0;
        }
    }
    printf("%d\n", res);
    if (!res) return 0;
    //2-SAT ������
    for (int i = 1; i <= n; i++) trfs[i] = -1;
    for (int i = scc_cnt - 1; i >= 0; i--) {
        for (int j : scc[i]) {
            if (trfs[j >> 1] < 0) {
                trfs[j >> 1] = (j & 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (trfs[i] < 0) return 1;
        printf("%d ", trfs[i]);
    }
    return 0;
}