#include <stdio.h>
#include <math.h>

/*
문제 : 원에 내접하는 사각형의 세 변이 주어질 때, 세 변의 길이 가운데 하나가 원의 지름과 같다면
그러한 사각형을 만들 수 있는지 구하고, 가능하다면 나머지 한 변의 길이를 출력한다.
불가능한 경우 -1을 출력한다.

해결 방법 : 원의 지름과 다른 한 점으로 이루어진 삼각형이 직각삼각형임과
대각선의 곱이 마주보는 두 변의 곱의 합과 같음을 이용한다.

주요 알고리즘 : 기하학, 수학

출처 : 충남대 3회 E번
*/

int main(void) {
    int a, b, c, d, p, q, r;
    double x;
    scanf("%d %d %d", &a, &b, &c);
    p = a;
    q = 2 * b * c;
    r = a * (c * c - a * a + b * b);
    d = q * q - 4 * p * r;
    if (d < 0) {
        printf("%d", -1);
        return 0;
    }
    x = (-q + sqrt(d)) / (2 * p);
    if (x < 0) {
        printf("%d", -1);
        return 0;
    }
    printf("%d", (int)(x + 0.000001));
}