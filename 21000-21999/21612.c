#include <stdio.h>

/*
문제 : 물의 끓는 점이 주어질 때 5 * B - 400 = P라는 공식을 통해 기압 P를 구하고 해수면 위인지 구한다.

해결 방법 : 공식에 끓는 점을 대입해 기압을 구한 뒤 끓는 점이 100보다 높은지 여부를 통해 해수면과 높이의 관계를 구하면 된다.

주요 알고리즘 : 수학, 구현

출처 : CCC 2021 J1번
*/

int main(void) {
    int b;
    scanf("%d", &b);
    printf("%d\n", b * 5 - 400);
    if (b > 100) printf("-1");
    else if (b == 100) printf("0");
    else printf("1");
    return 0;
}