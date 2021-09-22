#include <stdio.h>
#include <string.h>

/*
문제 : 길이 N(N <= 10^6)의 p, A, P로 이루어진 문자열이 주어질 때, 겹치지 않는 부분 문자열 "pPAp"를
최대 몇 개 만들 수 있는지 구한다.

해결 방법 : 문자열의 왼쪽에서부터 문자열 "pPAp"를 찾는다. 문자열을 찾으면 4칸 뒤부터 다시 다음 문자열을 찾아본다.
이를 반복하면 가장 왼쪽에 있는 가능한 pPAp를 찾을 수 있고, 따라서 가장 많은 pPAp를 찾을 수 있다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : Postech 2018 H번
*/

char s[1048576];

int main(void) {
    int n, r = -1;
    char* p;
    scanf("%d", &n);
    scanf("%s", s);
    p = s - 4;
    while (p != NULL) {
        p = strstr(p + 4, "pPAp");
        r++;
    }
    printf("%d", r);
    return 0;
}