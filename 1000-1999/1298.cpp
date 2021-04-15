#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100) ���� �������� �������� �־��� �� �ִ� ��Ī ���� ����Ѵ�.

�ذ� ��� : �̺� ��Ī �˰����� ����Ѵ�.

�ֿ� �˰��� : �̺� ��Ī
*/

vector<int> v[128];
int a[128], b[128], vis[128];

int match(int x) {
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        if (b[v[x][i]] < 0 || (!vis[b[v[x][i]]] && match(b[v[x][i]]))) {
            a[x] = v[x][i];
            b[v[x][i]] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, m, x, y, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = -1;
        b[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            if (match(i)) r++;
        }
    }
    printf("%d", r);
    return 0;
}