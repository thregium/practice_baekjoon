#include <stdio.h>

/*
문제 : 사슴 무리의 1994년 기준 연령별/성별 개체수와 생존율이 주어질 때, 이후 N - 1개 연도에 대해 매년 연령별/성별 개체수를 구한다.
(개체수, 생존율 생략)

해결 방법 : 첫 해(1994년)는 주어진 개체수를 그대로 출력하고, 이후로는 이전 연도의 개체수와 생존율에 따라
해당 연도의 연령별/성별 개체수를 계산해 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 사칙연산

출처 : MidC 1994 3번
*/

int nums[96][3][2], sz[96];

int round(int n) {
    if (n % 100 >= 50) return n / 100 + 1;
    else return n / 100;
}

int main(void) {
    int n;
    printf("         HERD     ADULT     ADULT     MALE     FEMALE     MALE     FEMALE\n");
    printf("YEAR     SIZE     MALES    FEMALES    FAWNS     FAWNS    NEWBORN   NEWBORN\n");
    printf("----   -------   -------   -------   -------   -------   -------   -------\n");
    nums[0][0][0] = 1372, nums[0][0][1] = 1280, nums[0][1][0] = 686, nums[0][1][1] = 640, nums[0][2][0] = 1703, nums[0][2][1] = 3714;
    sz[0] = 9395;
    printf("1994   %7d   %7d   %7d   %7d   %7d   %7d   %7d\n", sz[0], nums[0][2][0], nums[0][2][1], nums[0][0][0] + nums[0][1][0], nums[0][0][1] + nums[0][1][1], nums[0][0][0], nums[0][0][1]);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        nums[i][0][0] = round(nums[i - 1][2][1] * 78);
        nums[i][0][1] = round(nums[i - 1][2][1] * 72);
        nums[i][1][0] = round(nums[i - 1][0][0] * 55);
        nums[i][1][1] = round(nums[i - 1][0][1] * 55);
        nums[i][2][0] = round(nums[i - 1][1][0] * 60 + nums[i - 1][2][0] * 15);
        nums[i][2][1] = round(nums[i - 1][1][1] * 60 + nums[i - 1][2][1] * 90);
        sz[i] = nums[i][0][0] + nums[i][0][1] + nums[i][1][0] + nums[i][1][1] + nums[i][2][0] + nums[i][2][1];
        printf("%d   %7d   %7d   %7d   %7d   %7d   %7d   %7d\n", i + 1994, sz[i], nums[i][2][0], nums[i][2][1], nums[i][0][0] + nums[i][1][0], nums[i][0][1] + nums[i][1][1], nums[i][0][0], nums[i][0][1]);
    }
    return 0;
}