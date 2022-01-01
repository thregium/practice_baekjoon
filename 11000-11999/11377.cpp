#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 1000)���� ����� M(M <= 1000)���� ���� �־�����. �̶�, K(K <= N)���� ����� 2���� ���� �� �� �ְ�,
�������� 1���� �ϸ� �� �� �ִٸ� �� �� �ִ� ���� �ִ� ������ ���Ѵ�.

�ذ� ��� : �̺� ��Ī�� ���� �켱 ��� ������� 1���� �ϸ� �ϴ� ����� ��Ī�� ���Ѵ�.
�׸��� �� ���¿��� ����� ������ 2�� �ø��� �ø� �������� �߰� ��Ī�� ���Ѵ�. ��, �߰� ��Ī�� K���� �Ǵ� ����
�߰� ��Ī�� �����Ѵ�. �� �� ���� ��Ī�� �߰� ��Ī�� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �̺� ��Ī
*/

vector<int> ed[2048];
int vis[2048], left[2048], right[1024];

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
    int n, m, k, c, w, r = 0, r2 = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &w);
            ed[i].push_back(w);
        }
    }
    for (int i = 1; i <= n; i++) {
        r += match(i);
        for (int j = 1; j <= n; j++) vis[j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        ed[i + n] = ed[i];
    }
    for (int i = n + 1; i <= n * 2; i++) {
        r2 += match(i);
        if (r2 == k) break;
        for (int j = 1; j <= n * 2; j++) vis[j] = 0;
    }
    printf("%d", r + r2);
    return 0;
}