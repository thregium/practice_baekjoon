#include <stdio.h>
#include <string.h>

/*
문제 : "고무오리 디버깅 끝"이 나오기 전까지 "문제"가 나오면 문제의 수를 1 늘리고, "고무오리"가 나오면 문제가 있다면
수를 1 줄이고, 없는 경우 수를 2 늘린다. 마지막에 문제의 개수가 0개인지 확인한다.

해결 방법 : 문제의 개수를 변수로 하는 값을 갖고 있으면 된다. 문자 확인은 strcmp() 함수를 이용한다.

주요 알고리즘 : 구현

출처 : 충남대 4회 A번
*/

char s[64];

int main(void) {
    int cnt = 0;
    while (1) {
        fgets(s, 48, stdin);
        //if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] == '\0';
        if (!strcmp(s, "문제\n")) cnt++;
        else if (!strcmp(s, "고무오리\n")) {
            if (cnt == 0) cnt += 2;
            else cnt--;
        }
        else if (!strcmp(s, "고무오리 디버깅 끝\n")) break;
    }
    if (cnt) printf("힝구\n");
    else printf("고무오리야 사랑해\n");
    return 0;
}