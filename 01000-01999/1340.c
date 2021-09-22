#include <stdio.h>
#include <string.h>

/*
문제 : 날짜와 시각이 주어질 때, 이 시각이 연도의 몇%를 지난 것인지 구한다.

해결 방법 : 파싱을 통해 해당하는 달을 구하고, 날짜를 구한 다음, 윤년인지 여부와 결합해 전체 연도에서 며칠째인지 구한다.
그 다음, 이를 이용해 전체 연도에서 몇분째인지를 구하고, 이를 전체 연도의 분에서 나눈 결과를 출력하면 된다.

주요 알고리즘 : 구현, 파싱
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
const char* months[] = { "", "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };
char mbuff[16];

int isleap(int x) {
    if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else if (x & 3) return 0;
    else return 1;
}

int main(void) {
    int month = 0, day, year, hour, min, time = 0, total = 525600;
    scanf("%s %d, %d %d:%d", mbuff, &day, &year, &hour, &min);
    for (int i = 1; i <= 12; i++) {
        if (!strcmp(mbuff, months[i])) month = i;
    }
    if (month == 0) return 1;
    if (isleap(year)) {
        for (int i = 3; i <= 12; i++) days[i]++;
        total = 527040;
    }
    time = (days[month] + day - 1) * 1440 + hour * 60 + min;
    printf("%.39f", (double)time / total * 100.0);
    return 0;
}