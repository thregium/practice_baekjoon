#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 상자 더미를 같은 높이로 쌓았다가 옮겨서 현재의 상태가 되었다. 이 더미들을 다시 옮겨 전부 같은 높이로
만들기 위해서는 최소 몇 회 옮겨야 하는지 구한다. 단, 다시 옮길 수 있는 경우만 주어진다.

해결 방법 : 다시 옮겼을 때의 모든 상자의 높이는 전체 높이의 평균이 되어야 한다. 한 번 옮길 때 마다 평균과 차이 나는
더미의 높이를 2씩 줄일 수 있으므로, 모든 높이의 평균과의 차이 합을 2로 나눈 것이 답이 된다.

주요 알고리즘 : 수학

출처 : SWERC 1997 G번
*/

int b[128];

int main(void) {
    int n, s, a, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        s = 0, r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            s += b[i];
        }
        a = s / n;
        if (s % n) return 1;
        for (int i = 0; i < n; i++) {
            r += abs(a - b[i]);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", tt, r >> 1);
    }
    return 0;
}