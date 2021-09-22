#include <stdio.h>

/*
문제 : 100자 이하의 대문자로 이루어진 문자열이 주어질 때, 원판에 쓰인 대문자들을 이용해 문자열을 표현하기 위해
최소로 돌려야 하는 판의 칸 수를 구한다.

해결 방법 : 판을 어떻게 돌리더라도 문자를 입력할 때의 판의 위치는 항상 동일하다.
따라서, 판을 가능한 적게 돌리는 방향으로 돌리는 것이 좋고, 왼쪽과 오른쪽으로 각각 돌려본 다음
더 적게 움직이는 쪽을 선택하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구현

출처 : 한양대E 2019Z A번
*/

char s[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int r = 0, lr, rr;
    char l = 'A';
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        lr = (s[i] - l + 26) % 26;
        rr = (l - s[i] + 26) % 26;
        r += small(lr, rr);
        l = s[i];
    }
    printf("%d", r);
    return 0;
}