#include <stdio.h>

/*
���� : �� ���� ���� ���� �ø��ų� ������ N(N <= 100)ȸ�� ������ �־��� ��, ���� ���� �ö󰡰ų� ������ Ƚ���� ���Ѵ�.
�߸��� �Է��� �־����� �ʴ´�.

�ذ� ��� : �߸��� �Է��� �־����� �ʱ� ������ 2ȸ �������� �ö󰬴ٸ� �ݵ�� ���� �ؿ��� ���� �ö� ���̸�,
2ȸ �������� �������ٸ� �ݵ�� ���� ������ ������ ������ ���� ���̴�. ����, �׷��� �ൿ�� Ƚ���� ���ϸ� �ȴ�.

�ֿ� �˰����� : ����, �ùķ��̼�

��ó : JAG 2014D A��
*/

char buff[8];

int main(void) {
    int n, r, last;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0, last = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            if (buff[1] == 'u') {
                if (last > 0) r++;
                else last = 1;
            }
            else {
                if (last < 0) r++;
                else last = -1;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}