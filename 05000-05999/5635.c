#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 15)���� �̸��� ������ ���� �־��� ��, ������ ���� �ʴ� ����� ���� ���� ����� �̸��� ���� ����Ѵ�.

�ذ� ��� : ������ ������ ���ϱ� ���� ���� ����� ���ϸ� �ִ񰪰� �ּڰ��� ���� �̸��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : Hatyai 2012 H��
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