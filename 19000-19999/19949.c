#include <stdio.h>

/*
문제 : 10개의 5지선다 답안이 주어질 때, 3개의 답을 연속하게 찍지 않으면서 5점 이상 받는 경우의 수를 구한다.

해결 방법 : 브루트 포스를 통해 모든 경우를 해보면 된다.

주요 알고리즘 : 브루트 포스

출처 : 인하대 2020N F번
*/

int ans[16], chk[16];

int track(int x) {
    if (x == 10) {
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (chk[i] == ans[i]) cnt++;
        }
        return (cnt >= 5);
    }
    int r = 0;
    for (int i = 1; i <= 5; i++) {
        chk[x] = i;
        if (x >= 2 && chk[x] == chk[x - 1] && chk[x] == chk[x - 2]) continue;
        r += track(x + 1);
    }
    return r;
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &ans[i]);
    }
    printf("%d", track(0));
    return 0;
}