#include <stdio.h>
#define INF 1012345678

/*
���� : �� ���� �÷��̾ N, M(N, M <= 50)���� ī��� ī�� ������ �Ѵ�. (��Ģ ����)
�� ī��� �� ���� �ּ��� �������� ������ �Ѵٸ� ù ��° �÷��̾��� ������
�� ��° �÷��̾��� ���� ���̸� ���Ѵ�.

�ذ� ��� : �� ���� ���ÿ� �ִ� ī��� ����� ���� ������ ��輱, �׸��� �ϰ� �н��� Ƚ����
������ ����, ���̳��� ���α׷����� ������ �ȴ�. �ڼ��� ������ �ڵ带 �����Ѵ�.

�ֿ� �˰��� : DP, ���� �̷�

��ó : JAG 2016DA D��
*/

int a[64], b[64], mem[54][54][54][54][2][2]; //(in stack, unused)(a, b), turn, passes
char vis[54][54][54][54][2][2];

int getsum(int* arr, int st, int ed) {
    int res = 0;
    for (int i = st; i <= ed; i++) {
        if (arr[i] < 0) continue;
        res += arr[i];
    }
    return res;
}

int dp(int as, int au, int bs, int bu, int n, int m, int t, int l) {
    if (vis[as][au][bs][bu][t][l]) return mem[as][au][bs][bu][t][l];
    int res = 0, tdp;
    if (t) {
        if (l == 0) {
            res = dp(au, au, bu, bu, n, m, !t, l + (as == au && bs == bu)) +
                getsum(a, as, au - 1) - getsum(b, bs, bu - 1);
        }
        else res = 0;
        tdp = INF;
        if (bu <= m) {
            if (b[bu] < 0) tdp = dp(au, au, bs, bu + 1, n, m, !t, 0);
            else tdp = dp(as, au, bs, bu + 1, n, m, !t, 0);
        }
        if (tdp < res) res = tdp;
    }
    else {
        if (l == 0) {
            res = dp(au, au, bu, bu, n, m, !t, l + (as == au && bs == bu)) +
                getsum(a, as, au - 1) - getsum(b, bs, bu - 1);
        }
        else res = 0;
        tdp = -INF;
        if (au <= n) {
            if (a[au] < 0) tdp = dp(as, au + 1, bu, bu, n, m, !t, 0);
            else tdp = dp(as, au + 1, bs, bu, n, m, !t, 0);
        }
        if (tdp > res) res = tdp;
    }

    vis[as][au][bs][bu][t][l] = 1;
    return mem[as][au][bs][bu][t][l] = res;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    printf("%d\n", dp(1, 1, 1, 1, n, m, 0, 0));
    return 0;
}