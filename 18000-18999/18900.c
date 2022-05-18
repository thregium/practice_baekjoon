#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 N 이하 자연수로 서로 다른 길이의 막대를 출력해야 한다. 프린터에서는
가장 긴 막대부터 오른쪽 또는 왼쪽으로 이동하며 출력 가능할 때, 이동해야 하는 횟수를 구한다.
단, 같은 방향으로 연속해서 이동 가능하다.

해결 방법 : 각 막대의 길이에 대한 위치를 각각 저장하고, 긴 막대부터 순서대로 확인한다.
그 값이 단조 증가 또는 단조 감소하는 가장 긴 수열을 세면서 그러한 수열로 나눈 개수를 세면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 투 포인터?

출처 : AMPPZ 2017 G번
*/

int a[1048576];

int main(void) {
    int n, x, stt, res = 0, lt, rt;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x] = i;
    }
    stt = n;
    while (stt > 0) {
        lt = stt;
        while (lt > 1 && a[lt - 1] < a[lt]) lt--;
        rt = stt;
        while (rt > 1 && a[rt - 1] > a[rt]) rt--;
        if (lt <= rt) stt = lt - 1;
        else stt = rt - 1;
        res++;
    }
    printf("%d", res);
    return 0;
}