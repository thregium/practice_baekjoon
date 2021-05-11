#include <stdio.h>
#include <string.h>

/*
���� : �� �θ� ����(N <= 1000)�� �̷���� ���� ���� �־�����. �� ���� ����� �θ� ���ڷ� ����Ѵ�.
��, ���� 1000�� �Ѵ� ��쿡�� Ư���� ���ڿ��� ����ؾ� �Ѵ�.

�ذ� ��� : 1000 ������ ��� �θ� ���ڸ� ��ó���� ���� �̸� ���س��� ���� ���� �Ŀ��� �ش��ϴ� �θ� ���ڵ��� �����Ѵ�.
�� ���� �� �θ� ���ڸ� ���� ����� ���� �� �ְ�, �̸� ���س��� ������ �����Ƿ� �θ� ���ڷ� �ٲٴ� �͵� ����.

�ֿ� �˰��� : ����, ����, ���ڿ�

��ó : CCC 1996 4��
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