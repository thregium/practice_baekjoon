#include <stdio.h>

/*
���� : K���� �ָ� ���� ���� N(1 <= N, K <= 10^9)�� �Ѵٰ� �ϸ�, �̰��� ���ذ� �ƴϱ� ���ؼ� �ʿ��� ���� �������� ���Ѵ�.
�׻� ������ ��� -1�� ����Ѵ�.

�ذ� ��� : N�� 1�� ��� �׻� �����̹Ƿ� -1�� ����Ѵ�. �� ���� ���� ceil(k / (n - 1))���� �� �� ������ ���ذ� �ƴϹǷ�,
�� ���� k�� ���� ���� ���� �ȴ�.

�ֿ� �˰����� : ����

��ó : �Ѿ��E 2021 B��
*/

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);
    if (n <= 1) printf("-1");
    else printf("%d", (k + n - 2) / (n - 1) + k);
    return 0;
}