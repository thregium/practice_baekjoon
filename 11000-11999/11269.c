#include <stdio.h>

/*
문제 : 길이가 300 이하고 3의 배수이며 대문자로만 이루어진 문자열이 주어질 때, 이 문자열을 PERPERPER...PER로 바꾸려고 한다.
이 문자열을 하루에 한 글자씩 바꿀 수 있다면 최소 몇 일이 걸리는지 구한다.

해결 방법 : 각 문자의 번호를 3으로 나눈 결과별로 어떤 문자가 나와야 할지 확인한다. 0인 경우 P, 1인 경우 E, 2인 경우 R이다.
만약 나와야 할 문자가 나왔다면 넘어가고, 그렇지 않다면 바꿔야 하므로 1일을 추가한다. 마지막에 나온 날수가 답이 된다.

주요 알고리즘 : 구현, 문자열

출처 : NCPC 2015 C번
*/

char s[384];

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (i % 3 == 0 && s[i] != 'P') r++;
        else if (i % 3 == 1 && s[i] != 'E') r++;
        else if (i % 3 == 2 && s[i] != 'R') r++;
    }
    printf("%d", r);
    return 0;
}