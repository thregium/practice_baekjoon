#include <stdio.h>

/*
문제 : 주어진 @로 이루어진 ㅁ자를 N(N <= 100)배한 모양을 출력한다.

해결 방법 : 위, 가운데, 아래로 각각 나누어 출력한다. 가운데 부분은 중앙 3 * N칸을 공백, 나머지를 @로 채우고,
나머지 부분은 전부 @로 N * 5칸을 채우면 된다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < n; j++) printf("@");
        for (int j = 0; j < n * 3; j++) printf(" ");
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    return 0;
}