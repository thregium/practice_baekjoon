#include <stdio.h>

/*
���� : N(N <= 45)��Ʈ�� �� ��� ������ 1�� ���� ��Ʈ�� ������ ���Ѵ�.

�ذ� ��� : ��ȭ���� ���� ���� �̴� �Ǻ���ġ ���� N + 1��° ���� ���� ������ �� �� �ִ�.
����, �� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : TUD 2002 1��
*/

long long fibo[64];

int main(void) {
    int t, n;
    fibo[0] = 1;
    fibo[1] = 2;
    for (int i = 2; i <= 45; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%d\n\n", tt, fibo[n]);
    }
    return 0;
}