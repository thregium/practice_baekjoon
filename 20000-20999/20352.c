#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

/*
���� : ���� ���̰� �־��� �� ���� �ѷ��� ���Ѵ�.

�ذ� ��� : ���� ���̿��� ���̸� ������ �������� �ϸ� �������� ���´�. ���⼭ 2���̸� ���ϸ� �ѷ��� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : NWERC 2019 PC��
*/

int main(void) {
    long long a;
    scanf("%lld", &a);
    printf("%.16lf", sqrt(a / PI) * PI * 2);
    return 0;
}