#include <stdio.h>

/*
문제 : 두 자연수 A, B(A <= B <= 10^9)가 주어질 때, A, B, C의 평균값과 중앙값을 같게 만드는 정수 C 가운데 가장 작은 것을 구한다.

해결 방법 : C가 A, B보다 작은 경우 가장 작아진다. 이 값은 C, A, B 순으로 등차수열을 이룰 때의 C이고, 계산하면 A * 2 - B이다.

주요 알고리즘 : 수학, 사칙연산

출처 : Latin 2010 PA번
*/

int main(void) {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        printf("%d\n", a * 2 - b);
    }
    return 0;
}