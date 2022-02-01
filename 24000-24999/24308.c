#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 100자 이하의 양수 또는 음수가 주어진다. 이때, 이 수에서 정확히 2개의 자릿수를 바꾸어
만들어지는 수 가운데 6으로 나누어 떨어지는 가장 큰 수를 구한다. 0으로 시작해서는 안 된다.

해결 방법 : 2개의 자리를 고른 뒤 두 자리가 모두 원래 자리와 다르며 6으로 나누어 떨어지는
(마지막 자리가 짝수이고 모든 자릿수의 합이 3인) 수를 모두 확인한다. 그 중 가장 큰 수를 고르면 되는데,
이는 모두 자릿수가 같으므로 문자열 비교를 통해 알아낼 수 있다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : IATI 2018 D1번
*/

char s[128], res[128], tmp[128], orig[128];

int main(void) {
    int l, rl = 0, sg = 0, sm = 0, r = 0;
    scanf("%s", s);
    l = strlen(s);
    sg = (s[0] == '-');
    if (sg) orig[0] = '-';
    rl = sg;
    if (l < 2) return 1;
    for (int i = 0; i < l; i++) {
        if (isdigit(s[i])) {
            sm += s[i] - '0';
            orig[rl++] = s[i];
        }
    }
    strcpy(tmp, orig);
    for (int i = sg; i < rl; i++) {
        for (int a = 9; a >= 0; a--) {
            if (i == sg && a == 0) continue;
            for (int j = i + 1; j < rl; j++) {
                if (orig[i] - '0' == a) continue;
                for (int b = 9; b >= 0; b--) {
                    if (orig[j] - '0' == b) continue;
                    if ((j != rl - 1 && ((orig[rl - 1] - '0') & 1)) || (j == rl - 1 && (b & 1))) continue;
                    if ((sm + (a - orig[i] + '0') + (b - orig[j] + '0')) % 3) continue;
                    tmp[i] = a + '0';
                    tmp[j] = b + '0';
                    if (r++ == 0) strcpy(res, tmp);
                    else if ((sg && strcmp(res, tmp) > 0) || (!sg && strcmp(res, tmp) < 0)) {
                        strcpy(res, tmp);
                    }
                    tmp[i] = orig[i];
                    tmp[j] = orig[j];
                }
            }
        }
    }
    printf("%s", res);
    return 1;
}