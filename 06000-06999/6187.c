#include <stdio.h>

/*
���� : N(N <= 16)���� �ڿ��� ���� C(C <= 5000)�� ���� �ʴ� ���� ū ���� �ǵ��� �� ���� ���� ���Ѵ�.

�ذ� ��� : 2^N���� ��쿡 ���� ��Ʈ����ŷ�� ���� ��� ��츦 Ȯ���� ���� C ������ ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ����ŷ

��ó : USACO 2008O B2��
*/

int weight[32];

int main(void) {
    int c, n, r = 0, t;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) t += weight[j];
        }
        if (t <= c && t > r) r = t;
    }
    printf("%d", r);
    return 0;
}