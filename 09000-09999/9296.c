#include <stdio.h>

/*
���� : ���� L(L <= 100)�� �� ���ڿ��� �־��� ��, �� ���ڿ� ���� �ٸ� ������ ������ ���Ѵ�.

�ذ� ��� : �� ���ڿ��� Ȯ���ϸ� ���� �ٸ� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : UVaH 2012 A��
*/

char que[128], ans[128];

int main(void) {
    int t, l, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &l);
        scanf("%s%s", que, ans);
        r = 0;
        for (int i = 0; i < l; i++) {
            if (que[i] != ans[i]) r++;
        }
        printf("Case %d: %d\n", tt, r);
    }
    return 0;
}