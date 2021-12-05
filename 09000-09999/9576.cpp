#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 1000)���� å�� M(M <= 1000)���� ������ �ַ��� �Ѵ�. �̶�, �� ����� ���� �� �ִ� å�� ������ �־�����
å�� ���� �� �ִ� �ִ��� ��� ���� ���Ѵ�.

�ذ� ��� : �̺� ��Ī�� �̿��ϸ� �����ϰ� Ǯ �� �ִ�.

�ֿ� �˰��� : �̺� ��Ī
*/

int left[1024], right[1024], vis[1024];
vector<int> ed[1024];

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int t, n, m, a, b, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            for (int j = a; j <= b; j++) ed[i].push_back(j);
        }
        r = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) vis[j] = 0;
            r += match(i);
        }
        printf("%d\n", r);
        for (int i = 0; i <= 1000; i++) {
            left[i] = 0;
            right[i] = 0;
            vis[i] = 0;
            ed[i].clear();
        }
    }
    return 0;
}