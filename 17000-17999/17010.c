#include <stdio.h>

/*
문제 : 문자와 반복 횟수가 주어질 때, 그 문자를 해당 횟수만큼 반복한다.

해결 방법 : 문제에 쓰인대로 구현한다.

주요 알고리즘 : 구현

출처 : CCC 2019J 2번
*/

int main(void) {
    int l, n;
    char c;
    scanf("%d", &l);
    for (int tt = 0; tt < l; tt++) {
        scanf("%d %c", &n, &c);
        for (int i = 0; i < n; i++) {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}