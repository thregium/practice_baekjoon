#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ��Ʈ���ī ������ �ִ�. �� ��Ʈ���ī �ȿ� �� ���� ��Ʈ���ī�� 1��������
���� �� �ִٸ�, �־��� ũ��(<= 10^9)�� ��Ʈ���ī���� �ִ��� �����ϸ�
������ ��Ʈ���ī�� ������ ���Ѵ�.

�ذ� ��� : ���� ���� �ߺ��Ǵ� ũ���� ��Ʈ���ī�� �ߺ� ���� ����.
�̴� ������ ���� ������ ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : SLPC 2010_1 D��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, cnt, best;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        cnt = 1, best = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                if (cnt > best) best = cnt;
                cnt = 1;
            }
            else cnt++;
        }
        if (cnt > best) best = cnt;
        printf("%d\n", best);
    }
    return 0;
}