#include <stdio.h>

/*
문제 : 삼각형의 세 변의 길이(<= 1000)가 주어질 때, 직각삼각형인지 정삼각형인지 둘다 아닌지 구한다.

해결 방법 : 정삼각형인지는 세 변의 길이가 모두 같은지 확인하면 되고 직각삼각형인지는 피타고라스의 정리를 이용해
두 변의 길이의 제곱의 합이 나머지 한 변의 길이의 제곱과 같은 경우가 있는지 확인하면 된다.

주요 알고리즘 : 기하학, 피타고라스 정리, 구현

출처 : ILOCAMP 2010 B4-2번
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && a == c) printf("2");
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) printf("1");
    else printf("0");
    return 0;
}