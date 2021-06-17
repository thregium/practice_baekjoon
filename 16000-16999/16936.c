#include <stdio.h>
#include <stdlib.h>

/*
���� : ��� �ڿ����� 3���� �����ų�(3���� ������ �������� ���) 2�� ���ϴ� ���� �ݺ��ϰ� �� ������ ���� ������ ������ ������ �־�����.
�� ������ ������ ���� ������� ��迭�� ����Ѵ�.

�ذ� ��� : �� ������ �ݺ��� ���� ���μ� 3�� ������ �پ��� 2�� ������ �þ�� �ȴ�. ����, �� ���� ���μ� 3�� ������ 2�� ������ �����ص� ����
3�� ������ �پ��� ������, 2�� ������ �þ�� ������ �����ϸ� ���� ������ �ȴ�.

�ֿ� �˰��� : ����, ������, �׸��� �˰���
*/

long long b[128][3];

int cmp1(const void* a, const void* b) {
    long long a2 = *(long long*)a;
    long long b2 = *(long long*)b;
    if (a2 != b2) return a2 > b2 ? 1 : -1;
    long long a3 = *((long long*)a + 1);
    long long b3 = *((long long*)b + 1);
    return a3 < b3 ? 1 : a3 == b3 ? 0 : -1;
}

int main(void) {
    long long n, x;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        b[i][2] = x;
        while (!(x & 1)) {
            b[i][0]++;
            x >>= 1;
        }
        while (!(x % 3)) {
            b[i][1]++;
            x /= 3;
        }
    }
    qsort(b, n, sizeof(long long) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%lld ", b[i][2]);
    }
    return 0;
}