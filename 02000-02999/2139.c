#include <stdio.h>

/*
문제 : 연도와 날짜가 주어질 때, 이 날이 해당 연도의 몇 번째 날인지 구한다.

해결 방법 : 해당 연도가 윤년인지 확인한 다음, 해당 달 이전까지의 달의 날짜 수를 구하고 해당 일과 더하면 된다.

주요 알고리즘 : 구현, 수학

출처 : NZPC 2005 C번
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int isleap(int x) {
    if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else if (x & 3) return 0;
    else return 1;
}

int main(void) {
    int d, m, y;
    while (1) {
        scanf("%d %d %d", &d, &m, &y);
        if (d == 0) break;
        if (m > 2 && isleap(y)) printf("%d\n", days[m] + d + 1);
        else printf("%d\n", days[m] + d);
    }
    return 0;
}