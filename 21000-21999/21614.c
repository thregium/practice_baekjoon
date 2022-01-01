#include <stdio.h>

/*
문제 : 주어진 코드를 해석하여 이동 방향과 거리를 출력한다.

해결 방법 : 앞의 2자리로 이동 방향을 구하고 뒤의 3자리로 거리를 구하면 된다.

주요 알고리즘 : 수학

출처 : CCC 2021J 3번
*/

int main(void) {
    int n, l = -1;
    while (1) {
        scanf("%d", &n);
        if (n == 99999) break;
        if (n < 1000) printf("%s %03d\n", l == 1 ? "left" : "right", n);
        else if ((n / 1000) & 1) printf("left %03d\n", n % 1000);
        else printf("right %03d\n", n % 1000);
        l = ((n / 1000) & 1);
    }
    return 0;
}