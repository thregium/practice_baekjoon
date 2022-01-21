#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 10�� ������ ���ڷ� �̷���� ��ȣ�� �־�����. �̶�, �� ���ڸ� 2�� �̻� ������� �ʰ� ���� �� �ִ�
������ ���� �� ������ ���� ������ ��ȣ�� ���Ѵ�. �� ��ȣ ���� �Ÿ��� �� ��ȣ�� ���� ������ ����
���� ���� �Ǵ� 10^���� - ���� ���� �� �� ���� ���̴�. ���� �� ���� ������ ��� �� ���� ���� ����.

�ذ� ��� : 10!�� �׷��� ũ�� �ʱ� ������ �� ���ڵ��� 1���� ����ϴ� ��� ��쿡 ����
�Ÿ��� ���ؼ� ���� �� ���� ã���� �ȴ�. ��ȣ�� ���ڿ��� ���� ���� strtoll() �Լ��� ���� ���� �ٲ� �� �ִ�.
int ������ �Ѿ �� ������ 0���� ������ �� ������ �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : JAG 2015P B��
*/

char buff[16], chk[16];
long long before, after = -1, b10 = 1;

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long diff(long long x) {
    if (x < 0) return -1;
    return small(llabs(before - x), b10 - llabs(before - x));
}

void track(int c, long long n) {
    if (c == 0) {
        if (diff(n) > diff(after)) after = n;
        else if (diff(n) == diff(after) && n < after) n = after;
    }
    for (int i = 0; i < 10; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        track(c - 1, n * 10 + i);
        chk[i] = 0;
    }
}

int main(void) {
    scanf("%s", buff);
    before = strtoll(buff, NULL, 10);
    for (int i = strlen(buff); i > 0; i--) {
        buff[i - 1] = '0';
        b10 *= 10;
    }
    track(strlen(buff), 0);
    while (after < 0);
    for (int i = strlen(buff) - 1; i >= 0 && after > 0; i--, after /= 10) buff[i] = after % 10 + '0';
    printf("%s\n", buff);
    return 0;
}