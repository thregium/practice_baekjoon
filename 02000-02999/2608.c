#include <stdio.h>
#include <string.h>

/*
���� : �θ� ���ڷ� �����ִ� �� ���� ���� ���� �ƶ��� ���ڿ� �θ� ���ڷ� ����Ѵ�. ��, �� ���� ���� 4000���� �۴�.

�ذ� ��� : 4000 �̸��� ��� �θ� ���ڸ� �̸� �����ص� ���� �Է¹��� �� ���� ����ִ� ������ � ������ �� ���� ����� ã�´�.
�� ���� �� ���� ��ġ�� ���� �����ص� ������ ������ ����ϸ� �ȴ�.
*/

char nums[4096][32], n[32];

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
    scanf("%s", n);
    for (int i = 0; i < 4000; i++) {
        if (!strcmp(n, nums[i])) {
            sum += i;
            break;
        }
    }
    scanf("%s", n);
    for (int i = 0; i < 4000; i++) {
        if (!strcmp(n, nums[i])) {
            sum += i;
            break;
        }
    }
    printf("%d\n", sum);
    printf("%s", nums[sum]);
    return 0;
}