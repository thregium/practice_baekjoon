#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 15)명의 이름과 생일이 각각 주어질 때, 생일이 가장 늦는 사람과 가장 빠른 사람의 이름을 각각 출력한다.

해결 방법 : 각각의 생일을 비교하기 쉽게 수로 만들고 비교하며 최댓값과 최솟값일 때의 이름을 각각 구하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : Hatyai 2012 H번
*/

int highest = 12345678, lowest = 87654321;
char highestname[32], lowestname[32], buff[32];

int bday_to_int(int y, int m, int d) {
    return y * 10000 + m * 100 + d;
}

int main(void) {
    int n, d, m, y, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", buff, &d, &m, &y);
        x = bday_to_int(y, m, d);
        if (x < lowest) {
            lowest = x;
            strcpy(lowestname, buff);
        }
        if (x > highest) {
            highest = x;
            strcpy(highestname, buff);
        }
    }
    printf("%s\n%s", highestname, lowestname);
    return 0;
}