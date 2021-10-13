#include <stdio.h>
#include <string.h>

/*
문제 : 길이 100 이하의 문자열이 주어질 때, 이 문자열에서 "BUG"를 전부 없앤 문자열을 출력한다.
대소문자를 구별하고, "BUG"를 없앤 다음 생긴 "BUG"도 없애야 한다.

해결 방법 : "BUG"가 없을 때 까지 strstr를 통해 "BUG"의 위치를 찾고 strcpy와 strcat을 이용해 해당 "BUG"를
없애는 것을 반복하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : CERC 2007 PB번
*/

char s[2][128];

int main(void) {
    int i = 0, p = 0;
    char* c;
    while (fgets(s[0], 120, stdin)) {
        i = 0;
        while (strstr(s[0], "BUG")) {
            c = strstr(s[0], "BUG");
            *c = '\0';
            strcpy(s[1], s[0]);
            strcat(s[1], c + 3);
            strcpy(s[0], s[1]);
        }
        printf("%s", s[i]);
    }
    return 0;
}