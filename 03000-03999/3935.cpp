#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

/*
문제 : N(N <= 365)일동안 구름의 위치를 조정해 축제가 열리지 않는 곳에만 비가 오도록 하며,
모든 곳은 최근 7일 사이에 비가 온 적이 있도록 할 수 있는 지 구한다.

해결 방법 : 각 날마다 이전 7일간의 구름 위치로 가능한 것들을 각 날의 셋에 저장해둔다.
이를 각 날마다 모든 셋에 대해 다음 날의 위치로 가능한 경우를 각각 계산해서 저장해 나가고,
마지막 날 가능한 경우가 있는 지 살피면 된다.

주요 알고리즘 : DP, 셋

출처 : Aizu 2003 D번
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