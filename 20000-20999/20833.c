#include <stdio.h>

/*
문제 : 한 변의 길이가 1부터 N(N <= 100)까지인 큐브를 하나씩 만들기 위해 1 * 1 * 1 크기의 조각이 몇 개 필요한지 구한다.

해결 방법 : 크기 X에서 필요한 조각의 수는 X * X * X이다. 이를 반복문을 통해 1에서 N까지 반복하면 된다.

주요 알고리즘 : 수학

출처 : SwOI 2019Q 1번
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r += i * i * i;
    }
    printf("%d", r);
    return 0;
}