#include <stdio.h>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 100)���� ���ÿ� M���� ���ΰ� �ִ�. �� ���� ������ �Ÿ�(<= 100)�� ���赵(<= 10000)�� �־�����.
L(L <= 100)�� ������ �ְ�, ���� ������ �Ÿ���ŭ�� ����� �ְ� ������ ����� ���赵�� 0���� ���� �� �ִ�.
�̶�, 1�� ���ÿ��� N�� ���÷� �׻� �� �� �ִٸ� �� ���÷� ���� �� �ɸ��� ���赵 ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : �� ������ ��ȣ�� ���� ������ �������� �Ͽ� �׷����� ���� ���� ���ͽ�Ʈ�� ���� ���� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, DP

��ó : JAG 2009D C��
*/

int mem[128][128], vis[128][128];
vector<tuple<int, int, int>> ed[128];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
//asserted, vertex, money(remaining)

int main(void) {
    int n, m, l, a, b, d, e, r;
    while (1) {
        scanf("%d %d %d", &n, &m, &l);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &a, &b, &d, &e);
            ed[a].push_back({ b, d, e });
            ed[b].push_back({ a, d, e });
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= l; j++) {
                mem[i][j] = INF;
                vis[i][j] = 0;
            }
        }

        pq.push({ 0, 1, l });
        mem[1][l] = 0;
        while (pq.size()) {
            d = get<0>(pq.top());
            a = get<1>(pq.top());
            b = get<2>(pq.top());
            pq.pop();
            if (vis[a][b]) continue;
            else vis[a][b] = 1;
            for (auto& i : ed[a]) {
                if (get<1>(i) <= b && mem[a][b] < mem[get<0>(i)][b - get<1>(i)]) {
                    mem[get<0>(i)][b - get<1>(i)] = mem[a][b];
                    pq.push({ mem[get<0>(i)][b - get<1>(i)], get<0>(i), b - get<1>(i) });
                }
                if (mem[a][b] + get<2>(i) < mem[get<0>(i)][b]) {
                    mem[get<0>(i)][b] = mem[a][b] + get<2>(i);
                    pq.push({ mem[get<0>(i)][b] , get<0>(i), b });
                }
            }
        }

        r = INF;
        for (int i = 0; i <= l; i++) {
            if (mem[n][i] < r) r = mem[n][i];
        }
        printf("%d\n", r);
        for (int i = 1; i <= n; i++) {
            ed[i].clear();
        }
    }
    return 0;
}