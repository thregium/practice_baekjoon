#include <stdio.h>

/*
문제 : 일과 월이 주어질 때, 2009년 기준으로 무슨 요일인지 구한다.

해결 방법 : 각 월별로 지나간 날들의 수를 미리 저장해둔 후, 몇 번째 날인지를 확인한다. 그 다음, 그 값을 7로 나눈 나머지에 따라
요일을 배정하면 된다.

주요 알고리즘 : 구현, 수학

출처 : COCI 08/09#4 2번
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int main(void) {
    int d, m, d2;
    scanf("%d %d", &d, &m);
    d2 = d + days[m];
    switch (d2 % 7) {
    case 0:
        printf("Wednesday");
        break;
    case 1:
        printf("Thursday");
        break;
    case 2:
        printf("Friday");
        break;
    case 3:
        printf("Saturday");
        break;
    case 4:
        printf("Sunday");
        break;
    case 5:
        printf("Monday");
        break;
    case 6:
        printf("Tuesday");
        break;
    default:
        return 1;
        break;
    }
    return 0;
}