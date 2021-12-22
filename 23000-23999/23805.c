#include <stdio.h>

/*
문제 : @로 이루어진 반시계방향으로 90도 돌아간 ㄹ 형태를 N(N <= 100)배 한 모양을 출력한다.

해결 방법 : 각 줄마다 경우를 나눈다. 첫 번째 줄은 3칸 @ 후 1칸 공백, 다시 1칸 @이다. 2 ~ 4번째 줄은 @과 공백이 교대로 나온다.
마지막 줄은 @ 1칸 후 1칸 공백, 다시 3칸 @이다. 이를 N * N배하여 반복하면 원하는 모양을 출력 가능하다.

주요 알고리즘 : 구현
*/

void printshape(int n, char c) {
    for (int i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printshape(n * 3, '@');
        printshape(n, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n * 3; i++) {
        printshape(n, '@');
        printshape(n, ' ');
        printshape(n, '@');
        printshape(n, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n, ' ');
        printshape(n * 3, '@');
        printf("\n");
    }
    return 0;
}