#include <stdio.h>

/*
���� : �������� �Ŀ� Ÿ���� �־��� ��, �̰��� ���������� �־��� ���ǿ��� ã�� ����Ѵ�.(���� ����)

�ذ� ��� : �������� �־��� ��쿡 �°� ����Ѵ�. Ȧ�ο� ������ ���� ���� ó���ؾ� �Ѵ�.

�ֿ� �˰��� : ����

��ó : SWERC 1996 PB��
*/

int main(void) {
    int p, s;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &p, &s);
        if (p == 0) break;
        printf("Hole #%d\n", tt);
        if (s == 1) printf("Hole-in-one.\n\n");
        else if (s == p - 3) printf("Double eagle.\n\n");
        else if (s == p - 2) printf("Eagle.\n\n");
        else if (s == p - 1) printf("Birdie.\n\n");
        else if (s == p) printf("Par.\n\n");
        else if (s == p + 1) printf("Bogey.\n\n");
        else printf("Double Bogey.\n\n");
    }
    return 0;
}