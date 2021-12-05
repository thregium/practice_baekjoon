#include <stdio.h>

/*
���� : N * M(N, M < 10000, �ڿ���) ũ���� ���簢���� �־��� ��, �ڸ� �� �ִ� ���� ū ���簢���� �ڸ��� �ൿ��
�ݺ��Ͽ� ���� �� �ִ� ���簢���� ���� ���Ѵ�.

�ذ� ��� : ��͸� ���� �� ���� ���̰� ������ �� ���� �� ���� ���� ���� �� ������ �ϴ� ���簢���� ������� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���

��ó : LtOI 11II 1��
*/

int getres(int a, int b) {
    if (a == b) return 1;
    else return (a > b ? getres(a - b, b) : getres(a, b - a)) + 1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", getres(n, m));
    return 0;
}