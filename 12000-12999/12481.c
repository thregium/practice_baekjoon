#include <stdio.h>
#include <string.h>
#include <math.h>

/*
문제 : 길이 60 이하의 '1', '0', '?'로 이루어진 문자열이 주어진다. 이때, 이 문자열에서 '?'를
'0' 또는 '1'로 바꾸고 이진수로 읽어 만들 수 있는 제곱수가 하나뿐이라면 그러한 제곱수를 이진수로 출력한다.
문자열의 첫 글자는 '1'로 시작하고 '?'는 20자 이하로 주어진다.

해결 방법 : '?'가 20자 이내로 주어지므로 모든 '?'를 0 또는 1로 바꾸는 모든 경우를 시도해본다.
제곱수인지 여부를 확인할 때에는 실수 오차에 유의한다.

주요 알고리즘 : 수학, 브루트 포스

출처 : GCJ 2011R3 D1번
*/

char s[128];

int issqr(long long x) {
    long long y = sqrt(x);
    for (int i = -1; i <= 1; i++) {
        if ((y + i) * (y + i) == x) return 1;
    }
    return 0;
}

void printbin(long long x) {
    char s[128] = { 0, };
    char c;
    for (int i = 0; x; i++) {
        s[i] = '0' + (x & 1);
        x >>= 1;
    }
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s", s);
}

int main(void) {
    int t, l, q, p, r;
    long long n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        q = 0, l = strlen(s), r = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '?') q++;
        }
        for (int i = 0; i < (1 << q); i++) {
            p = 0;
            n = 0;
            for (int j = 0; j < l; j++) {
                if (s[j] == '1') n += (1LL << (l - j - 1));
                else if (s[j] == '?') {
                    if ((i >> (p++)) & 1) n += (1LL << (l - j - 1));
                }
            }
            if (issqr(n)) {
                printf("Case #%d: ", tt);
                printbin(n);
                printf("\n");
                r = 1;
                break;
            }
        }
        if (!r) return 1;
    }
    return 0;
}