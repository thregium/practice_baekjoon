#include <stdio.h>

/*
���� : N(N <= 10^6)���� �������� �־�����. M(M <= 10^6)���� ������ �����Ѵ�.
0. ������ 1�� ����� �� �� �ִ��� ���Ѵ�.
1. x��° ��Ʈ�� 1�� �ٲ۴�.

�ذ� ��� : ���� 1�� ����� ������ �����ϰ� �ִ´�. 0�� ������ ������ �� ���� ����Ѵ�.
1�� ������ ������ �� �� ���� ���ؼ� �� �� 1�� ��� �信�� 1�� ����, �� �� 0�� ��� 1�� ���Ѵ�. �� �� �ƴ϶�� �״�� �д�.
��, �̹� 1�� ��Ʈ��� �ƹ��͵� ���� �ʰ� �Ѿ�� �Ѵ�.

�ֿ� �˰����� : ����?

��ó : ������ 2018C A��
*/

int bin[1048576];

int main(void) {
    int n, m, o, p, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bin[i]);
        if (bin[i] == 1 && bin[i - 1] == 0) r++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &o);
        if (o == 0) {
            printf("%d\n", r);
        }
        else {
            scanf("%d", &p);
            if (bin[p]) continue;
            r -= bin[p - 1] + bin[p + 1] - 1;
            bin[p] = 1;
        }
    }
    return 0;
}