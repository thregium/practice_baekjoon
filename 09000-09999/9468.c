#include <stdio.h>

/*
���� : 15���� ���� �ƴ� ������ �̷���� �迭���� ���� ������ ���Ѵ�. ������ ���� ���̴� �ִ� 1�̴�.

�ذ� ��� : ���� ���� �޶����� ���� ������ ���� ���� 2�� ������ �ȴ�.

�ֿ� �˰��� : ����

��ó : GNY 2013 A��
*/

int main(void) {
    int p, k, r, l, x;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &k);
        r = 0;
        scanf("%d", &l);
        for (int i = 1; i < 15; i++) {
            scanf("%d", &x);
            if (x != l) r++;
            l = x;
        }
        if (r & 1) return 1;
        printf("%d %d\n", k, r >> 1);
    }
    return 0;
}