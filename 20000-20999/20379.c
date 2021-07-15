#include <stdio.h>

/*
���� : �罿 ������ 1994�� ���� ���ɺ�/���� ��ü���� �������� �־��� ��, ���� N - 1�� ������ ���� �ų� ���ɺ�/���� ��ü���� ���Ѵ�.
(��ü��, ������ ����)

�ذ� ��� : ù ��(1994��)�� �־��� ��ü���� �״�� ����ϰ�, ���ķδ� ���� ������ ��ü���� �������� ����
�ش� ������ ���ɺ�/���� ��ü���� ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ��Ģ����

��ó : MidC 1994 3��
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