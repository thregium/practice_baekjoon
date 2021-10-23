#include <stdio.h>

/*
문제 : N(N <= 99)병의 맥주를 출력한다. 문법에 맞게 출력해야 한다.

해결 방법 : 반복문을 통해 1병 이상일 때를 출력하고, 마지막에는 직접 출력한다. 1병일 때의 예외 처리에 주의한다.

주요 알고리즘 : 구현, 케이스 워크?

출처 : 선린 3회예 C번
*/

char s[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        sprintf(s, "%d %s", i, i > 1 ? "bottles" : "bottle");
        printf("%s of beer on the wall, %s of beer.\n", s, s);
        if (i == 1) sprintf(s, "%s", "no more bottles");
        else sprintf(s, "%d %s", i - 1, i > 2 ? "bottles" : "bottle");
        printf("Take one down and pass it around, %s of beer on the wall.\n\n", s);
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    printf("Go to the store and buy some more, %d %s of beer on the wall.", n, n > 1 ? "bottles" : "bottle");
    return 0;
}