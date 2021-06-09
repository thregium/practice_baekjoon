#include <stdio.h>
#include <vector>
using namespace std;
vector<int> vx[512];
int vis[512], xm[512], ym[512];

/*
���� : N * N(N <= 500) ũ���� ������ M(M <= 10000)���� ���� ��� �����ϱ� ���ؼ��� �� �Ǵ� ���� �ּ� �� �� �ʿ����� ���Ѵ�.

�ذ� ��� : �� ��� ���� ����, �� ���� ��ġ�� �� ���� ��ġ�� ��� ���� �մ� �������� �����Ѵ�.
�׷��� �Ǹ� �ش� ���� �����ϱ� ���ؼ��� �ش� ���� �ش��ϴ� ������ �� �� �� �ϳ��� �����;� ���� �� �� �ִ�.
���� �̴� �̺� ��Ī�� ���� ���� �� �ִٴ� ���� �� �� �ִ�.

�ֿ� �˰��� : �̺� ��Ī

��ó : USACO 2005N G1��
*/

int match(int x) {
    vis[x] = 1;
    for (int i = 0; i < vx[x].size(); i++) {
        if (ym[vx[x][i]] == 0 || !vis[ym[vx[x][i]]] && match(ym[vx[x][i]])) {
            xm[x] = vx[x][i];
            ym[vx[x][i]] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, k, x, y, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        vx[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!xm[i]) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            if (match(i)) r++;
        }
    }
    printf("%d", r);
    return 0;
}