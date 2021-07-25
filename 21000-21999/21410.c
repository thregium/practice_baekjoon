#include <stdio.h>
#include <string.h>

/*
���� : �ڿ��� A(A <= 10^18)�� �־��� ��, ���� A�̸� �ڸ����� ���� ���� ū �� ���� �ƴ� ���� B, C�� ���Ѵ�.

�ذ� ��� : A�� � �ڸ����� ���ؼ� �ش� ���� �� �ڸ����� ������ ���ؼ��� ���� �� �ִ� �ڸ����� ����
�ø��� �ִ� ���� ���� ��� �� ���� ���̴�. �׷���, �׻� �ø��� �ִ� ��찡 ���� ��캸�� �ڸ����� �� Ŀ���� ������
�ø��� �ֵ��� �ϴ� ���� ����. �ø��� �Ұ����� ���� ù �ڸ��� ���� �ø��� ������ ���� 19�� ��� ���̰�,
�ڿ������� Ȯ���ϸ� �ִ��� �ø��� ���� �ϵ��� ������ ����� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ����, ���ڿ�

��ó : ROI 2007H E��
*/

char a[32], b[32], c[32];

int main(void) {
    int len, digit, carry = 0, sum = 0;
    scanf("%s", a);
    len = strlen(a);
    if (len == 1 && a[0] == '1') {
        printf("1\n1 0");
        return 0;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (i > 0) {
            digit = a[i] - '0' + 10 - carry;
            if (digit == 19) {
                digit -= 10;
                carry = 0;
            }
            else carry = 1;
        }
        else {
            digit = a[i] - '0' - carry;
            carry = 0;
        }
        b[i] = ((digit + 1) >> 1) + '0';
        c[i] = (digit >> 1) + '0';
        sum += digit;
    }
    printf("%d\n", sum);
    printf("%s %s", b[0] == '0' ? b + 1 : b, c[0] == '0' ? c + 1 : c);
    return 0;
}