#include <stdio.h>

/*
문제 : L(L <= 1000)까지의 자연수가 있다. N(N <= 1000)개의 구간이 주어지고, 각 구간에 차례로 아직 배분하지 않은 구간 내의
자연수들을 전부 배분한다. 이때, 가장 긴 구간과 가장 많은 자연수를 배분받은 구간을 구한다. 개수가 같은 경우,
먼저 나온 구간을 우선한다.

해결 방법 : L과 N이 크지 않기 때문에 자연수 배분을 직접 시뮬레이션해 보면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : COCI 12/13#4 1번
*/

int cake[1024], people[1024][3];

int main(void) {
    int l, n, longest = -1, lsz = -1, much = -1, msz = -1;
    scanf("%d%d", &l, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &people[i][0], &people[i][1]);
        if (people[i][1] - people[i][0] > lsz) {
            lsz = people[i][1] - people[i][0];
            longest = i;
        }
    }
    if (longest < 0) return 1;
    for (int i = 0; i < n; i++) {
        for (int j = people[i][0]; j <= people[i][1]; j++) {
            if (cake[j]) continue;
            cake[j] = 1;
            people[i][2]++;
        }
        if (people[i][2] > msz) {
            msz = people[i][2];
            much = i;
        }
    }
    if (much < 0) return 2;
    printf("%d\n%d", longest + 1, much + 1);
    return 0;
}