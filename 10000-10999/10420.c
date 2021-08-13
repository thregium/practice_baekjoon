#include <stdio.h>

/*
문제 : 2014년 4월 2일부터 시작해 N(N <= 10000)일차 되는 날이 언제인지 구한다.

해결 방법 : N이 작은 편이므로 N일간의 움직임을 직접 시뮬레이션해본다. 윤년 처리에 주의한다.

주요 알고리즘 : 구현, 시뮬레이션, 수학

출처 : 서강대 2014 MB번
*/

int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int altmonth(int y, int m) {
    if (m != 2) return m;
    if ((y & 3) || !(y % 100) && y % 400) return 2;
    else return 0;
}

int main(void) {
    int n, y = 2014, m = 4, d = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        d++;
        if (d > days[altmonth(y, m)]) {
            d = 1;
            m++;
        }
        if (m > 12) {
            y++;
            m = 1;
        }
    }
    printf("%d-%02d-%02d", y, m, d);
    return 0;
}