#include <stdio.h>

/*
���� : N * N(N <= 100) ũ���� ���ڸ� K�� ���� �°� ������ ����Ѵ�.
1�� ��� ������ �ʰ�, 2�� ��� �¿� ����, 3�� ��� ���� �����̴�.

�ذ� ��� : 2���� �迭�� �̿��Ѵ�. ���� ������ ���� �ݴ� ������ ���� �ǰ�, �¿� ������ �� �࿡�� ���� �ݴ� ������ ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���ϴ� 2015 L��
*/

char s[128][128];

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    scanf("%d", &k);
    switch (k) {
    case 1:
        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
        }
        break;
    case 2:
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) printf("%c", s[i][j]);
            printf("\n");
        }
        break;
    case 3:
        for (int i = n - 1; i >= 0; i--) {
            printf("%s\n", s[i]);
        }
        break;
    default:
        return 1;
    }
    return 0;
}