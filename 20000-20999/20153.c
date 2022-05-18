#include <stdio.h>

/*
���� : N(N <= 2222222)���� �ڿ���(<= 2222222)�� �־��� ��, �ϳ��� ���� ���� XOR�� ����
���� ū ���� ���� ���Ѵ�.

�ذ� ��� : ��� ���� XOR�� �Ϳ��� �ϳ��� XOR�� �� ���鼭 �� �� ���� ����� ū ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ����ŷ, ���Ʈ ����

��ó : ���縯�� 2ȸ B��
*/

int a[2228224];

int main(void) {
    int n, xsum = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        xsum ^= a[i];
    }
    if (xsum > best) best = xsum;
    for (int i = 0; i < n; i++) {
        if ((xsum ^ a[i]) > best) best = (xsum ^ a[i]);
    }
    printf("%d%d", best, best);
    return 0;
}