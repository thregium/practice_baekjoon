#include <stdio.h>

/*
���� : �־��� �ڵ带 �ؼ��Ͽ� �̵� ����� �Ÿ��� ����Ѵ�.

�ذ� ��� : ���� 2�ڸ��� �̵� ������ ���ϰ� ���� 3�ڸ��� �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : CCC 2021J 3��
*/

int main(void) {
    int n, l = -1;
    while (1) {
        scanf("%d", &n);
        if (n == 99999) break;
        if (n < 1000) printf("%s %03d\n", l == 1 ? "left" : "right", n);
        else if ((n / 1000) & 1) printf("left %03d\n", n % 1000);
        else printf("right %03d\n", n % 1000);
        l = ((n / 1000) & 1);
    }
    return 0;
}