#include <stdio.h>

/*
���� : �� ���� X, Y(-10^9 <= X, Y <= 10^9)�� �־��� ��, X + Y�� ���Ѵ�.

�ذ� ��� : X + Y�� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : CERC 2008 PA��
*/

int main(void) {
    int t, x, y;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x + y);
    }
    return 0;
}