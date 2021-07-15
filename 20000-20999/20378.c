#include <stdio.h>
#include <string.h>

/*
���� : 1000�ڸ� ������ ������ �־�����, �� ���鿡 �ڸ��� ������ �ڿ����� ���ϸ� �ش� ���� ������ ĭ��ŭ �о ���� ���� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : ���� �ڿ������� ĳ���� ����ؼ� ���� ������ �Ѵ�. �� �� �ڸ� ������ �������� ĳ���� �����ִ� ��� �ڸ����� �޶����Ƿ� ���� ���� ���� �� ����.
ĳ���� ���ٸ� 1ĭ���� (������ ����)���� �ѹ��� �о��. �� �� ���� ���� �ִٸ� ���� �� �ְ�, ���ٸ� ���� �� ����.

�ֿ� �˰��� : ����, ����Ƽ��

��ó : MidC 1994 B��
*/

char number[1024], mul[1024];

int main(void) {
    int len, carry, r, t;
    while (scanf("%s", number) != EOF) {
        r = 1;
        len = strlen(number);
        for (int i = 1; i <= len; i++) {
            carry = 0;
            for (int j = len - 1; j >= 0; j--) {
                mul[j] = ((number[j] - '0') * i + carry) % 10;
                carry = ((number[j] - '0') * i + carry) / 10;
            }
            if (carry > 0) {
                r = 0;
                break;
            }
            r = 0;
            for (int j = 0; j < len; j++) {
                t = 1;
                for (int k = 0; k < len; k++) {
                    if ((number[k] - '0') != mul[(k + j) % len]) {
                        t = 0;
                        break;
                    }
                }
                r |= t;
            }
            if (!r) break;
        }

        if (r) printf("%s is cyclic\n", number);
        else printf("%s is not cyclic\n", number);
    }
    return 0;
}