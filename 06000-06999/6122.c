#include <stdio.h>

/*
문제 : Nline(Nline <= 1458)개의 기구 사용 기록이 주어질때, N(N <= 145)명의 기구 사용 시간을 각각 구한다.
각 기구 사용 기록은 기구 시작/끝 여부와 사용자, 사용 시각(시간/분 순서)의 형태로 주어진다.
기구 사용 기록은 시간 순이고, 하루를 넘는 경우나 시작과 끝은 전부 대응된다.

해결 방법 : 각 기구를 시작하면 마지막으로 켠 시각을 저장하고, 끝내면 현재 시각에서 마지막으로 켠 시각을 뺀 값을
해당 사용자의 사용 시간에 더한다. 기록이 끝나면 각 사용자의 사용 시간을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2009O B1번
*/

int started[192], times[192];
char buff[16];

int main(void) {
    int n, nlines, x, h, m;
    scanf("%d %d", &n, &nlines);
    for (int i = 0; i < nlines; i++) {
        scanf("%d %s %d %d", &x, buff, &h, &m);
        if (buff[2] == 'A') started[x] = h * 60 + m;
        else times[x] += (h * 60 + m) - started[x];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", times[i] / 60, times[i] % 60);
    }
    return 0;
}