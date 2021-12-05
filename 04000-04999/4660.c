#include <stdio.h>

/*
���� : N(N <= 4)���� ���� L(L < 80)�� ���忡�� ������ �Ѵ�. �� ����� C(C <= 200)���� ī�带 ���ʷ� ����� �����ϰ�,
�� ī�带 ������ �� ���� ĭ ������ ù �ش� ���� ������ ĭ���� �̵��Ѵ�. 2���� ���� ������ ��찡 �ִµ�,
�̴� �̸� �� �� �����ϸ� �ȴ�.
���� ������ ĭ�� �����ϰų� ������ ĭ�� ����ģ ��� ������ �̱�� �� ��, ������ �̱�� ����� �� ������ �� ī���� ���� ���Ѵ�.
�̱� ����� ���ٸ� �׶����� �� ī���� ���� ����Ѵ�.

�ذ� ��� : ���� ������ ������ �ùķ��̼��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 2000 C��
*/

char board[128], buff[4];
int player[4];

int main(void) {
    int n, l, c, t = 0, e, p;
    while (1) {
        scanf("%d %d %d", &n, &l, &c);
        if (n == 0) break;
        for (int i = 0; i < n; i++) player[i] = -1;
        scanf("%s", board);
        e = 0, p = 0;
        for (int i = 0; i < c; i++) {
            scanf("%s", buff);
            if (e) continue;
            for (int ii = 0; buff[ii]; ii++) {
                t = 0;
                for (int k = player[p] + 1; k < l; k++) {
                    if (board[k] == buff[ii]) {
                        player[p] = k;
                        t = 1;
                        break;
                    }
                }
            }
            if (!t || player[p] == l - 1) {
                printf("Player %d won after %d cards.\n", p + 1, i + 1);
                e = 1;
            }
            p = (p + 1) % n;
        }
        if (!e) printf("No player won after %d cards.\n", c);
    }
    return 0;
}