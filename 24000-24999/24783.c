#include <stdio.h>

/*
문제 : 세 자연수 A, B, C(A, B, C <= 10000)가 주어질 때,
A와 B에 사칙연산을 하여 C를 만들 수 있는 지 확인한다. 이를 N(N <= 1000)번 반복한다.

해결 방법 : A와 B로 만들 수 있는 모든 경우에 대해 C가 만들어지는 경우가 하나라도 있는 지 확인하면 된다.

주요 알고리즘 : 수학, 사칙연산, 케이스 워크

출처 : VTH 2016 A번
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a + b == c || a * b == c || a - b == c || b - a == c ||
            (a % b == 0 && a / b == c) || (b % a == 0 && b / a == c)) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}