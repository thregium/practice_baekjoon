#include <stdio.h>

/*
���� : N(N <= 50)���� ���ڿ��� �־��� ��, �� ���ڿ��� ��ȣ�� �ű��.

�ذ� ��� : �ݺ����� fgets() �Լ��� �̿��� ���ڿ��� �Է¹����� ��ȣ�� ����ϰ� �Է¹��� ���ڿ��� �ٽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : PacNW 2010 P��
*/

char line[64];

int main(void) {
    int n;
    scanf("%d", &n);
    fgets(line, 60, stdin);
    for (int i = 1; i <= n; i++) {
        fgets(line, 60, stdin);
        printf("%d. %s", i, line);
    }
    return 0;
}