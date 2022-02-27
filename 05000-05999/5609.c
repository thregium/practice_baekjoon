#include <stdio.h>

/*
���� : �ֻ����� N(N <= 10000)������ ������ ������ �־��� ��, �Ź� �ֻ����� ���鿡 ���� ���� ���� ���Ѵ�.

�ذ� ��� : �ֻ����� ������ ������ �ùķ��̼��ϸ� �ȴ�. �̴� �ϵ��ڵ����� ó���ϴ� ���� ����.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JOi 2006�� 3��
*/

char buff[8];
int dice[6], td[6];
int rot[6][6] = { {1, 5, 2, 3, 0, 4}, {3, 1, 0, 5, 4, 2}, {2, 1, 5, 0, 4, 3},
    {4, 0, 2, 3, 5, 1}, {0, 2, 4, 1, 3, 5}, {0, 3, 1, 4, 2, 5} };
char* newsrl = "NEWSRL";

int main(void) {
    int n, r;
    for (int tt = 0;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < 6; i++) dice[i] = i + 1;
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            for (int j = 0; j < 6; j++) {
                if (buff[0] == newsrl[j]) {
                    for (int k = 0; k < 6; k++) td[k] = dice[rot[j][k]];
                    for (int k = 0; k < 6; k++) dice[k] = td[k];
                    r += dice[0];
                    break;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}