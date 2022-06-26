#include <stdio.h>
#define MOD 1000000007

/*
���� : N(N <= 2000)���� ������ M(M <= 2000)���� �������� �̷���� ����� �׷�������
�� �־����� i��°�� ������ 3^(i - 1)�� �뷮�� ���´�. �̶�, 0�� �������� N - 1�� �������� �带 �� �ִ�
�ִ� ������ ���Ѵ�.

�ذ� ��� : ���� �׷����� ����ġ�� ũ�� ������ �ִ� ������ ���� ���ϱ�� ��ƴ�.
�׷���, ���⼭ 0��° �������� p - 1��° ���������� �뷮 ���� p��° �뷮���� �۴ٴ� ���� �� �� �����Ƿ�
ū �뷮���� ������ ���س����� ���� �����ϴ�. M - 1�� �������� �������� �ش� ���� ���ķ� ���� �����鸸
���� �÷������� ���� 0������ N - 1������ �̵� ������ �� Ȯ���Ѵ�. ������ ��� �ش� ������ �����
�信 �ش� ������ �뷮�� ���س�����. �̸� �ݺ��ϸ� ��� ������ �ִ������� �帣�� ������
���� ���� ���� �� �ְ�, �̰��� ���� �ȴ�.

�ֿ� �˰����� : �׷��� �̷�, �׸��� �˰�����, �÷�����, �÷ο�
*/

int edc[2048], ed[2048][2048][2], vis[2048], b3[2048];

int dfs(int x, int l, int n) {
    vis[x] = 1;
    if (x == n - 1) {
        return 1;
    }
    int r = 0;
    for (int i = 0; i < edc[x]; i++) {
        if (ed[x][i][1] < l || vis[ed[x][i][0]]) continue;
        else r |= dfs(ed[x][i][0], l, n);
    }
    return r;
}

int main(void) {
    int n, m, a, b, r = 0;
    b3[0] = 1;
    for (int i = 1; i <= 2000; i++) b3[i] = (b3[i - 1] * 3LL) % MOD;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a][edc[a]][0] = b;
        ed[a][edc[a]++][1] = i;
        ed[b][edc[b]][0] = a;
        ed[b][edc[b]++][1] = i;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) vis[j] = 0;
        if (dfs(0, i, n)) {
            r = (r + b3[i]) % MOD;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < edc[j]; k++) {
                    if (ed[j][k][1] == i) ed[j][k][1] = -1;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}