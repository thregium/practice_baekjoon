#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 강의실 사용 일정이 주어질 때, 0부터 S(S <= 10^9)까지의 시간 범위 안에서 M(M <= S) 동안
겹치지 않고 강의실을 사용할 수 있는 가장 이른 시각을 구한다. 없다면 -1을 출력한다.

해결 방법 : 각 시간 범위를 시작 시간 순서대로 정렬한다. 그 다음, 사용 시각을 0으로 둔 채로 겹치는 경우가 있는지 확인한다.
겹치는 경우가 생기면 그 강의의 끝 시각으로 사용 시각을 옮긴다. 이를 반복하고 강의가 끝난 이후 사용 시각을 출력하면 된다.
단, 강의가 끝나기 전에 강의실이 닫는다면 -1을 출력해야 한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 연세대 2020 C번
*/

int test[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, s, l = 0;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &test[i][0], &test[i][1]);
    }
    qsort(test, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (test[i][0] < l + m) {
            l = test[i][0] + test[i][1];
        }
    }
    if (l + m > s) printf("-1");
    else printf("%d", l);
    return 0;
}