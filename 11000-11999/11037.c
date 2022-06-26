#include <stdio.h>
#include <stdlib.h>

/*
���� : �ڿ��� N(N < 10^9)�� �־��� ��, 1���� 9 ���� ���� ��� �ڸ����� �ٸ��鼭 N���� ū �� ���
���� ���� ���� ����Ѵ�.

�ذ� ��� : 9�ڸ� ������ 1���� 9 ���� ���� �̷���� ��� �ڸ����� �ٸ� ���� �� 100���� �����̴�.
�̴� ���� ��� Ȯ���ϴ� ���� ������ ������, ���� ��� ���� �迭�� ������ ����, ������ �д�.
�� �ڷ� N�� ���� �� ���� 987654321 �̻��� ��� �� ū ���� �����Ƿ� 0��,
�� �� ��� �̺� Ž������ �� ������ 1 ū ���� ���� ���� ���ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����, �̺� Ž��

��ó : VHSPC 2014 L��
*/

int a[1048576], chk[16];
int acnt = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int rem, int n) {
    a[acnt++] = n;
    for (int i = 1; i <= 9; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        track(rem - 1, n * 10 + i);
        chk[i] = 0;
    }
}

int main(void) {
    int n, lo, hi, mid;
    track(9, 0);
    qsort(a, acnt, sizeof(int), cmp1);
    while (scanf("%d", &n) != EOF) {
        if (n >= 987654321) {
            printf("0\n");
            continue;
        }
        n++;
        lo = 0, hi = acnt - 1;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (a[mid] >= n) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", a[lo]);
    }
    return 0;
}
