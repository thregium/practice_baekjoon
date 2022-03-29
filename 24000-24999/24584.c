#include <stdio.h>
#include <string.h>

/*
���� : [L, H](L <= H <= 100000)��° �Ҽ����� 6�ڸ� ������ P�� �κ� ���ڿ��� ���� �Ҽ��� ������ ���Ѵ�.
��� �Ҽ��� 0���� �������� �ʴ´�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� H���� �Ҽ��� ���� ����, ��� �Ҽ��� ����
sprintf �Լ��� �̿��Ͽ� ���ڿ��� ��ȯ �� strstr �Լ��� �̿��� P�� �κ� ���ڿ��� ���� �� Ȯ���Ѵ�.
�׷��� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �����佺�׳׽�, ���ڿ�

��ó : MidAtl 2021 H�� // NCNA 2021 C��
*/

char sieve[1572864], n[16], x[16];
int prime[103000];
int pp = 0;

int main(void) {
    int l, h, r = 0;
    for (int i = 2; i < 1300000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j < 1300000; j += i) sieve[j] = 1;
    }
    scanf("%d %d", &l, &h);
    scanf("%s", n);
    for (int i = l - 1; i < h; i++) {
        sprintf(x, "%d", prime[i]);
        if (strstr(x, n)) r++;
    }
    printf("%d", r);
    return 0;
}