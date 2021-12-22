#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : �־��� �׷����� �ּ����� ���� ����ϴ� �÷����� ���Ѵ�.

�ذ� ��� : �־��� �׷����� �̺� �׷����̴�. ����, �̺� �׷����� �� �κ��� ã�Ƽ� ������ �ָ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �̺� �׷���, BFS

��ó : CEOI 2015 5-10��
*/

vector<int> ed[103000];
queue<int> q;
int color[103000];

void bfs(int x) {
    q.push(x);
    color[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (color[i] == 0) {
                color[i] = (!(color[x] - 1)) + 1;
                q.push(i);
            }
        }
    }
}

int check(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j : ed[i]) {
            if (color[j] == color[i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int n, m, x, y;
    //freopen("E:\\PS\\Olympiad\\Central Europe\\2015\\ceoi2015\\10960\\calvin10.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    bfs(1);
    if (!check(n)) return 1;
    printf("2\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[j] == i) printf("%d ", j);
            if (color[j] == 0) {
                return 1;
            }
        }
        printf("\n");
    }
    return 0;
}