#include <stdio.h>
#include <string.h>

/*
문제 : 10000자 이하의 소문자로 이루어진 문자열 s와 100자 이하의 소문자로 이루어진 문자열 p가 있을 때,
p를 이용해 복사-붙여넣기를 하여 s를 만들 수 있는 최소 시간을 구한다. p를 복사-붙여넣기 하는데는 1초가 걸리고,
한 글자를 입력하는 데도 1초가 걸린다. 복사-붙여넣기는 문자열 중간으로도 할 수 있다.
하지만 p 외의 문자열은 복사-붙여넣기 할 수 없고, 이미 있는 문자열을 지울 수도 없다.

해결 방법 : 문자열 s에서 p의 개수를 모두 찾아 p인 부분을 지워 나가며 해당하는 부분을 1초씩으로 계산한다.
남은 부분은 한 문자에 1초씩으로 계산해 두 값을 더하면 답이 된다.

주요 알고리즘 : 문자열

출처 : TOPC 2015 C번
*/

char s[10240], p[128];

int main(void) {
    int t, r = 0;
    char* x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %s", s, p);
        x = strstr(s, p);
        r = 0;
        while (x) {
            strcpy(x, x + strlen(p));
            x = strstr(s, p);
            r++;
        }
        r += strlen(s);
        printf("%d\n", r);
    }
    return 0;
}