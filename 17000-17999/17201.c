#include <stdio.h>

/*
문제 : 자석 N(N <= 5)개의 연결이 극 형태로 주어질 때, 이 연결이 모두 붙을 수 있는지 구한다.

해결 방법 : 근처 극끼리 같은 극이라면 붙을 수 없다. 따라서, 인접한 두 극이 같은지만 확인해주면 된다.

주요 알고리즘 : 구현

출처 : 중앙대 2019N A번
*/

char s[16];

int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 1; i < 2 * n; i++) {
        if (s[i] == s[i - 1]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}