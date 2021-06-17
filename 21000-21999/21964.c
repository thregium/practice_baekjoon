#include <stdio.h>

/*
문제 : 주어진 길이 N(N <= 100000)의 문자열에서 마지막 5 문자를 출력한다.

해결 방법 : 마지막 문자 - 5번째 문자부터 마지막 문자까지 반복하면 된다.

주요 알고리즘 : 문자열

출처 : 선린 5회예 A번
*/

char s[103000];

int main(void) {
    int n;
    scanf("%d%s", &n, s);
    for (int i = n - 5; i < n; i++) {
        printf("%c", s[i]);
    }
    return 0;
}