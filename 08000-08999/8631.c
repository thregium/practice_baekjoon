#include <stdio.h>
#include <stdlib.h>
#define MOD 10000

/*
���� : N(N <= 200000)���� �ڿ���(<= 10^9)�� �־��� ��, �� �ڿ����� �������� �Ǵ� ������������
��ġ�ϴ� ����� �������� ���Ѵ�. ���� ���� ó���� �ٸ� ��ġ�� �ִ� ����� �ٸ� �� ����Ѵ�.

�ذ� ��� : �� ���� ������ ���� ���� ���� ��� (�� ���� ����)! ��ŭ�� ���س�����.
�׸��� ���� ���� ������� ���������� ���������� ���� �����ϹǷ� �ٽ� 2�� ���Ѵ�.
��� ������ Ư���ϹǷ� ��� ���Ŀ� �����Ѵ�.

�ֿ� �˰��� : ����, ���շ�, ����

��ó : JPOI 2008 3-3��
*/

int a[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c = 1, flag_r = 0, flag_o = 0, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            for (int j = 1; j <= c; j++) {
                r = (r * j);
                if (r >= MOD) {
                    flag_o = 1;
                    r %= MOD;
                }
            }
            c = 1;
            flag_r = 1;
        }
        else c++;
    }
    for (int j = 1; j <= c; j++) {
        r = (r * j);
        if (r >= MOD) {
            flag_o = 1;
            r %= MOD;
        }
    }
    if (flag_r) r = (r * 2);
    if (r >= MOD) {
        flag_o = 1;
        r %= MOD;
    }
    if (flag_o) printf("%04d", r);
    else printf("%d", r);
    return 0;
}