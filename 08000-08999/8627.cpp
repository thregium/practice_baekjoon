#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 1000)���� ���� ��ǥ���� �־�����. P��° ������ ����Ͽ� �ִ� �Ÿ� S��ŭ ������
��ǥ������ �ٸ� �������� �̵� �����ϴ�. ������ �̵��ϸ� �ٽ� �̵��� �����ϰ�,
�� �� ���������� �ٽ� �̵��� �Ұ����ϴٸ� ó�� �������� �󸶳� �ָ� �̵� ������ �� ���Ѵ�.
���� ��ǥ�� ���� 10^9 ������ �����̴�.

�ذ� ��� : �÷������� ���� �̵� ������ ������ ���ϰ� �� ��� ó�� �������� ���� �� ��������
�Ÿ��� ã�� ���� �ű⼭ S�� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ������

��ó : JPOI 2009 3-3��
*/

char vis[1024];
long long pos[1024][2];
queue<int> q;

long long getdist(int a, int b) {
    return (pos[a][0] - pos[b][0]) * (pos[a][0] - pos[b][0]) +
        (pos[a][1] - pos[b][1]) * (pos[a][1] - pos[b][1]);
}

int main(void) {
    int n, p, s, x;
    double r = 0.0;
    scanf("%d %d %d", &n, &p, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &pos[i][0], &pos[i][1]);
    }
    q.push(p);
    vis[p] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (getdist(i, x) > (long long)s * s) continue;
            vis[i] = 1;
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) continue;
        if (sqrt(getdist(i, p)) > r) r = sqrt(getdist(i, p));
    }
    printf("%.3f", r + s);
    return 0;
}