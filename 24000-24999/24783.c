#include <stdio.h>

/*
���� : �� �ڿ��� A, B, C(A, B, C <= 10000)�� �־��� ��,
A�� B�� ��Ģ������ �Ͽ� C�� ���� �� �ִ� �� Ȯ���Ѵ�. �̸� N(N <= 1000)�� �ݺ��Ѵ�.

�ذ� ��� : A�� B�� ���� �� �ִ� ��� ��쿡 ���� C�� ��������� ��찡 �ϳ��� �ִ� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����, ���̽� ��ũ

��ó : VTH 2016 A��
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a + b == c || a * b == c || a - b == c || b - a == c ||
            (a % b == 0 && a / b == c) || (b % a == 0 && b / a == c)) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}