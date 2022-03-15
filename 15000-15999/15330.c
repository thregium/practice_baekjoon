#include <stdio.h>
#include <stdlib.h>

/*
���� : M(M <= 16, ¦��)���� ���� ���� ���� �־�����. �̶�, �� ������ 2���� ¦���
������ �׾��� �� ��Ÿ���� ���༱�� �ִ� ������ ���Ѵ�. �� ���� ��ǥ ������ ���� 1000 ���ϴ�.
�� ������ �������� ���⸸ ���ٸ� ���༱�̴�.

�ذ� ��� : ���Ʈ ������ ������ 2���� ¦���� ��� ����� �� ����.
�׸��� ������ ��� ¦������ ��� �ֿ� ���� ���༱���� ���θ� ������ ���� �Ǻ��ϰ�
�� ������ �ִ밡 �� ���� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : Tsukuba 2017 B��
*/

int point[16][2], pair[8][2], vis[16];
int best = 0;

long long sqr(long long a) {
    return a * a;
}

int ispararell(int a, int b) {
    long long dxa = point[pair[a][0]][0] - point[pair[a][1]][0];
    long long dya = point[pair[a][0]][1] - point[pair[a][1]][1];
    long long dxb = point[pair[b][0]][0] - point[pair[b][1]][0];
    long long dyb = point[pair[b][0]][1] - point[pair[b][1]][1];
    if (sqr(dxa * dxb + dya * dyb) == (sqr(dxa) + sqr(dya)) * (sqr(dxb) + sqr(dyb))) return 1;
    else return 0;
}

void track(int n, int m, int x) {
    int r;
    if (m == x) {
        r = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (ispararell(i, j)) r++;
            }
        }
        if (r > best) best = r;
        return;
    }
    r = -1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (r < 0) {
            r = i;
            pair[x][0] = i;
            vis[i] = 1;
            continue;
        }
        pair[x][1] = i;
        vis[i] = 1;
        track(n, m, x + 1);
        vis[i] = 0;
    }
    vis[r] = 0;
}

int main(void) {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    track(m, m >> 1, 0);
    printf("%d\n", best);
    return 0;
}