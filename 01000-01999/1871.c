#include <stdio.h>
#include <stdlib.h>

/*
문제 : 대문자 3 글자-숫자 4자로 이루어진 번호판이 있을 때, 이 번호판의 알파벳 부분(26진법으로 계산)과 숫자 부분의
차이가 100 이하인지 구한다.

해결 방법 : 알파벳 부분은 세 글자를 각각 'A'와 빼고 26의 거듭제곱을 곱해서 더하는 방식으로 26진법을 계산하고,
숫자 부분은 strtoll()함수를 이용해 해결한다.(4칸 뒤부터 시작해야 한다.). 그 다음 두 수의 차의 절댓값을 계산하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : Alberta 2012 A번
*/

char s[16];

int main(void) {
    int n, l, r;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%s", s);
        l = (s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A');
        r = strtoll(s + 4, NULL, 10);
        if (abs(l - r) <= 100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}