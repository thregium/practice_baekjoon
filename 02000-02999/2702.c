#include <stdio.h>

/*
���� : A, B(A, B <= 1000)�� �ּҰ������ �ִ������� ���� ���Ѵ�.

�ذ� ��� : A�� B�� ũ�Ⱑ ����� �����Ƿ� �ּҰ������ A�� ����� �ϳ��� ���캸�� Ȯ���ϰ�
�ִ������� A ������ ���鿡 ���� �ϳ��� ���캸���� �ð� ���� ���ư��� ���� �����ϴ�.

�ֿ� �˰��� : ����, ���Ʈ ����
*/

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        for (int i = a; i <= a * b; i += a) {
            if (i % b == 0) {
                printf("%d ", i);
                break;
            }
        }
        for (int i = a; i >= 1; i--) {
            if (a % i == 0 && b % i == 0) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}