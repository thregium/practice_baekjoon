#include <stdio.h>

/*
���� : 3���� ���� �ٸ� 100 ������ �ڿ����� �־��� ��, �� �� ���� ���ĵ� �������� �ƴ��� ���Ѵ�.

�ذ� ��� : �� ���� ���ʷ� a, b, c��� �ϸ� a > b�̰� b > c(��������)�̰ų� a < b�̰� b < c(��������)�̸� ���ĵ� ���̰�
�� �� �ƴ϶�� ���ĵ��� ���� ���̴�.

�ֿ� �˰��� : ����

��ó : MidC 2009 B��
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    printf("Gnomes:\n");
    for (int tt = 0; tt < n; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        if ((a > b && b > c) || (a < b && b < c)) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}