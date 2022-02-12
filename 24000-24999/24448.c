#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 200000)번의 주어지는 이름의 책을 쌓거나 책을 읽는 행동이 주어질 때,
읽은 책들의 이름을 순서대로 출력한다. 책을 읽는 경우 "READ"라는 문자열이, 책을 쌓는 경우에는
책의 이름인 10자 이하의 소문자로 이루어진 문자열이 주어진다.
"READ"가 나오는 경우 책이 하나 이상 쌓여있는 경우만 주어진다.

해결 방법 : 스택을 이용하여 쌓은 책들을 순서대로 저장하고, "READ"가 들어올 때 마다
스택의 맨 위에서 하나씩 책을 꺼내 그 이름을 출력하면 된다.

주요 알고리즘 : 자료 구조, 스택

출처 : JOI 2022예2 1번
*/

char st[204800][12], buff[12];

int main(void) {
    int q, t = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "READ")) printf("%s\n", st[--t]);
        else strcpy(st[t++], buff);
    }
    return 0;
}