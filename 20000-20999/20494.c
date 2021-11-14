#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명의 사람과 셰프가 있을 때, 각 사람이 먹을 초밥의 목록이 주어지면 셰프가 만들어야 하는 초밥의 수를 구한다.

해결 방법 : 각 사람이 먹을 초밥을 모두 만들어야 하므로 목록의 길이 합과 같다!

주요 알고리즘 : 애드 혹

출처 : 선린 4회예 C번
*/

char s[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        r += strlen(s);
    }
    printf("%d", r);
    return 0;
}
