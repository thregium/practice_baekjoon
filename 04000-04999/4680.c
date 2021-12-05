#include <stdio.h>

/*
문제 : N(N <= 12)개의 자연수가 비오름차순으로 주어질 때, 합이 T(T <= 1000)이 되는 경우를 사전 내림차순으로 출력한다.

해결 방법 : 재귀를 통해 모든 경우를 해본다. 이때, 직전과 같은 수를 뽑지 않도록 한다.

주요 알고리즘 : 브루트 포스

출처 : MidC 1997 C번
*/

int a[16], chk[16];
int r;

void track(int t, int n, int sel, int stt, int sm) {
    if (sm > t) return;
    else if (sm == t) {
        r++;
        for (int i = 0; i < sel; i++) {
            if (i > 0) printf("+");
            printf("%d", chk[i]);
        }
        printf("\n");
    }

    for (int i = stt; i < n; i++) {
        if (a[i] == chk[sel]) continue;
        chk[sel] = a[i];
        track(t, n, sel + 1, i + 1, sm + a[i]);
        chk[sel + 1] = 0;
    }
}

int main(void) {
    int t, n;
    while (1) {
        scanf("%d", &t);
        if (t == 0) break;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        printf("Sums of %d:\n", t);
        track(t, n, 0, 0, 0);
        if (!r) printf("NONE\n");
        for (int i = 0; i < 16; i++) chk[i] = 0;
    }
    return 0;
}