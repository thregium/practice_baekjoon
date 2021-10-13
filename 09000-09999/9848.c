#include <stdio.h>

/*
문제 : N(N <= 100)번의 연습 경기 시간 기록(<= 100000)이 주어질 때, 마지막 경기보다 시간이 K(K <= 100000) 이상
줄어든 횟수를 구한다.

해결 방법 : 각 경기 기록을 입력받으며 2번째 이후에서 마지막 경기와의 시간 차가 K 이상인지를 매번 확인해보면 된다.

주요 알고리즘 : 구현

출처 : NOI 2007 1번
*/

int main(void) {
    int n, k, time, last = -1, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &time);
        if (i > 0 && last - time >= k) r++;
        last = time;
    }
    printf("%d", r);
    return 0;
}