#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� 10^6 ������ 16���� ���ڿ��� �־��� ��, �̸� N(N <= 500000)���� Ư�� ���̷� �߶� ��ȯ��
���ڿ��� 10���� ���� ���� ���Ѵ�. ��, ��ȯ�� 10���� ���� �׻� ������ ���� �ʴ´�.

�ذ� ��� : N���� ���̰� ���� �� ���� ������ ���ϴ� ���̸�ŭ �� ���ڿ��� �ڸ� ����, �ش� ���ڿ��� strtoll �Լ��� ����
10���� ���� �˾Ƴ��� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : �Ѿ�� 6ȸB C��
*/

char cy[1048576], mv[32], buf[32];

int main(void) {
    int n, p = 0;
    long long r = -1;
    scanf("%s", cy);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        if (buf[0] == 'c') {
            for (int j = 0; j < 2; j++) mv[j] = cy[p + j];
            mv[2] = '\0';
            r = strtoll(mv, NULL, 16);
            p += 2;
        }
        else if (buf[0] == 'i') {
            for (int j = 0; j < 8; j++) mv[j] = cy[p + j];
            mv[8] = '\0';
            r = strtoll(mv, NULL, 16);
            p += 8;
        }
        else if (buf[0] == 'l') {
            for (int j = 0; j < 16; j++) mv[j] = cy[p + j];
            mv[16] = '\0';
            r = strtoll(mv, NULL, 16);
            p += 16;
        }
        else return 2;
        if (p > 0 && cy[p - 1] == '\0') return 3;
        if (r < 0) return 1;
        printf("%lld ", r);
    }
    return 0;
}