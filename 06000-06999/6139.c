#include <stdio.h>

/*
���� : N(N <= 100000)���� å�� �дµ� T�е��� 1�п� S���� �ӵ��� å�� �а� R(T, S, R <= 100)�е��� ���ٰ� �Ѵ�.
å�� ���� �дµ� �ɸ��� �ð��� ���Ѵ�.

�ذ� ��� : å�� �д� �ð����� ���� å �������� �Ѱܰ��� N �̻��� �� �� ������ �ð��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : USACO 2007N B2��
*/

int main(void) {
    int n, k, s, t, r, p, tr;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &s, &t, &r);
        p = 0, tr = 0;
        while (p < n) {
            for (int i = 0; i < t; i++) {
                tr++;
                p += s;
                if (p >= n) break;
            }
            if (p >= n) break;
            tr += r;
        }
        printf("%d\n", tr);
    }
    return 0;
}