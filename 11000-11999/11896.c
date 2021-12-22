#include <stdio.h>

/*
���� : ���� [A, B](A, B <= 10^9)�� �־��� ��, �� �������� ���̰� ����� N������ ���� �ϳ��� ��� ���� ���� �� �� �ִ� ������ �ִ�
N�� ���� ���Ѵ�.

�ذ� ��� : N�� ¦���� ��� ������� ���·� ��ġ�ϸ� ���� �����ϴ�. ������ Ȧ���� ��쿡�� �ּ� �� ���� ���� �Ұ������� �� �� �ִ�.
����, N�� ¦���� 2�� ��쿡�� ������ �������� �����Ƿ� ���� �Ұ����ϴ�. ���� A�� B ���̿��� 2�� ������ ¦���� ���� ���ϸ� �ȴ�.
�̴� ���콺 �Լ��� ���� ���� �� �ִ�.

�ֿ� �˰����� : ������, ����

��ó : GA5 2��
*/

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < 4) a = 4;
    if (a & 1) a++;
    if (b < 4) {
        printf("0");
        return 0;
    }
    if (b & 1) b--;
    a >>= 1;
    b >>= 1;
    printf("%lld", ((long long)b - a + 1) * ((long long)a + b));
    return 0;
}