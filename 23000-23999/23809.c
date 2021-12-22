#include <stdio.h>

/*
문제 : @로 이루어진 'K'자를 N(N <= 100)배한 형태를 출력한다.

해결 방법 : 각 줄별로 각 칸에 맞는 글자들을 반복문을 통해 출력하면 된다.

주요 알고리즘 : 구현
*/

void printshape(int n, char c) {
    for (int i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 3, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 2, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n * 3, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 2, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 3, ' ');
        printshape(n, '@');
        printf("\n");
    }
    return 0;
}