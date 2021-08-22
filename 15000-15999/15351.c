#include <stdio.h>

/*
문제 : 길이 30 이하의 알파벳 대문자와 공백으로 이루어진 문자열이 주어질 때, 이 문자열의 점수를 구한다.
문자열의 점수는 공백을 제외한 각 문자들에 A는 1점, B는 2점 .. Z는 26점으로 점수를 매기고 모든 문자의 점수를 합한 것이다.
점수가 100점인 경우에는 점수 대신 PERFECT LIFE를 출력한다.

해결 방법 : 각 문자의 점수는 c - 'A' + 1로 구할 수 있다. 단, 이때 공백인 경우는 이를 계산하지 않고 넘어가야 한다.
이를 모든 문자에 대해 더해서 점수를 구한 후 100점이면 PERFECT LIFE를 출력하고, 그 외에는 점수를 출력하면 된다.

주요 알고리즘 : 구현, 문자열
*/

char s[48];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 40, stdin);
        r = 0;
        for (int j = 0; s[j]; j++) {
            if (s[j] == ' ' || s[j] == '\n') continue;
            r += s[j] - 'A' + 1;
        }
        if (r == 100) printf("PERFECT LIFE\n");
        else printf("%d\n", r);
    }
    return 0;
}