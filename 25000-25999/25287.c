#include <stdio.h>

/*
문제 : N(N <= 50000)개의 자연수로 이루어진 순열에서 각 수를 N - x + 1로 바꿀 수 있다면
정렬 가능한 지 확인한다.

해결 방법 : 앞에서부터 작은 쪽으로 먼저 넣어보고 앞의 수보다 작다면 큰 쪽으로 다시 넣어본다.
둘다 안 된다면 넣을 수 없는 것이므로 정렬이 불가능하다.

주요 알고리즘 : 그리디 알고리즘

출처 : 선린 6회예 C번
*/

int a[51200];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = small(a[i], n - a[i] + 1);
            if (a[i] < a[i - 1]) {
                a[i] = big(a[i], n - a[i] + 1);
                if (a[i] < a[i - 1]) break;
            }
            r = i;
        }
        if (r == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}