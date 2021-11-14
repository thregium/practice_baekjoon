#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : ���ϰ� N(N <= 1000)���� ���� �־��� ��, �� �� ��� ���� ���̿������� ���� �� �� ���� ���� ���� ���Ѵ�.
���̿������� ������ �־��� ��Ĵ�� ���Ѵ�.

�ذ� ��� : �� ������ ���ڿ� �������� �Է¹��� ����, ������ �־��� ��Ĵ�� ���̿������� ���ϰ� ���� ū ���� ã�Ƴ�����.
�ִ񰪰� ���ٸ� strtoll �Լ��� �̿��� �� ���� ���� ã�´�.

�ֿ� �˰��� : ����, ����

��ó : ���ִ� 2021D1 A / 2021D2 A��
*/

char bd[16], cd[16], res[16];

int sqr(int x) {
    return x * x;
}

int main(void) {
    int n, t, best = -1;
    scanf("%s", bd);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cd);
        t = 0;
        for (int j = 0; j < 4; j++) {
            t += sqr(bd[j] - cd[j]);
        }
        t *= sqr(bd[4] - cd[4]) + sqr(bd[5] - cd[5]);
        t *= sqr(bd[6] - cd[6]) + sqr(bd[7] - cd[7]);
        if (t > best || (t == best && strtoll(cd, NULL, 10) < strtoll(res, NULL, 10))) {
            strcpy(res, cd);
            best = t;
        }
    }
    printf("%s", res);
    return 0;
}