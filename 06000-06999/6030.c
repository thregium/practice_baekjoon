#include <stdio.h>

/*
���� : ���� P, Q(P, Q <= 6000)�� ����� �Ǵ� �ڿ����� �������� ���ʷ� ���� ���Ѵ�.

�ذ� ��� : ��� P�� Q�� ���� Ȯ���ϴٰ� ������ ����� �ƴ϶�� �Ѿ��, ������ �ش� �������� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : USACO 2010F B1��
*/

int main(void) {
    int p, q;
    scanf("%d %d", &p, &q);
    for (int i = 1; i <= p; i++) {
        if (p % i) continue;
        for (int j = 1; j <= q; j++) {
            if (q % j) continue;
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}