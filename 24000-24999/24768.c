#include <stdio.h>

/*
문제 : 두 음이 아닌 정수 X, Y(X, Y <= 1000)가 주어질 때, X + Y가 13인지 확인하고 아니라면
X와 Y를 비교한 결과를 출력한다. 이를 X와 Y가 모두 0일 때 까지 반복한다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현

출처 : VTH 2014 D번
*/

int main(void) {
    int x, y;
    while (1) {
        scanf("%d %d", &x, &y);
        if (x + y == 0) break;
        else if (x + y == 13) printf("Never speak again.\n");
        else if (x == y) printf("Undecided.\n");
        else if (x < y) printf("Left beehind.\n");
        else printf("To the convention.\n");
    }
    return 0;
}