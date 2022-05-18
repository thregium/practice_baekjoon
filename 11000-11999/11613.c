#include <stdio.h>
#include <stdlib.h>

/*
문제 : 디지털 숫자 형태로 이루어진 두 자연수(< 10^8)의 덧셈을 한 결과를 디지털 숫자 형태로 출력한다.

해결 방법 : 각 글자의 부분들을 문자로 치환하여 바꾸는 작업을 우선 한다.
그 다음, 그 문자열에서 두 수를 뽑아서 더하고 그것을 다시 문자열로 바꾸어둔다.
그 문자열을 다시 처음 했던 방식의 반대로 그림으로 바꾸어 출력하면 된다.

주요 알고리즘 : 구현, 파싱

출처 : CERC 2015 A번
*/

char s[7][128], t[32], t2[32], res[7][128];
const char* digits[7] = { "xxxxx  ....x  xxxxx  xxxxx  x...x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  .....",
"x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..",
"x...x  ....x  ....x  ....x  x...x  x....  x....  ....x  x...x  x...x  ..x..",
"x...x  ....x  xxxxx  xxxxx  xxxxx  xxxxx  xxxxx  ....x  xxxxx  xxxxx  xxxxx",
"x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..",
"x...x  ....x  x....  ....x  ....x  ....x  x...x  ....x  x...x  ....x  ..x..",
"xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  ....x  xxxxx  xxxxx  ....." };

int main(void) {
    int a, b, p = -1, ok;
    for (int i = 0; i < 7; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; s[0][i]; i += 6) {
        for (int j = 0; j <= 10; j++) {
            ok = 1;
            for (int ii = 0; ii < 7; ii++) {
                for (int jj = 0; jj < 5; jj++) {
                    if (s[ii][i + jj] != digits[ii][j * 7 + jj]) ok = 0;
                }
            }
            if (ok) t[i / 6] = (j == 10 ? '+' : ('0' + j));
        }
        if (t[i / 6] == '+') p = i / 6;
    }
    if (p < 0) return 1;
    a = strtoll(t, NULL, 10);
    b = strtoll(t + p + 1, NULL, 10);
    sprintf(t2, "%d", a + b);
    for (int i = 0; t2[i]; i++) {
        for (int ii = 0; ii < 7; ii++) {
            for (int jj = 0; jj < 5; jj++) {
                res[ii][i * 6 + jj] = digits[ii][(t2[i] - '0') * 7 + jj];
            }
            if (i > 0) res[ii][i * 6 - 1] = '.';
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}