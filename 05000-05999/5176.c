#include <stdio.h>

/*
���� : P���� M(P, M <= 500)���� �ڸ��� ���� ��, P���� �� ����� ���ϴ� �ڸ��� �����Ѵ�.
���ϴ� �ڸ��� ������ ��� ���� ���Ѵٸ� ���� ���ϴ� ����� ���� ���Ѵ�.

�ذ� ��� : �湮 �迭�� �̿��� �̹� �湮�� ��� �ᱣ���� 1 �ø��� �湮���� �ʾҴٸ� �湮�ϴ� ���� �ݺ���
���� �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����

��ó : USC 2007F B��
*/

int a[512];

int main(void) {
    int t, p, m, x, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = 0;
        scanf("%d %d", &p, &m);
        for (int i = 1; i <= m; i++) a[i] = 0;
        for (int i = 0; i < p; i++) {
            scanf("%d", &x);
            if (a[x]) r++;
            else a[x] = 1;
        }
        printf("%d\n", r);
    }
    return 0;
}