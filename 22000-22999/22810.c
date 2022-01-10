#include <stdio.h>

/*
문제 : N(N <= 100)명의 사람이 만날 수 있는 M(M <= 100)개의 날짜가 주어진다. 각 날짜는 100 이하의 자연수이다.
이때, Q(Q <= N)명 이상의 가장 많은 사람이 만날 수 있는 날짜 가운데 가장 빠른 것을 구한다.
그러한 날짜가 없다면 0을 출력한다.

해결 방법 : 각 날짜별로 만날 수 있는 사람 수를 구하고, 1부터 100까지 확인하며 가장 만날 수 있는 사람이 많은 날짜를 구한다.
초기값을 0으로 두면 그러한 날짜가 없을 때 자동으로 답이 0이 된다.

주요 알고리즘 : 구현

출처 : JDC 2003 A번
*/

int cnt[128];

int main(void) {
    int n, q, m, date, best, bn;
    while (1) {
        scanf("%d %d", &n, &q);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &date);
                cnt[date]++;
            }
        }
        best = 0, bn = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] >= q && cnt[i] > best) {
                best = cnt[i];
                bn = i;
            }
        }
        printf("%d\n", bn);
        for (int i = 1; i <= 100; i++) cnt[i] = 0;
    }
    return 0;
}