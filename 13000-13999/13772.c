#include <stdio.h>

/*
문제 : 길이 250 이하의 알파벳 대문자와 공백으로 이루어진 문자열이 주어질 때, 이 문자열의 구멍 개수를 구한다.

해결 방법 : B에는 구멍이 2개, A, D, O, P, Q, R에는 구멍이 1개 있다. 따라서, 해당 문자들이 주어지면 구멍의 개수를 맞게 올리고,
나머지 문자들은 무시한 다음, 구멍의 개수를 출력하면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2016 B번
*/

char s[256];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 253, stdin);
        r = 0;
        for (int j = 0; s[j]; j++) {
            if (s[j] == 'B') r += 2;
            else if (s[j] == 'A' || s[j] == 'D' || s[j] == 'O' || s[j] == 'P' || s[j] == 'Q' || s[j] == 'R') r++;
        }
        printf("%d\n", r);
    }
    return 0;
}