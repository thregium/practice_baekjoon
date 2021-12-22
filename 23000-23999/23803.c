#include <stdio.h>

/*
문제 : 주어진 @로 이루어진 ㄴ자 모양을 N(N <= 100)배한 모양을 출력한다.

해결 방법 : 위쪽 부분(N * 4) * N 크기의 @ 직사각형과 아래쪽 부분 N * (N * 5) 크기의 @ 직사각형을 나누어 출력하면 된다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 4; i++) {
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    return 0;
}