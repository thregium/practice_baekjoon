#include <stdio.h>

/*
���� : ������ 10 ������ ���� X�� �־��� ��, X�� Ȧ������ ¦������ ���Ѵ�.

�ذ� ��� : X�� 1�� and�� ����� 1�̸� Ȧ���̰� 0�̸� ¦���̴�.

�ֿ� �˰��� : ����, ��Ģ����?

��ó : NAQ 2013 A��
*/

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("%d is %s\n", x, (x & 1) ? "odd" : "even");
    }
    return 0;
}