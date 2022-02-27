#include <stdio.h>

/*
문제 : N + 2(N <= 200000)개의 칸으로 이루어진 게임 판의 A번 칸에 말이 오른쪽 방향을 보고 있다.
'#'가 쓰인 칸에 닿으면 반대 방향으로 말의 방향이 바뀌고 '#'은 '.'으로 바뀐다.
0번 또는 N + 1번 칸에 닿으면 반대 방향으로 말의 방향이 바뀐다. 이때, 모든 '#'이 사라지기까지
말이 이동하는 횟수를 구한다. 말은 한번에 1칸씩 움직인다.

해결 방법 : 현재 말이 이동하는 구간의 시작과 끝점을 움직이면서 방향에 따라 다음 시작/끝점까지의
거리를 구해나가는 방식으로 답을 찾으면 된다.

주요 알고리즘 : 구현, 투 포인터

출처 : JOI 2021예2 1번
*/

char s[204800];

int main(void) {
    int n, a, st, ed, d = 1;
    long long r = 0;
    scanf("%d %d", &n, &a);
    scanf("%s", s + 1);
    s[0] = 'X', s[n + 1] = 'X';
    st = a, ed = a;
    while (s[st] == '.') st--;
    while (s[ed] == '.') ed++;
    while (st != 0 || ed != n + 1) {
        if (d) {
            r += ed - a;
            a = ed;
            if (ed <= n) {
                ed++;
                while (s[ed] == '.') ed++;
            }
            d = 0;
        }
        else {
            r += a - st;
            a = st;
            if (st > 0) {
                st--;
                while (s[st] == '.') st--;
            }
            d = 1;
        }
    }
    printf("%lld\n", r);
    return 0;
}