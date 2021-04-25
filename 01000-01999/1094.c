#include <stdio.h>

/*
문제 : 2^n 길이의 막대를 이어붙여서 x 길이의 막대를 만들 때 필요한 최소한의 막대 수를 출력한다.

해결 방법 : x를 이진수로 나타낸 뒤 1의 갯수를 세면 이것이 필요한 최소한의 막대 수이다.

주요 알고리즘 : 수학, 비트마스킹
*/

int main(void) {
    int x, r = 0;
    scanf("%d", &x);
    for(int i = x; i; i >>= 1) r += i % 2;
    printf("%d", r);
    return 0;
}