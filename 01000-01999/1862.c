#include <stdio.h>
#include <stdlib.h>

/*
문제 : 4를 표기하지 않는 표기법의 자연수 N(N <= 999999999)이 주어질 때, 십진법으로 나타낸 값을 구한다.

해결 방법 : 5 이상의 숫자를 1씩 내린 다음 strtoll 함수를 통해 9진법 수를 십진법으로 변환하여 출력하면 된다.

주요 알고리즘 : 수학, 정수론
*/

char s[16];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] >= '5') s[i]--;
    }
    printf("%lld", strtoll(s, NULL, 9));
    return 0;
}