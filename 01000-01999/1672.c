#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 DNA 문자열이 주어질 때, 이 문자열을 주어진 규칙에 따라 축약하면 남는 염기는 무엇인지 구한다.
(규칙 생략)

해결 방법 : 규칙에 맞게 끝쪽부터 문자열을 줄여나간다. 

주요 알고리즘 : 문자열, 구현, 케이스 워크
*/

char s[1048576];

int main(void) {
    int n, t;
    scanf("%d%s", &n, s);
    for (int i = n - 2; i >= 0; i--) {
        t = s[i] + s[i + 1];
        if (s[i] == s[i + 1]) continue;
        else if (t == 'A' + 'C') s[i] = 'A';
        else if (t == 'A' + 'G') s[i] = 'C';
        else if (t == 'A' + 'T') s[i] = 'G';
        else if (t == 'C' + 'G') s[i] = 'T';
        else if (t == 'C' + 'T') s[i] = 'G';
        else if (t == 'G' + 'T') s[i] = 'A';
        else return 1;
    }
    printf("%c", s[0]);
    return 0;
}