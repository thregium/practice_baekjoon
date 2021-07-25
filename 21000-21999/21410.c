#include <stdio.h>
#include <string.h>

/*
문제 : 자연수 A(A <= 10^18)가 주어질 때, 합이 A이며 자릿수의 합이 가장 큰 두 음이 아닌 정수 B, C를 구한다.

해결 방법 : A의 어떤 자리에서 합해서 해당 수가 그 자릿수로 나오기 위해서는 나올 수 있는 자릿수의 합은
올림이 있는 경우와 없는 경우 두 가지 뿐이다. 그런데, 항상 올림이 있는 경우가 없는 경우보다 자릿수가 더 커지기 때문에
올림이 있도록 하는 것이 좋다. 올림이 불가능한 경우는 첫 자리인 경우와 올림을 포함한 합이 19인 경우 뿐이고,
뒤에서부터 확인하며 최대한 올림을 많이 하도록 수들을 만들면 된다.

주요 알고리즘 : 그리디 알고리즘, 수학, 문자열

출처 : ROI 2007H E번
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