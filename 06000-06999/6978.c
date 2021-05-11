#include <stdio.h>
#include <string.h>

/*
문제 : 두 로마 숫자(N <= 1000)로 이루어진 덧셈 식이 주어진다. 이 식을 계산해 로마 숫자로 출력한다.
단, 합이 1000을 넘는 경우에는 특정한 문자열을 출력해야 한다.

해결 방법 : 1000 이하의 모든 로마 숫자를 전처리를 통해 미리 구해놓은 다음 덧셈 식에서 해당하는 로마 숫자들을 추출한다.
그 다음 각 로마 숫자를 더한 결과를 얻을 수 있고, 미리 구해놓은 값들이 있으므로 로마 숫자로 바꾸는 것도 쉽다.

주요 알고리즘 : 구현, 수학, 문자열

출처 : CCC 1996 4번
*/

char nums[4096][32];

int main(void) {
    int p, sum = 0;
    for (int i = 1; i < 4000; i++) {
        p = 0;
        if (i / 1000) {
            for (int j = 0; j < i / 1000; j++) nums[i][p++] = 'M';
        }
        if (i / 100 % 10) {
            if (i / 100 % 10 == 9) {
                nums[i][p++] = 'C';
                nums[i][p++] = 'M';
            }
            else if (i / 100 % 10 >= 5) {
                nums[i][p++] = 'D';
                for (int j = 0; j < i / 100 % 10 - 5; j++) nums[i][p++] = 'C';
            }
            else if (i / 100 % 10 == 4) {
                nums[i][p++] = 'C';
                nums[i][p++] = 'D';
            }
            else {
                for (int j = 0; j < i / 100 % 10; j++) nums[i][p++] = 'C';
            }
        }
        if (i / 10 % 10) {
            if (i / 10 % 10 == 9) {
                nums[i][p++] = 'X';
                nums[i][p++] = 'C';
            }
            else if (i / 10 % 10 >= 5) {
                nums[i][p++] = 'L';
                for (int j = 0; j < i / 10 % 10 - 5; j++) nums[i][p++] = 'X';
            }
            else if (i / 10 % 10 == 4) {
                nums[i][p++] = 'X';
                nums[i][p++] = 'L';
            }
            else {
                for (int j = 0; j < i / 10 % 10; j++) nums[i][p++] = 'X';
            }
        }
        if (i % 10) {
            if (i % 10 == 9) {
                nums[i][p++] = 'I';
                nums[i][p++] = 'X';
            }
            else if (i % 10 >= 5) {
                nums[i][p++] = 'V';
                for (int j = 0; j < i % 10 - 5; j++) nums[i][p++] = 'I';
            }
            else if (i % 10 == 4) {
                nums[i][p++] = 'I';
                nums[i][p++] = 'V';
            }
            else {
                for (int j = 0; j < i % 10; j++) nums[i][p++] = 'I';
            }
        }
    }
    
    int t, n, n1 = 0, n2 = 0;
    char buff[64] = { 0, };
    char num1[32], num2[32];
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", buff);
        strcpy(num1, strtok(buff, "+"));
        strcpy(num2, strtok(NULL, "="));
        for (int i = 1; i <= 1000; i++) {
            if (!strcmp(num1, nums[i])) n1 = i;
            if (!strcmp(num2, nums[i])) n2 = i;
        }
        printf("%s+%s=%s\n\n", num1, num2, n1 + n2 > 1000 ? "CONCORDIA CUM VERITATE" : nums[n1 + n2]);
    }
    return 0;
}