#include <stdio.h>

/*
���� : ���� N(N <= 200000)�� �迭�� 2^30���� ���� �ڿ������� �����ִ�. �̶�, �� �迭�� ������ ������ ����
���� OR�� ���� �ڿ��� K(K < 2^30)�� ������ �ִ� �� ���ϰ�, �ִٸ� �׷��� ���� ��� �ϳ��� ����Ѵ�.

�ذ� ��� : OR�ؼ� K�� ���� �� �ִ�(K�� OR�� ���� K��) ������ ���� ����صд�.
�׸��� ��ϵ� ĭ�鸸���� �̷���� ������ ��� Ȯ���غ��� OR�� ���� K���� ���ɴ�.
�׷��� ��� �� ������ ����ϸ� �ǰ�, �迭�� ��� ������ ���� �׷��� ��찡 ���ٸ� �׷��� ������ ���� ���̴�.

�ֿ� �˰����� : �׸��� �˰�����, ��Ʈ����ŷ

��ó : ���ڴ� 2021 A��
*/

int a[204800], good[204800];

int main(void) {
    int n, k, x, e;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        good[i] = ((a[i] | k) == k);
    }
    for (int i = 0; i < n; i++) {
        if (!good[i]) continue;
        x = 0, e = i;
        while (e < n && good[e]) {
            x |= a[e];
            e++;
        }
        if (x == k) {
            printf("%d %d", i + 1, e);
            return 0;
        }
        i = e - 1;
    }
    printf("-1");
    return 0;
}