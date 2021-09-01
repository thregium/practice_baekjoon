#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 1000)��� �� M(M <= 1000)���� �ִ�. �� ����� �� �� �ִ� �ϵ��� �־��� ��, ���� �ִ� �� ������
���ÿ� �� �� �ִ��� ���Ѵ�. �� ����� 2������ ���� �� �� �ְ�, �� �ϵ��� 1�� ������ �ȴ�.

�ذ� ��� : �̺� ��Ī�� �̿��� �ذ� �����ϴ�. �Ϲ����� �̺и�Ī���� �� ������� ������ 2���� �ø��� �̺� ��Ī�� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �̺� ��Ī
*/

int left[2048], right[1024], vis[2048];
vector<int> ed[2048];

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
    int n, m, c, x, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &x);
            ed[i * 2 - 1].push_back(x);
            ed[i * 2].push_back(x);
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        if (left[i]) continue;
        for (int j = 1; j <= n * 2; j++) vis[j] = 0;
        r += match(i);
    }
    printf("%d", r);
    return 0;
}