#include <stdio.h>

/*
���� : 1���� N(N <= 100000)������ ���� �̷���� �������� i��° ���� i�� ���μҰ� �ƴ� ���� K���� ������ �ִ��� ã�� �ִٸ� �� �� �ϳ��� ����Ѵ�.

�ذ� ��� : 1�� ������ ���� �ڱ� �ڽŰ� ���μҰ� �ƴϰ�, ��� ���� 1�� �ڱ� �ڽ� + 1�� ���μ��̴�.
����, N - K - 1��° �������� i + 1�� ����� �� N - K��°���� 1(�̿� ���� 1���� N - K������ ���� ����ߴ�.),
�� ���� ������ i�� ����ϸ� 1���� N������ ��� ���� �� ���� ����ϸ鼭 ���μҰ� �ƴ� ���� ��Ȯ�� K���� ���� �� �ִ�.
��, K�� N�� ���� ��쿡�� 1�� � ���͵� ���μҰ� �ǹǷ� �׷��� ������ ���� �� ����.

�ֿ� �˰����� : ����, ������
*/

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == n) {
        printf("Impossible");
        return 0;
    }
    for (int i = 1; i < n - k; i++) {
        printf("%d ", i + 1);
    }
    printf("1 ");
    for (int i = n - k + 1; i <= n; i++) {
        printf("%d ", i);
    }
    return 0;
}