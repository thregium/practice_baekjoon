#include <stdio.h>
#include <string.h>

/*
문제 : 길이 200000 이하의 소문자로 이루어진 세 문자열이 주어질 때, 마지막 문자열이 앞의 두 문자열의 부분 문자열인지 구한다.

해결 방법 : strstr()함수는 O(A + B)이기 때문에 strstr 함수를 이용하면 시간 내로 풀 수 있다.

주요 알고리즘 : 문자열
*/

char a[204800], b[204800], c[204800];

int main(void) {
    scanf("%s%s%s", a, b, c);
    if (strstr(a, c) && strstr(b, c)) printf("YES");
    else printf("NO");
    return 0;
}