#include <stdio.h>

/*
문제 : ISBN의 13자리 가운데 한 자리를 알 수 없을 때, 알 수 없는 자리의 값을 구한다.
모든 홀수 번째 자리 숫자와 (짝수 번째 자리 숫자 * 3)의 합이 10의 배수가 되어야 한다.

해결 방법 : 알 수 없는 자리로 가서 0부터 9까지의 숫자를 하나씩 넣어보며 조건을 만족하는지 확인한다.
만족하는 수가 나오면 그 값을 출력하면 된다.(그러한 값은 유일하므로)

주요 알고리즘 : 브루트 포스

출처 : 전북대 2017 C번
*/

char s[16];

int main(void) {
    int r;
    scanf("%s", s);
    for (int i = 0; i < 13; i++) {
        if (s[i] != '*') continue;
        for (int j = 0; j < 10; j++) {
            s[i] = '0' + j;
            r = 0;
            for (int k = 0; k < 13; k++) {
                if (k & 1) r += (s[k] - '0') * 3;
                else r += s[k] - '0';
            }
            if (r % 10) continue;
            printf("%d", j);
            return 0;
        }
    }
    return 1;
}
