#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#define INF 10123456789
using namespace std;

/*
���� : N * M(N, M <= 50) ũ���� ���ڿ� �빮�ڿ� '-', '*'�� ���� �ִ�. '*'�� �� �� ���̴�.
�� �빮���� ����� �־��� ��, '*'���� �����¿�� �̵��Ͽ� ���� ������ �̵��� �� ������ ����� ����
���ƾ� �ϴ� �빮�� ������ �ּ��� �� ��� �ּ� ����� ���Ѵ�. '-'�� ĭ���δ� �̵��� �� ����.

�ذ� ��� : �� ���ڸ� 2���� �������� ������ �� ���� ���̸� �ܓ������� �帣�� �������� �̾��� ����,
������ ���ڳ��� �뷮 ���Ѵ��� ��������, �ٱ����� ������ ��� �Ǵٸ� ������ �뷮 ���Ѵ��� �������� �̾��ش�.
�� ���� �� ������ �뷮�� '*'�� ���Ѵ�, '-'�� 0, �빮�ڴ� ��� + ����� �պ��� ū ������ ���� �־��ش�.
�׷��� �� �� '*'���� �ٱ����� �帣�� ������ Ȯ���� ����, �� ���� �빮�ڿ��� ���� ������ ���� ���� ��������
���� �ȴ�.
�� �빮�ڿ��� ������ ���� ���ϴ� ������ ���� ������ ������ �������� �켱������ ���� �����̴�.

�ֿ� �˰��� : �׷��� �̷�, �÷ο�

��ó : SRM 433D1 3��
*/

typedef struct edge {
    int nxt, rev;
    long long cap, used;
} edge;

char ter[64][64];
int cost[26], vis[8192], back[8192];
long long f[8192];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<edge> ed[8192]; //nxt, cap, used, rev
queue<int> q;

long long flow(int ss, int sk) {
    int v;
    long long r = 0;
    while (1) {
        q.push(ss);
        f[ss] = INF + (1LL << 48);
        vis[ss] = 1;
        while (q.size()) {
            v = q.front();
            q.pop();
            for (edge i : ed[v]) {
                if (vis[i.nxt] || i.cap == i.used) continue;
                q.push(i.nxt);
                vis[i.nxt] = 1;
                back[i.nxt] = v;
                f[i.nxt] = i.cap - i.used;
                if (f[v] < f[i.nxt]) f[i.nxt] = f[v];
            }
        }
        if (f[sk] == 0) break;
        for (int i = sk; i != ss; i = back[i]) {
            for (edge& j : ed[back[i]]) {
                if (j.nxt == i) {
                    j.used += f[sk];
                    break;
                }
            }
            for (edge& j : ed[i]) {
                if (j.nxt == back[i]) {
                    j.used -= f[sk];
                    break;
                }
            }
        }
        r += f[sk];
        //printf("%lld\n", f[sk] & ((1LL << 40) - 1));
        for (int i = 0; i < 8192; i++) {
            f[i] = 0;
            vis[i] = 0;
        }
    }
    return r;
}

int main(void) {
    int n, m, x, y, p1, p2, ss = -1;
    long long c, r;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ter[i] + 1);
    }
    for (int i = 0; i < 26; i++) {
        scanf("%d", &cost[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p1 = (i << 7) + (j << 1);
            if (ter[i][j] == '*') {
                ss = (i << 7) + (j << 1);
            }
            if (isupper(ter[i][j])) c = cost[ter[i][j] - 'A'] + (1LL << 40);
            else if (ter[i][j] == '*') c = (1LL << 56) + INF;
            else c = 0;
            ed[p1].push_back(edge{ p1 + 1, (int)ed[p1 + 1].size(), c, 0});
            ed[p1 + 1].push_back(edge{ p1, (int)ed[p1].size() - 1, 0, 0 });

            for (int d = 0; d < 4; d++) {
                x = i + dxy[d][0];
                y = j + dxy[d][1];
                if (x < 1 || y < 1 || x > n || y > m) p2 = 0;
                else p2 = (x << 7) + (y << 1);

                ed[p1 + 1].push_back(edge{ p2, (int)ed[p2].size(), (1LL << 56) + INF, 0 });
                ed[p2].push_back(edge{ p1 + 1, (int)ed[p1 + 1].size() - 1, 0, 0 });
            }
        }
    }
    if (ss < 0) return 1;

    r = flow(ss, 0) & ((1LL << 40) - 1);
    if (r >= INF) return 2;
    else printf("%lld", r);
    return 0;
}