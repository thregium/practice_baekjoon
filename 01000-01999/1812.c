#include <stdio.h>

/*
���� : N(N < 1000, N�� Ȧ��)���� ������ �������� ��ġ�Ǿ� �ִ�. �̶�, ������ �� ���� �յ��� ���� �־��� ��,
������ �� ������ ���ؼ� ����Ѵ�.

�ذ� ��� : ������ �� ������ ���� ���߱� ������ �־��� ��� ���� ���ϸ� ��ü �� ���� 2�谡 �ȴ�.
���� �� ������ 2�� ������ ��ü ���� ���� ���� �� �ִ�. �׷���, N�� Ȧ���̹Ƿ� ������ �� ���� �ٸ� ������ �����
������ ���� ���� �� �ִ�. �� ������ for ���� ������ ������ ���� �����ָ� ���� ���� �� �ִ�.

�ֿ� �˰����� : ����
*/

int a[1024];

int main(void) {
    int n, sum = 0, sub;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sum >>= 1;
    for (int i = 0; i < n; i++) {
        sub = 0;
        for (int j = (i + 1) % n; j != i; j = (j + 2) % n) sub += a[j];

        printf("%d\n", sum - sub);
    }
    return 0;
}