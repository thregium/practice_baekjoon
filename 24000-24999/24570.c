#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 문제에 주어진 형태의 문자열이 주어질 때, 문자열들을 출력에 필요한 형태로 변환하여 출력한다.

해결 방법 : 문제에 주어진대로 문자열을 변환한다. 파싱 기준점을 잘 잡고 문자열과 수를 잘 구분하여
출력하도록 한다.

주요 알고리즘 : 문자열, 파싱, 구현

출처 : CCC 2022 J3번
*/

char s[1024], inst[64];

int main(void) {
    int st = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) inst[i - st] = s[i];
        else {
            inst[i - st] = '\0';
            printf("%s %s %lld\n", inst, s[i] == '+' ? "tighten" : "loosen", strtoll(&s[i + 1], NULL, 10));
            i++;
            while (isdigit(s[i])) i++;
            st = i;
            i--;
        }
    }
    return 0;
}