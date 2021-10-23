#include <stdio.h>

/*
문제 : N(N <= 100)명이 N명에 대해 투표한 결과가 주어질 때, 가장 많은 표를 받은 사람이 누구인지 구한다.
단, 두명 이상인 경우에는 skipped를 출력한다. 투표 결과가 0이라면 그 사람은 투표를 하지 않은 것이다.

해결 방법 : 각 표를 받은 사람의 수를 구한 다음, 가장 많은 표를 받은 사람을 구한다. 
이때 동수가 나오는 경우는 따로 체크를 하도록 한다.

주요 알고리즘 : 구현

출처 : 경북대 2020 B번
*/

int cnt[128];

int main(void) {
    int n, x, r = -1, b = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > b) {
            b = cnt[i];
            r = i;
        }
        else if (cnt[i] == b) r = -1;
    }
    if (b < 0) return 1;
    if (r < 0) printf("skipped");
    else printf("%d", r);
    return 0;
}