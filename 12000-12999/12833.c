#include <stdio.h>

/*
���� : A XOR B�� Cȸ �� ����� ���Ѵ�.

�ذ� ��� : ��� ���� ���� ���� XOR ������ 2ȸ �ϸ� ������� ���ƿ´�. ����, C�� Ȧ���� ��쿡�� A XOR B�� ����ϰ�,
¦���� ��쿡�� A�� �״�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����?
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c & 1) printf("%d", a ^ b);
    else printf("%d", a);
    return 0;
}