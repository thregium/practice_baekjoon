#include <stdio.h>

/*
���� : N(N <= 20) �Ѹ��������� �޼����� ���� �־����� ���� ���� ���� �� ����� �����̰� �������� �׷����� ���Ѵ�.

�ذ� ��� : ���ʿ��� X��°�� ���� �޽����� X�� ���� ����� �� ���̴�. ������ ������ ���� �� ����� ã�� �� �ְ�,
�� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2006 F��
*/

int mess[32][32];
char s[32][64];

int main(void) {
    int n, r = 0;
    char c;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for (int j = 1; j < n; j++) {
                scanf(" %c", &c);
                if (c == 'N') mess[i][j] = 1;
                else mess[i][j] = 0;
            }
        }
        printf("Group %d\n", tt);

        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mess[i][j]) {
                    printf("%s was nasty about %s\n", s[(i - j + n) % n], s[i]);
                    r++;
                }
            }
        }
        if (r == 0) printf("Nobody was nasty\n");
        printf("\n");
    }
    return 0;
}