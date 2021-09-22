#include <stdio.h>
#include <string.h>

/*
���� : ��¥�� �ð��� �־��� ��, �� �ð��� ������ ��%�� ���� ������ ���Ѵ�.

�ذ� ��� : �Ľ��� ���� �ش��ϴ� ���� ���ϰ�, ��¥�� ���� ����, �������� ���ο� ������ ��ü �������� ��ĥ°���� ���Ѵ�.
�� ����, �̸� �̿��� ��ü �������� ���°������ ���ϰ�, �̸� ��ü ������ �п��� ���� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�
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