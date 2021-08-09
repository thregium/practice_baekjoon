#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 10)개의 문자를 주어진 방식에 따라 암호화한 문자열이 주어진다. 이때, 각 문자들은 최대 한 개씩 잘못된 비트가 있을 수 있다.
만약 두 개 이상의 비트가 잘못되었다면 잘못된 비트가 있는 문자의 번호를 구하고, 모두 해독 가능하다면 해독한 문자열을 구한다.

해결 방법 : 각 문자 단위로 해당 문자의 비트들을 확인한 다음, 원래 비트가 대응하는 문자가 있는지 확인한다. 있다면 다음 문자를 확인하고,
없는 경우에는 한 비트씩 바꾸어 가며 대응하는 문자를 확인한다. 만약 전부 대응하지 않는다면 2개 이상의 비트가 잘못된 것이므로
해당 문자는 잘못된 것이다. 끝까지 잘못되지 않았다면 지금까지 해독한 문자열을 출력하면 된다.

주요 알고리즘 : 문자열, 구현, 브루트 포스

출처 : 정올 2004 초1번
*/

char s[64], pass[16], digi[8];
char* code[8] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

int main(void) {
    int n, t;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            digi[j] = s[i * 6 + j];
        }
        t = 0;
        for (int j = 0; j < 8; j++) {
            if (!strcmp(code[j], digi)) {
                t = 1;
                pass[i] = j + 'A';
                break;
            }
        }
        if (t) continue;
        for (int j = 0; j < 6; j++) {
            if (j > 0) digi[j - 1] = !(digi[j - 1] - '0') + '0';
            digi[j] = !(digi[j] - '0') + '0';
            for (int k = 0; k < 8; k++) {
                if (!strcmp(code[k], digi)) {
                    t = 1;
                    pass[i] = k + 'A';
                    break;
                }
            }
            if (t) break;
        }
        if (t) continue;
        else {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("%s", pass);
    return 0;
}