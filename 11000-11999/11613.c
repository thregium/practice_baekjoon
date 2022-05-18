#include <stdio.h>
#include <stdlib.h>

/*
���� : ������ ���� ���·� �̷���� �� �ڿ���(< 10^8)�� ������ �� ����� ������ ���� ���·� ����Ѵ�.

�ذ� ��� : �� ������ �κе��� ���ڷ� ġȯ�Ͽ� �ٲٴ� �۾��� �켱 �Ѵ�.
�� ����, �� ���ڿ����� �� ���� �̾Ƽ� ���ϰ� �װ��� �ٽ� ���ڿ��� �ٲپ�д�.
�� ���ڿ��� �ٽ� ó�� �ߴ� ����� �ݴ�� �׸����� �ٲپ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�

��ó : CERC 2015 A��
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