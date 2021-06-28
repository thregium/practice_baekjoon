#include <stdio.h>

/*
문제 : 주어진 정수들 중 양수의 개수를 구한다.

해결 방법 : EOF가 될 때 까지 수들을 입력받으며 양수의 개수를 센 후 개수를 출력하면 된다.

주요 알고리즘 : 구현

출처 : 한양대E 2017B A번
*/

int main(void) {
    int r = 0, x;
    while (scanf("%d", &x) != EOF) {
        if (x > 0) r++;
    }
    printf("%d", r);
    return 0;
}