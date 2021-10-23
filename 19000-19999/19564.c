#include <stdio.h>

/*
문제 : 길이 100000 이하의 소문자로 이루어진 문자열이 주어질 때, 문자 제거만으로 이 문자열을 표시하기 위해 필요한
"abcdefg...xyz" 문자열의 최소 개수를 구한다.

해결 방법 : a부터 z까지의 문자를 확인하는 문자와 같을 때 까지 반복해서 찾는다. 이를 반복하다가
모든 문자열을 확인했을 때 까지 사용한 문자열의 개수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : 폴리매스 1회 B번
*/

char s[103000];

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        while (r % 26 + 'a' != s[i]) r++;
        r++;
    }
    printf("%d", (r - 1) / 26 + 1);
    return 0;
}