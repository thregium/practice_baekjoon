#include <stdio.h>

/*
문제 : N(N <= 8)개의 자연수(<= 50)가 주어진다. 매 수마다 누적 합에서 K(K <= 50)씩을 빼 나간다면
자연수의 순열 가운데 누적 합이 음수가 되는 경우가 없는 순열의 개수를 구한다.

해결 방법 : 순열의 모든 경우를 해 보면서 그러한 순열의 개수를 세면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹
*/

int a[8], chk[8];
int r = 0;

void track(int n, int p, int x, int k) {
    if (x < 500) return;
    if (n == p) {
        r++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        else chk[i] = 1;
        track(n, p + 1, x - k + a[i], k);
        chk[i] = 0;
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    track(n, 0, 500, k);
    printf("%d", r);
    return 0;
}