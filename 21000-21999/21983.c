#include <stdio.h>
#include <math.h>

/*
���� : ���̰� A(1 <= A <= 10^18)�� ���������� �ѷ��� ���Ѵ�.

�ذ� ��� : A�� �����ٿ� 192�� �������� �������� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : NWERC 2021 PB��
*/

int main(void) {
    double a;
    scanf("%lf", &a);
    printf("%.9f", sqrt(a) * sqrt(sqrt(192)));
    return 0;
}