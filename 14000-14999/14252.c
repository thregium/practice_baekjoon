#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 50)���� 100000 ������ �ڿ����� �־�����. �̶�, �ּ����� �ڿ����� �߰��� �������� ���� ������ ���鳢���� GCD��
���� 1�� �ǰ� �Ϸ��� �Ѵ�. �߰��ؾ� �ϴ� �ڿ����� ������ ���Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� 10�� ������ ��� �ڿ������� �����غ��� �� 7���� ���� ������ ��� ����
���̿� �ִ� 1���� �ڿ����� ���������� ������ ���鳢���� GCD�� 1�� �ȴ�. ����, N���� �ڿ����� ������ ����,
������ ���鳢�� GCD�� 1���� Ȯ���Ѵ�. �׷��ϴٸ� �Ѿ��, �ƴ϶�� ���� 7�� �ֿ� �ش��ϴ��� Ȯ���Ѵ�.
7�� ���� �ϳ���� �ᱣ���� 2�� ���ϰ� �ƴ϶�� 1�� ���Ѵ�.

�ֿ� �˰��� : ����, ������

��ó : SRM 577D2 3��
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, r  = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        if (gcd(a[i], a[i - 1]) == 1) continue;
        else if (a[i] - a[i - 1] == 16 && (a[i] == 2200 || a[i] == 27846 || a[i] == 32230 || a[i] == 57876 || a[i] == 62260 || a[i] == 87906 || a[i] == 92290)) r += 2;
        else r++;
    }
    printf("%d", r);
    /*
    for (int i = 1; i <= 100000; i++) {
        for (int j = i + 2; j <= 100000; j++) {
            t = 1;
            for (int k = i + 1; k < j; k++) {
                if (gcd(i, k) == 1 && gcd(j, k) == 1) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                printf("%d - %d\n", i, j);
            }
        }
        if (i % 100 == 0) printf("%d completed\n", i);
    }
    */
    return 0;
}