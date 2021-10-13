#include <stdio.h>

/*
문제 : 1이 1개, 2가 2개, 3이 3개... 식으로 나오는 수열의 A번째부터 B(A, B <= 1000)번째 까지의 수를 구한다.

해결 방법 : 1000번째까지의 모든 수들을 미리 구한 다음, 그를 이용해 A번째부터 B번째까지의 합을 구해서 출력하면 된다.

주요 알고리즘 : 구현, 수학

출처 : CHCI 2008RJ 1번
*/

int arr[2048];

int main(void) {
    int a, b, p = 1, r = 0;
    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j < i; j++) {
            arr[p++] = i;
        }
    }
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        r += arr[i];
    }
    printf("%d", r);
    return 0;
}