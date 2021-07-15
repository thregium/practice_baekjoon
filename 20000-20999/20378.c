#include <stdio.h>
#include <string.h>

/*
문제 : 1000자리 이하의 수들이 주어지면, 이 수들에 자릿수 이하의 자연수를 곱하면 해단 수를 임의의 칸만큼 밀어서 원래 수를 만들 수 있는지 구한다.

해결 방법 : 수의 뒤에서부터 캐리를 고려해서 곱셈 연산을 한다. 맨 앞 자리 수까지 왔음에도 캐리가 남아있는 경우 자릿수가 달라지므로 원래 수를 만들 수 없다.
캐리가 없다면 1칸부터 (숫자의 개수)까지 한번씩 밀어본다. 그 중 원래 수가 있다면 만들 수 있고, 없다면 만들 수 없다.

주요 알고리즘 : 수학, 빅인티저

출처 : MidC 1994 B번
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