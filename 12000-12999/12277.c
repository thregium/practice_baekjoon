#include <stdio.h>

char num[128], form[256];
char* suc[11] = { "", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple",
"octuple", "nonuple", "decuple" };
char* nums[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int nlen[128];

void printnum(int n, int c) {
    if (c > 1 && c <= 10) printf("%s ", suc[c]);
    if (c <= 10) printf("%s ", nums[n]);
    else {
        for (int i = 0; i < c; i++) {
            printf("%s ", nums[n]);
        }
    }
}

int main(void) {
    int t, n, last, cnt;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s %s", num, form);
        n = 1;
        for (int i = 0; form[i]; i++) {
            if (form[i] == '-') n++;
            else nlen[n] = nlen[n] * 10 + (form[i] - '0');
        }
        n++;
        for (int i = 1; i <= n; i++) nlen[i] += nlen[i - 1];

        printf("Case #%d: ", tt);
        for (int i = 1; i < n; i++) {
            last = (num[nlen[i - 1]] - '0');
            cnt = 1;
            for (int j = nlen[i - 1] + 1; j < nlen[i]; j++) {
                if (num[j] - '0' == last) cnt++;
                else {
                    printnum(last, cnt);
                    last = num[j] - '0';
                    cnt = 1;
                }
            }
            printnum(last, cnt);
        }
        printf("\n");

        for (int i = 0; i < 128; i++) nlen[i] = 0;
    }
    return 0;
}