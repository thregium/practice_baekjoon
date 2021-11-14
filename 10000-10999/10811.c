#include <stdio.h>

/*
���� : N(N <= 100)���� �ٱ��ϰ� ������� �ִ�. M(M <= 100)���� �ٲٴ� ���� �� �ٱ����� ������ ����Ѵ�.
�� ����ÿ��� I�� �ٱ��Ϻ��� J�� �ٱ��ϱ����� ������ �������� �Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. swap() �Լ��� ����ϰ� for���� ������ 2�� �����ϴ� ������� �����ߴ�.

�ֿ� �˰��� : ����, �ùķ��̼�
*/

int a[128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        for (int j = x, k = y; j < k; j++, k--) {
            swap(&a[j], &a[k]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}