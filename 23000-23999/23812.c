#include <stdio.h>

/*
문제 : @로 이루어진 'ㅒ'자 모양을 N(N <= 100)배 한 형태를 출력한다.

해결 방법 : 가로선과 세로선 부분을 나누어 출력하면 된다. 가로선은 @를 한 줄에 N * 5번씩 출력하고,
세로선은 한 줄에 @를 N번, 공백을 N * 3번, @를 N번씩 차례로 출력하면 된다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int h = 0; h < 3; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("@");
            for (int j = 0; j < n * 3; j++) printf(" ");
            for (int j = 0; j < n; j++) printf("@");
            printf("\n");
        }
        if (h == 2) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n * 5; j++) printf("@");
            printf("\n");
        }
    }
    return 0;
}