#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 시간대의 시각을 UTC+8의 시각으로 바꾼다. 단, 시각은 24시간 단위이고 시간대는 소숫점 아래 1자리까지 주어질 수 있다.

해결 방법 : 먼저 시간을 UTC+0 기준으로 옮긴 다음 시간대에 맞게 시각을 바꾸면 된다. 단, 시간대는 정수형으로 받는 것이 좋으며,
1자리인 경우와 2자리인 경우에 대해 서로 다르게 적용해야 한다.

주요 알고리즘 : 문자열, 파싱, 구현

출처 : Petro 2018S4 K번
*/

char s[16];

int main(void) {
    int t, a, b, tm, add;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %s", &a, &b, s);
        tm = a * 60 + b - 480;
        if (strlen(s) > 8) return 1;
        add = 0;
        if (strlen(s) == 5) add += (s[4] - '0') * 60;
        else if (strlen(s) == 6) add += (s[4] - '0') * 600 + (s[5] - '0') * 60;
        else if (strlen(s) == 7) add += (s[4] - '0') * 60 + (s[6] - '0') * 6;
        else if (strlen(s) == 8) add += (s[4] - '0') * 600 + (s[5] - '0') * 60 + (s[7] - '0') * 6;
        if (s[3] == '+') tm += add;
        else tm -= add;
        tm %= 1440;
        if (tm < 0) tm += 1440;
        printf("%02d:%02d\n", tm / 60, tm % 60);
    }
    return 0;
}