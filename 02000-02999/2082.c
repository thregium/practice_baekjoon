#include <stdio.h>

/*
문제 : 디지털 시계의 4 글자 가운데 일부 픽셀이 빈 칸으로 대체되었다. 원래 시계의 시각이 될 수 있는 값 가운데
가장 빠른 시각을 구한다. 항상 답이 있는 경우만 주어지고, 시계는 24시간 기준이다.

해결 방법 : 각 디지털 숫자를 비트마스킹으로 저장해둔 다음, 시계의 각 글자도 비트마스킹으로 정수 형태로 바꾼다.
그 다음, 가능한 모든 시각에 대해 모든 글자가 OR시 원래 숫자가 되는 가장 빠른 경우를 찾아
그 때의 시각을 출력하면 된다.

주요 알고리즘 : 구현, 비트마스킹

출처 : CHCI 2001RJ 3번
*/

char s[5][32];
int digit[4];
int nums[10] = { 31599, 4681, 29671, 29647, 23497, 31183, 31215, 29257, 31727, 31695 };

int main(void) {
    int t;
    for (int i = 0; i < 5; i++) {
        fgets(s[i], 24, stdin);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 3; k++) {
                digit[i] += (s[j][i * 4 + k] == '#') * (1 << ((4 - j) * 3 + (2 - k)));
            }
        }
    }

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            t = 1;
            if ((digit[0] | nums[i / 10]) != nums[i / 10]) t = 0;
            if ((digit[1] | nums[i % 10]) != nums[i % 10]) t = 0;
            if ((digit[2] | nums[j / 10]) != nums[j / 10]) t = 0;
            if ((digit[3] | nums[j % 10]) != nums[j % 10]) t = 0;
            if (!t) continue;
            printf("%02d:%02d", i, j);
            return 0;
        }
    }
    return 1;
}