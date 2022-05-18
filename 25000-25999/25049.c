#include <stdio.h>
#define INF 1234567890987654321

/*
���� : N(N <= 500000)���� �뷡�� ���� �� �뷡�� ��ȣ��(|| <= 10^9)�� �־�����
���� ��� �뷡�� ��ȣ�� ���� �ִ��� ���Ѵ�.
�뷡�� ���ʷ� ��� 2������ ������(�Ǵ� ���� �뷡��) �ǵ��ư� �� �ִ�. ����, �� �뷡�� 3�� �̻� ���� �� ����.

�ذ� ��� : �켱 ��� �뷡�� 1��, �Ǵ� 2���� ���� �� �ִٴ� ���� �� �� �ִ�.
2�� ��� �뷡�� ����� 2�� �̻��� ������� �ϸ�, �̴� 5���� ���¸� ������ DP�� ���� ������ ���� �� �ִ�.

�ֿ� �˰��� : DP

��ó : DGIST 2022 F��
*/

int p[524288];
long long mem[524288][7];

long long big(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j < 7; j++) mem[i][j] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        mem[i][1] = big(mem[i - 1][0], mem[i - 1][1]) + p[i];
        mem[i][2] = big(mem[i - 1][1], mem[i - 1][2]);
        mem[i][3] = big(mem[i - 1][2], mem[i - 1][3]) + p[i];
        mem[i][4] = big(mem[i - 1][3], mem[i - 1][4]);
        sum += p[i];
    }
    printf("%lld", sum + big(big(big(mem[n][0], mem[n][1]), big(mem[n][2], mem[n][3])), mem[n][4]));
    return 0;
}