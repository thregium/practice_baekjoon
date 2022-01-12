#include <stdio.h>
#include <ctype.h>

/*
문제 : 1000을 'm', 100을 'c', 10을 'x', 1을 'i'로 나타내고, 2 이상 9 이하의 배수를 앞에 적는 방식으로
만들어진 수 표기법(mcxi 표기법)으로 적혀진 문자열이 주어지면, 그 합을 mcxi 표기법으로 나타내어 출력한다.

해결 방법 : 주어진 두 문자열을 수로 바꾼 다음, 합을 구한다. 이를 다시 mcxi 표기법으로 바꾸어 출력하면 된다.
문자열을 수로 바꿀 때에는 m, c, x, i가 올 때 그 앞 글자가 숫자인 지 확인하고 숫자면 그만큼 배수해서 곱하면 된다.
출력시에는 각 자리가 2 이상인지 확인하며 자릿수와 문자를 출력한다.

주요 알고리즘 : 문자열, 파싱

출처 : JDC 2005 C번
*/

char s1[16], s2[16], res[16];

int chartonum(char c) {
    if (c == 'm') return 1000;
    if (c == 'c') return 100;
    if (c == 'x') return 10;
    if (c == 'i') return 1;
    return 0;
}

int mcxitonum(char* s) {
    int r = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'm' || s[i] == 'c' || s[i] == 'x' || s[i] == 'i') {
            if (i == 0 || !isdigit(s[i - 1])) r += chartonum(s[i]);
            else r += chartonum(s[i]) * (s[i - 1] - '0');
        }
    }
    return r;
}

void printmcxi(int n) {
    if (n / 1000) {
        if (n / 1000 > 1) printf("%d", n / 1000);
        printf("m");
    }
    if (n / 100 % 10) {
        if (n / 100 % 10 > 1) printf("%d", n / 100 % 10);
        printf("c");
    }
    if (n / 10 % 10) {
        if (n / 10 % 10 > 1) printf("%d", n / 10 % 10);
        printf("x");
    }
    if (n % 10) {
        if (n % 10 > 1) printf("%d", n % 10);
        printf("i");
    }
    printf("\n");
}

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %s", s1, s2);
        r = mcxitonum(s1) + mcxitonum(s2);
        printmcxi(r);
    }
    return 0;
}