#include <stdio.h>
#include <string.h>

/*
문제 : 10만자 이하의 문자열이 주어질 때, 이 문자의 모든 접두사를 정렬한 것의 길이를 정렬된 순서대로 출력한다.

해결 방법 : 정렬하더라도 길이 순서대로가 되므로 길이까지의 수를 오름차순으로 출력하면 된다.

주요 알고리즘 : 구현, 애드 혹?
*/

char s[103000];

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        printf("%d\n", i);
    }
    return 0;
}