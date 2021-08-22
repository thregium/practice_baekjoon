#include <stdio.h>

/*
���� : N(N <= 200000)���� ���� �̷���� �� ������ �ִ�. �� ������ ���� �� �ϳ����� ��� N���� ���� �� + (K * �ٲ� Ƚ��)��
�ּҷ� ������� ���� ���� ����.

�ذ� ��� : ���̳��� ���α׷����� ���� �ذ��� �� �ִ�. ���������� �� �������� �׶��� �ּڰ��� �����صθ� �ȴ�.

�ֿ� �˰��� : DP

��ó : �����Ž� 2D2 C��
*/

int a[204800], b[204800];
long long mem[204800][2];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    mem[0][0] = a[0], mem[0][1] = b[0];
    for (int i = 1; i < n; i++) {
        mem[i][0] = small(mem[i - 1][0], mem[i - 1][1] + k) + a[i];
        mem[i][1] = small(mem[i - 1][1], mem[i - 1][0] + k) + b[i];
    }
    printf("%lld", small(mem[n - 1][0], mem[n - 1][1]));
    return 0;
}