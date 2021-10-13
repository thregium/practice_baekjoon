#include <stdio.h>

/*
문제 : 특정한 날짜가 연-월-일 형태로 주어질 때, 해당 날짜로부터 N(N <= 10000)일 째 되는 날의 날짜를 구한다.
날짜는 1900년 이상 2014년 이하 범위에서 주어진다.

해결 방법 : N의 범위가 작으므로 1일씩 날짜를 늘려가며 해당 날짜를 확인해가면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 서강대 2014C A번
*/

int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int altmonth(int y, int m) {
    if (m != 2) return m;
    if ((y & 3) || !(y % 100) && y % 400) return 2;
    else return 0;
}

int main(void) {
    int n, y, m, d;
    scanf("%d-%d-%d %d", &y, &m, &d, &n);
    for (int i = 1; i < n; i++) {
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