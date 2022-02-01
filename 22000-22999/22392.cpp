#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 1000)���� ������ M(M <= 1000)���� �������� �̷���� ���� ���� �׷�������
���� ������ �����ϸ� ������ �� �׷����� ���� ��, A(�Ǵ� B) �׷쿡 ���� �� �ִ� ������ ���� ����� ���Ѵ�.
1. ���� �׷��� ���������� �������� �̾��� �� ����.
2. A�� B �׷��� ���������� �������� �̾��� �� ����.
3. A�� B �׷쿡 ���ϴ� ������ ������ ���ƾ� �Ѵ�.

�ذ� ��� : A�� B �׷��� �ϳ��� ������ �̺� �׷����� ���°� ���� �� �� �ִ�.
����, �켱 �̷��� ������ ���ؼ��� �� �׷����� �̺� �׷����� �Ǿ�� �Ѵ�. �̺� �׷������� Ȯ���Ͽ��ٸ�
A �׷��� ���� ������ �� �� �ִ� ���� ���� �׷� ��� ���� ������ ¦���� ���� ������ �� ���̴�.
���� �׷쿡 ���� ���� ������ ¦������ ���ǰ� ¦���� ���� ������ ��� ����ϸ� �ȴ�.
���� ������ ������ ¦���� ���� ���� ��� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �̺� �׷���

��ó : JAG 2018D E��
*/

int color[1024];
vector<int> ed[1024];
queue<int> q;

int bfs(int n, int x) {
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) color[i] = 0;
    int c = 1;
    color[x] = c;
    q.push(x);
    while (q.size()) {
        x = q.front();
        c = color[x];
        q.pop();
        for (int i : ed[x]) {
            if (color[i] == c) return -1;
            else if (color[i] == 0) {
                color[i] = (!(c - 1)) + 1;
                q.push(i);
            }
        }
    }
    x = 0;
    for (int i = 1; i <= n; i++) {
        x += (color[i] == 1);
    }
    return x;
}

int main(void) {
    int n, m, u, v, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        r = bfs(n, 1);
        if (r < 0) {
            printf("0\n");
        }
        else {
            if ((r & 1) && ((n - r) & 1)) printf("0\n");
            else if (r & 1) printf("1\n%d\n", (n - r) >> 1);
            else if ((n - r) & 1) printf("1\n%d\n", r >> 1);
            else {
                if (r < n - r) printf("2\n%d\n%d\n", r >> 1, (n - r) >> 1);
                else if (r == n - r) printf("1\n%d\n", r >> 1);
                else printf("2\n%d\n%d\n", (n - r) >> 1, r >> 1);
            }
        }
        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}