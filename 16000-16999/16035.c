#include <stdio.h>

/*
문제 : N(3 <= N <= 9, 홀수)개의 팀이 경기를 한다. 각 경기는 승패만을 따지고 무승부는 일어나지 않는다.
이때, 현재까지의 결과가 M(1 <= M <= N * (N - 1) / 2)개 주어질 때, 모든 팀의 승패수가 같게 되는 경우는
몇 가지가 나올 수 있는 지 구한다.

해결 방법 : N이 9이고 M이 1인 경우에도 많아야 약 160만가지 뿐이므로 백트래킹을 통해
모든 경우를 한 번씩 해보면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : JDC 2018 D번
*/

int wl[16][16];

int track(int n, int a, int b) {
    int c, r;
    if (a == b) {
        if (a == n) return 1;
        else return track(n, a, b + 1);
    }
    if (a > b || (a == n && b > n)) return 1;

    if (wl[a][b]) {
        if (b == n) {
            c = 0;
            for (int i = 1; i <= n; i++) c += wl[a][i];
            if (c) return 0;
            else return track(n, a + 1, a + 2);
        }
        else return track(n, a, b + 1);
    }
    else {
        r = 0;
        if (b == n) {
            wl[a][b] = 1, wl[b][a] = -1;
            c = 0;
            for (int i = 1; i <= n; i++) c += wl[a][i];
            if (!c) r += track(n, a + 1, a + 2);
            wl[a][b] = -1, wl[b][a] = 1;
            c = 0;
            for (int i = 1; i <= n; i++) c += wl[a][i];
            if (!c) r += track(n, a + 1, a + 2);
            wl[a][b] = 0, wl[b][a] = 0;
        }
        else {
            wl[a][b] = 1, wl[b][a] = -1;
            r += track(n, a, b + 1);
            wl[a][b] = -1, wl[b][a] = 1;
            r += track(n, a, b + 1);
            wl[a][b] = 0, wl[b][a] = 0;
        }
        return r;
    }
}

int main(void) {
    int n, m, a, b;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            wl[a][b] = 1;
            wl[b][a] = -1;
        }
        printf("%d\n", track(n, 1, 2));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) wl[i][j] = 0;
        }
    }
    return 0;
}