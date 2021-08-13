#include <stdio.h>

/*
문제 : N(N <= 1000)가지 경기 중 하나를 개최하려고 한다. 심사위원의 투표를 통해 가장 많은 표를 얻은 경기를 개최한다.
각 심사위원은 개최 비용이 자신의 기준 이하인 경기 중 가장 앞쪽에 있는(흥미로운) 경기에 표를 준다.
심사위원은 1000명 이하이며 각 경기의 개최 비용이 주어진다. 각 심사위원은 모두 표를 줄 수 있고 가장 많은 표를 얻은 경기는 하나뿐이다.

해결 방법 : 각 심사위원이 표를 어디에 주었는지를 매번 확인해본다. N개의 종목 중 가장 먼저 나오는 개최 비용이 기준 이하인 종목이다.
그 다음 표를 가장 많이 얻은 경기를 찾아몬다.

주요 알고리즘 : 구현

출처 : JOI 2014예 2번
*/

int a[1024], b[1024], v[1024];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        for (int j = 0; j < n; j++) {
            if (a[j] <= b[i]) {
                v[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] > v[r]) r = i;
    }
    printf("%d", r + 1);
    return 0;
}