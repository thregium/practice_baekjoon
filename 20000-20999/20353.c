#include <stdio.h>
#include <math.h>

/*
���� : ���� A(A <= 10^18)�� �Ǵ� �簢���� �ѷ��� ������ ª�� �� ���� �ѷ��� ���Ѵ�.

�ذ� ��� : �ش� ���� ���簢���� ���̰�, sqrt(A)�� 4�� ���ϸ� �ѷ��� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : NWERC 2016 PA��
*/

int main(void) {
    long long a;
    scanf("%lld", &a);
    printf("%.16lf", sqrt(a) * 4);
    return 0;
}