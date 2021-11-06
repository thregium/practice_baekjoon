#include <stdio.h>
#include <string.h>

/*
문제 : N(2 <= N <= 20)개의 대문자로 이루어진 길이 12 이하의 문자열이 주어질 때, 이 문자열이 증가하는 순서인지
감소하는 순서인지 둘 다 아닌지 구한다. 문자열은 중복되지 않는다.

해결 방법 : 문자열을 전부 입력받은 다음 strcmp함수를 이용해 (2번째 이후의) 각 문자열이 이전 문자열에 비해
큰지 작은지 확인한다. 더 크다면(사전순으로 뒤) 감소하는 것이 아니고, 더 작다면(사전순으로 앞) 증가하는 것이 아니다.
결과에서 더 큰지 더 작은지 둘 다 아닌지 구하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : MidC 2015 F번
*/

char s[32][32];

int main(void) {
    int n, ic = 1, dc = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i < n; i++) {
        if (strcmp(s[i], s[i - 1]) < 0) ic = 0;
        else if (strcmp(s[i], s[i - 1]) > 0) dc = 0;
        else return 1;
    }
    if (dc && ic) return 2;
    if (ic) printf("INCREASING");
    else if (dc) printf("DECREASING");
    else printf("NEITHER");
    return 0;
}