#include <stdio.h>
#include <string.h>

/*
문제 : 1000자 이하의 he...y 형태의(e가 임의의 횟수만큼 반복) 문자열이 주어질 때, e의 개수를 2배로 늘려 출력한다.

해결 방법 : e의 개수는 문자열의 길이를 l이라고 하면 (l - 2) * 2회가 되면 된다. h를 출력한 후 e를 해당 횟수 출력하고 다시 y를 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : BAPC 2019P G번
*/

char s[1024];

int main(void) {
    scanf("%s", s);
    int l = strlen(s);
    printf("h");
    for (int i = 0; i < (l - 2) * 2; i++) printf("e");
    printf("y");
    return 0;
}