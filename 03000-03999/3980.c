#include <stdio.h>

/*
문제 : 11명의 선수의 포지션 별 능력치가 주어질 때, 모든 선수들을 각 포지션에 배치하며 얻을 수 있는
최대 능력치 합을 구한다. 단, 능력치 0인 곳에는 배치할 수 없다. 각 포지션은 최대 5명의 선수에게만 적합하다.

해결 방법 : 각 포지션은 최대 5명에게만 적합하기 때문에 각 포지션마다 백트래킹을 하면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : GCPC 2010 G번
*/

int arr[16][16], chk[16];
int best = -1;

void track(int x, int r) {
    if (x == 11) {
        if (r > best) best = r;
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (arr[x][i]) {
            if (chk[i]) continue;
            chk[i] = 1;
            track(x + 1, r + arr[x][i]);
            chk[i] = 0;
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        best = -1;
        track(0, 0);
        printf("%d\n", best);
    }
    return 0;
}