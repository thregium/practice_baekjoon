#include <stdio.h>

/*
문제 : 자연수 N(N <= 100000)이 주어질 때, 이 수의 모든 자릿수를 더하는 것을 반복하여 한 자리 수가 될 때의 값을 구한다.

해결 방법 : 10 % 9 == 1이기 때문에 9로 나눈 나머지는 0일 때를 제외하면 한 자리 수가 되었을 때의 값이 된다. (증명 생략)
0일 때에는 답이 9가 된다.

주요 알고리즘 : 수학

출처 : NZPC 2005 D번
*/

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        if (n % 9) printf("%d\n", n % 9);
        else printf("9\n");
    }
    return 0;
}