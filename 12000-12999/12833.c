#include <stdio.h>

/*
문제 : A XOR B를 C회 한 결과를 구한다.

해결 방법 : 어떠한 수에 같은 수로 XOR 연산을 2회 하면 원래대로 돌아온다. 따라서, C가 홀수인 경우에는 A XOR B를 출력하고,
짝수인 경우에는 A를 그대로 출력하면 된다.

주요 알고리즘 : 구현?
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c & 1) printf("%d", a ^ b);
    else printf("%d", a);
    return 0;
}