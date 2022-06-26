#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

/*
���� : N(N <= 365)�ϵ��� ������ ��ġ�� ������ ������ ������ �ʴ� ������ �� ������ �ϸ�,
��� ���� �ֱ� 7�� ���̿� �� �� ���� �ֵ��� �� �� �ִ� �� ���Ѵ�.

�ذ� ��� : �� ������ ���� 7�ϰ��� ���� ��ġ�� ������ �͵��� �� ���� �¿� �����صд�.
�̸� �� ������ ��� �¿� ���� ���� ���� ��ġ�� ������ ��츦 ���� ����ؼ� ������ ������,
������ �� ������ ��찡 �ִ� �� ���Ǹ� �ȴ�.

�ֿ� �˰��� : DP, ��

��ó : Aizu 2003 D��
*/

int a[384][16], vis[16];
set<vector<int>> st[384];
vector<int> mv[16] = { {0, 1, 2, 4, 8}, {0, 1, 2, 5, 9}, {0, 1, 2, 6, 10}, {},
    {0, 4, 5, 6, 8}, {1, 4, 5, 6, 9}, {2, 4, 5, 6, 10}, {},
    {0, 4, 8, 9, 10}, {1, 5, 8, 9, 10}, {2, 6, 8, 9, 10}, {}, {}, {}, {}, {} };

int main(void) {
    int n, ok;
    vector<int> v;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 16; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        if (a[1][5] || a[1][6] || a[1][9] || a[1][10]) {
            printf("0\n");
            continue;
        }
        
        st[1].insert({ 5, -1, -1, -1, -1, -1, -1 });
        for (int i = 1; i < n; i++) {
            for (auto& j : st[i]) {
                v = j;
                for (int k = 6; k > 0; k--) v[k] = v[k - 1];
                for (int k : mv[v[1]]) {
                    v[0] = k;
                    if (i < 6) ok = 1;
                    else {
                        ok = 1;
                        for (int l = 0; l < 7; l++) {
                            vis[v[l]] = 1;
                            vis[v[l] + 1] = 1;
                            vis[v[l] + 4] = 1;
                            vis[v[l] + 5] = 1;
                        }
                        for (int l = 0; l < 16; l++) {
                            if (!vis[l]) ok = 0;
                            vis[l] = 0;
                        }
                    }
                    if (a[i + 1][v[0]] || a[i + 1][v[0] + 1] || a[i + 1][v[0] + 4] || a[i + 1][v[0] + 5]) {
                        ok = 0;
                    }
                    if (ok) st[i + 1].insert(v);
                }
            }
        }

        if (st[n].size()) printf("1\n");
        else printf("0\n");

        for (int i = 0; i <= n; i++) st[i].clear();
    }
    return 0;
}