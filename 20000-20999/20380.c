#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : D(D <= 10)차원 행렬이 주어지고 문자열이 주어진다. 문자열을 D개씩 주어진 대응대로(대응 생략) 수로 바꾼 다음,
해당 수들을 행렬로 바꾼 뒤 주어진 행렬에서 곱한 값을 결괏값으로 가져온다. 이를 다시 대응대로 문자열로 바꾸어 출력한다.
이때 문자열이 모자라는 경우에는 이후 문자를 공백으로 취급해야 한다.

해결 방법 : 문자열을 D개씩 쪼갠 다음 수로 대응시키고 행렬곱을 구한 다음 다시 문자열로 바꾸는 것을 반복하면 된다.

주요 알고리즘 : 구현, 수학, 문자열

출처 : MidC 1994 4번
*/

int mat[16][16], in[16], res[16];
char s[128], enc[128];

int main(void) {
    int d;
    char x;
    while (1) {
        scanf("%d", &d);
        if (d == 0) break;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        scanf("%c", &x);
        fgets(s, 100, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        for (int i = 0; s[i]; i += d) {
            for (int j = 0; j < d; j++) {
                if (s[i + j] == '\0') in[j] = 27;
                else if (isupper(s[i + j])) in[j] = s[i + j] - 'A' + 1;
                else if (s[i + j] == ' ') in[j] = 27;
                else if (s[i + j] == ',') in[j] = 28;
                else if (s[i + j] == '.') in[j] = 29;
                else in[j] = 0;
                res[j] = 0;
            }
            for (int x = 0; x < d; x++) {
                for (int y = 0; y < d; y++) res[x] += mat[x][y] * in[y];
            }
            for (int j = 0; j < d; j++) {
                res[j] %= 30;
                if (res[j] < 0) res[j] += 30;
            }
            for (int j = 0; j < d; j++) {
                if (res[j] == 0) enc[i + j] = '?';
                else if (res[j] <= 26) enc[i + j] = 'A' + res[j] - 1;
                else if (res[j] == 27) enc[i + j] = ' ';
                else if (res[j] == 28) enc[i + j] = ',';
                else if (res[j] == 29) enc[i + j] = '.';
            }
        }
        printf("'%s'\n", enc);
        memset(s, '\0', 128);
        memset(enc, '\0', 128);
    }
    return 0;
}