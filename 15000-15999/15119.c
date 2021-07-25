#include <stdio.h>

/*
문제 : B와 R로 이루어진 100000자 이하의 문자열이 주어질 때, B와 R의 개수 차가 가장 큰 구간을 구한다.

해결 방법 : B와 R을 각각 -1, 1로 본 다음, 누적 합을 구해준다. 누적 합이 가장 큰 지점과 가장 작은 지점을 찾은 다음
[먼저 나오는 지점 + 1, 나중에 나오는 지점] 구간을 구하면 누적 합 차가 가장 큰 곳이로 개수 차이도 가장 큰 곳이 된다.

주요 알고리즘 : 누적 합

출처 : PacNW 2017 G/S번
*/

char s[103000];
int sum[103000];

int main(void) {
    int highest = 0, lowest = 0;
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++) {
        if (s[i] == 'R') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
        if (sum[i] > sum[highest]) highest = i;
        if (sum[i] < sum[lowest]) lowest = i;
    }
    if (lowest < highest) printf("%d %d", lowest + 1, highest);
    else printf("%d %d", highest + 1, lowest);
    return 0;
}