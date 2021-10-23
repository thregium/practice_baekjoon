#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 10)번의 평일동안 수면 기록이 요일 시각 요일 시각의 형태로 주어진다. 이때, 일주일에 T(T <= 168)시간을
자기 위해 주말에 자야 할 최소 시간을 구한다. 각 수면 기록은 겹치지 않고 수면의 끝은 시작 이후이다.
48시간 내내 자더라도 목표 시간이 되지 않으면 -1, 전혀 자지 않아도 된다면 0을 출력한다.

해결 방법 : 수면 기록마다 각 요일을 체크하고 시각에 해당 요일에 해당하는 날짜의 시간을 더해서
소요된 수면 시간을 구하고 이들의 합을 구한다. 그 다음, 합이 T 이상인지 체크한다.
이상인 경우 이미 T시간을 잔 것이므로 0을 출력하면 되고, 그 외의 경우는 T - S를 출력한다.
단, 그 값이 48보다 크다면 -1을 출력해야 한다.

주요 알고리즘 : 구현

출처 : 서울대 2020 D2A번
*/

char ss[8], se[8];
const char* wd[5] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

int main(void) {
    int t, n, s = 0, st, ed;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s %d", ss, &st, se, &ed);
        for (int i = 0; i < 5; i++) {
            if (!strcmp(ss, wd[i])) st += i * 24;
            if (!strcmp(se, wd[i])) ed += i * 24;
        }
        s += ed - st;
    }
    if (s >= t) printf("0");
    else if (t - s > 48) printf("-1");
    else printf("%d", t - s);
    return 0;
}