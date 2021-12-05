#include <stdio.h>

/*
문제 : X * Y(X, Y <= 10^9, 자연수) 크기의 타일에서 대각선이 지나는 타일의 개수를 구한다.

해결 방법 : 직사각형을 타일의 꼭짓점을 지나는 최소 단위로 분해한다. 이 값은 X와 Y에서 각각 최대공약수를 나눈 크기이다.
이 크기에서 대각선이 지나는 타일의 개수는 왼쪽 아래에서 오른쪽 위 까지의 경로의 길이와 같고, 이는 X + Y - 1이다.
이것이 최대공약수 번 반복되므로 해당 수에 최대공약수를 곱한 것이 답이 된다.

주요 알고리즘 : 수학, 유클리드 호제법
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", gcd(x, y) * (x / gcd(x, y) + y / gcd(x, y) - 1));
    return 0;
}