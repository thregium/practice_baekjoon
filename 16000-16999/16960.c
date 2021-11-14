#include <stdio.h>

/*
문제 : N(N <= 2000)개의 스위치와 M(M <= 2000)개의 램프가 있을 때, 각 스위치에서 연결되는 램프들이 주어지면
N - 1개의 스위치로 모든 램프와 연결되는지 구한다.

해결 방법 : 모든 램프에 대해 연결되는 스위치의 개수를 센 다음, 각 스위치에서 연결되는 램프 가운데
1개의 스위치만 연결된(그 스위치와만 연결된) 램프가 있는지 구한다. 모든 램프가 그렇다면 연결될 수 없고,
그 외의 경우 모든 램프와 연결될 수 있다.

주요 알고리즘 : 구현?
*/

int cnt[2048], swc[2048][2048];

int main(void) {
    int n, m, r = 0, t = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &swc[i][0]);
        for (int j = 1; j <= swc[i][0]; j++) {
            scanf("%d", &swc[i][j]);
            cnt[swc[i][j]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        t = 1;
        for (int j = 1; j <= swc[i][0]; j++) {
            if (cnt[swc[i][j]] == 1) t = 0;
        }
        if (t) r = 1;
    }
    printf("%d", r);
    return 0;
}