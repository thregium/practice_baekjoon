#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 100)���� �������� �̷���� �׷����� M(M <= 16)���� ��ο� ���� �ִ�.
����, �� �濡���� K(K < N)���� ��ȣ�� �Ű��� ����� �ְ�, �� ����� �ٽ� ������ ����ȴ�.
�̶�, ��� ��ο� �濡�� ���� ������ �̵��ϱ� ���� �ʿ��� �ּ� �̵� Ƚ���� ���Ѵ�.
�� �̵��� �� ��ȣ�� �̵��ϰ� �Ǹ� ���� �濡���� ���̻� �̵����� �ʴ´�. ��� ��ο� �濡����
���� ������ �̵��ϴ� ����� �����Ѵ�.

�ذ� ��� : ��� ��ο� �濡�� ����ϴ� ��츦 ���������� �ΰ�, �� ������ �� ��ο� �渶��
����� ���� ���ɼ����� �д�. �ش� ������ ����� ������ �� �ִٸ� 1, ���ٸ� 0���� �Ͽ� ��Ʈ����ŷ��
���·� ����ȴ�. ���� �̵��� �� ���� ����� ������ �� �ִ� ����� Ȯ���ϰ� ��Ʈ����ŷ�Ͽ�
BFS�� �Ѵ�. ��� ��ο� �濡 ����� ���� �Ǵ� ���������� �ִܰŸ��� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��Ʈ����ŷ

��ó : JAG 2015S2 D��
*/

int v[128][128], dark[128], mem[65536];
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

int bfs(int x, int n, int m, int k) {
    int r = INF, t, cnt[128] = { 0, };
    q.push(x);
    mem[x] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if ((x >> j) & 1) {
                    cnt[v[dark[j]][i]]++;
                }
            }
            t = 0;
            for (int j = 0; j < m; j++) {
                if (cnt[dark[j]]) t += (1 << j);
                cnt[dark[j]] = 0;
            }
            if (mem[t] < 0) {
                q.push(t);
                mem[t] = mem[x] + 1;
            }
        }
    }
    return mem[0];
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &dark[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 0; i < (1 << m); i++) mem[i] = -1;
    printf("%d\n", bfs((1 << m) - 1, n, m, k));
    return 0;
}