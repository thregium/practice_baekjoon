#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 2000)���� ������ M(M <= 100000)���� �������� �̷���� �׷������� Ư�� ������ ����� ������ ��� ������
���� �������ٰ� �Ѵ�. �̶�, ���� ������ ��ǥ���� �־����� �׷��� ���� �� �ִ� ��, �׷��ϴٸ� ����� ����� ����Ѵ�.

�ذ� ��� : ���� �� �ִ�(������ ���� ��� ����� �� �Ǵ� ������ ����) �������� ��� ������ ����,
������ �� ������ ��� ���������� ���ɴ�. �������� ���� ������ �ִٸ� �׷��� ����� ����� ���� ���̰�,
���ٸ� �׷��� ����� ��� �� �ϳ��� ���� ���� ����� �ִ� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, �׸��� �˰���, ������

��ó : ��õ�� 2019 D��
*/

int dtr[2048], vis[2048], res[2048];
vector<int> ed[2048];

int main(void) {
    int n, m, k, u, v, t = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        dtr[u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!dtr[i]) continue;
        u = 0;
        for (int j : ed[i]) {
            if (!dtr[j]) {
                u = 1;
                break;
            }
        }
        if (!u) {
            res[t++] = i;
            vis[i] = 1;
            for (int j : ed[i]) vis[j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dtr[i] != vis[i]) t = -1;
    }
    printf("%d\n", t);
    for (int i = 0; i < t; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}