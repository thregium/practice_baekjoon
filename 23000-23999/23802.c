#include <stdio.h>

/*
문제 : 자연수 N(N <= 100)이 주어질 때, 원래 크기의 N배로 뒤집힌 ㄱ자로 @를 출력한다.

해결 방법 : 위쪽 줄을 N * (N * 5) 크기로 @를 출력하고 그 아래로 (N * 4) * N 크기로 @를 출력하면 된다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n * 4; i++) {
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    return 0;
}