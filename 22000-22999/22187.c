#include <stdio.h>

/*
문제 : 200자 이하의 소문자와 괄호로 이루어진 문자열이 주어질 때, 이 문자열의 괄호 안 문자들을
뒤집은 문자열을 구한다. 괄호는 출력하지 않는다.
괄호의 깊이는 최대 1단계이고 모든 괄호는 올바르게 짝지어져 있다.

해결 방법 : 문자열, 파싱, 구현

주요 알고리즘 : 문자열, 파싱, 구현

출처 : RCC 2011Q1 A번
*/

char s[256], tok[256];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int p = 0, l = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            p++;
            tok[l] = '\0';
            printf("%s", tok);
            l = 0;
            continue;
        }
        else if (s[i] == ')') {
            p--;
            tok[l] = '\0';
            for (int j = 0, k = l - 1; j < k; j++, k--) swap(&tok[j], &tok[k]);
            printf("%s", tok);
            l = 0;
            continue;
        }
        if (p > 1 || p < 0) return 1;
        tok[l++] = s[i];
        if (!s[i + 1]) {
            tok[l] = '\0';
            printf("%s", tok);
        }
    }
    return 0;
}