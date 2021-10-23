#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 대문자로 이루어진 문자열이 주어질 때, 순서를 유지하는 "HONI" 부분 수열의 최대 개수를 구한다.

해결 방법 : 앞에서부터 H, O, N, I를 반복하며 찾으면 된다. 처음 나오는 것을 추가하는 것이 무조건 이득이다.
문자열이 끝나면 찾은 HONI의 개수를 출력한다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : COCI 18/19#3 1번
*/

char s[103000];
char* honi = "HONI";

int main(void) {
    int p = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == honi[p & 3]) p++;
    }
    printf("%d", p >> 2);
    return 0;
}