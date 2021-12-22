#include <stdio.h>

/*
문제 : 문제에 주어진 형태의 달력에서 연, 월, 일이 주어질 때, 1000년 1월 1일까지 남은 날 수를 구한다.

해결 방법 : 달력의 날짜를 직접 돌려가며 계산하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2012 A번
*/

int main(void) {
    int t, y, m, d, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &y, &m, &d);
        r = 1;
        while (!(y == 999 && m == 10 && d == 20)) {
            if (y % 3) {
                d++;
                if (d == 21 || (d == 20 && (~m & 1))) {
                    d = 1;
                    m++;
                }
                if (m == 11) {
                    m = 1;
                    y++;
                }
            }
            else {
                d++;
                if (d == 21) {
                    d = 1;
                    m++;
                }
                if (m == 11) {
                    m = 1;
                    y++;
                }
            }
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}