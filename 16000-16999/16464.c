#include <stdio.h>

/*
문제 : 자연수 X(X <= 10^9)에 대해 2개 이상의 자연수의 연속합으로 표현 가능한지 여부를 구한다.

해결 방법 : 모든 홀수는 짝수개의 수의 합으로 표현 가능하고, 짝수들도 홀수로 나눌 수 있다면 그 수개만큼의
수의 합으로 표현 가능하다. 하지만 2의 거듭제곱 꼴인 경우 표현이 불가능하다.

주요 알고리즘 : 수학

출처 : 한양대 5회B F번 / 5회A G번
*/

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d", &x);
        if (x == (x & -x)) printf("GoHanGang\n");
        else printf("Gazua\n");
    }
    return 0;
}