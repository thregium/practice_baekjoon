#include <stdio.h>
#include <string.h>

/*
���� : �־��� M(M <= 10)���� �ܾ� ��� "sheep"�� �� ������ ���Ѵ�. ��ҹ��ڸ� �����Ѵ�.

�ذ� ��� : �ܾ���� �Է¹��� �� strcmp�� ���� sheep�� ������ �Ź� Ȯ���غ��� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : ECNA PB��
*/

char s[16];

int main(void) {
    int n, m, r;
    scanf("%d", &n);
    for (int tt = 1; tt <= n; tt++) {
        scanf("%d", &m);
        r = 0;
        for (int i = 0; i < m; i++) {
            scanf("%s", s);
            if (!strcmp(s, "sheep")) r++;
        }
        printf("Case %d: This list contains %d sheep.\n", tt, r);
    }
    return 0;
}