#include <stdio.h>
#include <vector>
#include <queue>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
using namespace std;

/*
���� : N(N < 50000)���� ������ M(M <= 100000)���� ����� ������ ���� �׷����� �ִ�. �� �׷����� �� ������ ĥ�ϵ�
�������� ����� ���������� ���� �ٸ� ������ ĥ�Ϸ��� �Ѵ�. ĥ�ϴ� ���� �������� Ȯ���ϰ�
�����ϴٸ� �� ���� ���� �ִ� �� ���� ������ ĥ�� �� �ִ��� ���Ѵ�.

�ذ� ��� : ���� �� �׷����� �̺� �׷����� ��� ��� ������ ĥ�ϴ� ���� �����ϴ�. �̺� �׷��� ���δ�
BFS�� ���� �ذ� �����ϴ�. �� �̺� �׷������� ���� ���� ĥ�ϴ� ����� �̺� �׷����� ���������� �� ���� ���
�� ū ���� �����ϴ� ���� �ݺ��ϸ� �ȴ�. ��, ���� �׷����� �ƴ� �� ������
�̺� �׷����� �ƴ� �׷����� �ϳ��� ������ ĥ�� �� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �̺� �׷���

��ó : USACO 2014O B3��
*/

int vis[51200];
vector<int> ed[51200];
queue<pair<int, int>> q;

int bfs(int x) {
    int s = 1, c = 1, r = 1;
    q.push(pair<int, int>(x, s));
    vis[x] = s;
    while (q.size()) {
        x = q.front().first;
        s = q.front().second;
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) {
                if (vis[i] == s) return -1;
            }
            else {
                vis[i] = (!(s - 1)) + 1;
                q.push(pair<int, int>(i, (!(s - 1)) + 1));
                if (s == 2) r++;
                c++;
            }
        }
    }
    return r > c - r ? r : c - r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("decorate.in", "r");
        fo = fopen("decorate.out", "w");
    }
    int n, m, a, b, r = 0, earn;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        earn = bfs(i);
        if (earn < 0) {
            r = -1;
            break;
        }
        else r += earn;
    }
    printf("%d", r);
    return 0;
}