#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 1000자 이하의 문자열이 주어질 때, 대문자들을 복호화하여 출력한다. 암호화 방법은 카이사르 암호이며,
원문에는 "LIVE"와 "CHIPMUNKS"가 들어있다. 대문자 외에는 원문 그대로 출력한다.

해결 방법 : P값을 0부터 25까지 이동시켜가며 "CHIPMUNKS"와 "LIVE"가 모두 존재하는 경우를 찾아 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : NOIS 2007 3번
*/

char s[1024], ds[1024];

int main(void) {
    fgets(s, 1013, stdin);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; s[j]; j++) {
            if (isupper(s[j])) ds[j] = (s[j] - 'A' + i) % 26 + 'A';
            else ds[j] = s[j];
        }
        if (strstr(ds, "CHIPMUNKS") && strstr(ds, "LIVE")) {
            if (i == 0) return 2;
            printf("%s", ds);
            return 0;
        }
    }
    return 1;
}