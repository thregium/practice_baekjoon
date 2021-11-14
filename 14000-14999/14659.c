#include <stdio.h>

/*
문제 : N(N <= 30000)개의 서로 다른 자연수가 주어질 때, 해당 수의 오른쪽에 있는 수 가운데 해당 수보다 큰 수 또는
수열의 끝 까지의 거리가 가장 긴 것의 거리를 구한다.

해결 방법 : 스택을 이용해 스택 안에 있는 수들이 내림차순으로 들어있도록 한다. 스택에서 빠질 때의 수를
원래 수의 위치와 비교해 거리를 재고 그 값들 가운데 가장 큰 것을 고르면 된다. 모든 수를 확인한 다음
다시 스택에서 모든 수를 빼야 함에 유의한다.

주요 알고리즘 : 자료 구조, 스택

출처 : 선린 1회 J번
*/

int h[32768], stack[32768];
int top = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        while (top > 0 && h[i] >= h[stack[top - 1]]) {
            r = big(r, i - stack[--top] - 1);
        }
        stack[top++] = i;
    }
    while (top > 0) {
        r = big(r, n - stack[--top] - 1);
    }
    printf("%d", r);
    return 0;
}