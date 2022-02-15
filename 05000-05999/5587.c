#include <stdio.h>

/*
���� : N * 2(N <= 100)���� ī�带 2���� ������ ������ ������ �־��� ��Ģ���� ī������� �Ѵ�.
�� ����� ���� ī����� �־��� ��, �� ����� ������ ���Ѵ�.

�ذ� ��� : ������ �־��� ��Ģ�� �ùķ��̼��Ͽ� ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JOI 2008�� 3��
*/

int card[256];

int main(void) {
    int n, x, h, sc, gc, turn, tmp;
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            card[x] = 1;
        }
        h = 0, sc = n, gc = n, turn = 0;
        while (sc && gc) {
            if (turn & 1) {
                tmp = 0;
                for (int i = h + 1; i <= n * 2; i++) {
                    if (card[i] == 0) {
                        tmp = 1;
                        card[i] = -1;
                        gc--;
                        h = i;
                        break;
                    }
                }
                if (!tmp) h = 0;
            }
            else {
                tmp = 0;
                for (int i = h + 1; i <= n * 2; i++) {
                    if (card[i] == 1) {
                        tmp = 1;
                        card[i] = -1;
                        sc--;
                        h = i;
                        break;
                    }
                }
                if (!tmp) h = 0;
            }
            turn++;
        }
        printf("%d\n%d\n", gc, sc);
        for (int i = 1; i <= n * 2; i++) card[i] = 0;
    }
    return 0;
}