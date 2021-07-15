#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 200000)���� �������� �̷���� Ʈ������ M(M <= N)���� �������� ��� ���� �Ÿ��� ������ �ִ��� Ȯ���ϰ�
�ִٸ� �׷��� ���� �� �ϳ��� ���Ѵ�.

�ذ� ��� : M���� �������� BFS�� ��߽�Ų��. �׸��� �� �������� �湮�� ������� ���� �����صд�.
Ȯ���ϴ� ������ ���� �湮���� ���� ������ ��쿡�� ���� ������ ����� ���� ������ �� �������� ��Ҵ�� �Ѵ�.
�湮�� �����̶�� ���� ������κ����� �Ÿ��� ����� �Ÿ��� ������ Ȯ���Ѵ�. �ٸ��ٸ� �ٸ� ������ ���캻��.
���ٸ� ���� ������ ����� ���� ���� ������ ����� ���� ���ϰ� �ٸ� ������ ���캻��.
�̸� ���� ��ģ �ڿ��� ��� ������ ���� M�� ������ �ִ��� ã�� �ִٸ� �� ������ ã�����ϴ� ���̰�
���ٸ� �׷��� ���� ���� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, BFS, Ʈ��

��ó : NWRRC 2019 E��
*/

int cnt[204800], dist[204800];
char dir[256], buff[64];
vector<int> ed[204800];
queue<int> q;

void bfs(void) {
    int x;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (cnt[i]) {
                if (dist[i] == dist[x] + 1) cnt[i] += cnt[x];
                continue;
            }
            q.push(i);
            cnt[i] = cnt[x];
            dist[i] = dist[x] + 1;
        }
    }
}

int main(void) {
    int m, n, v, u;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &v, &u);
        ed[v].push_back(u);
        ed[u].push_back(v);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &v);
        q.push(v);
        cnt[v] = 1;
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == m) {
            printf("YES\n%d", i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}