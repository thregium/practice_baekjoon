#include <stdio.h>

/*
문제 : 네 수가 주어질 때, 네 수를 돌려가며 나올 수 있는 분수의 합 가운데 몇 번 돌렸을 때가 가장 큰지 구한다.

해결 방법 : 각 수를 네 수의 곱을 분모로 하는 분수로 통분한 다음, 분자의 값을 비교해 가장 큰 것을 고르면 된다.

주요 알고리즘 : 수학

출처 : COCI 10/11#3 1번
*/

int main(void) {
    int a, b, c, d, best = 0, res = -1;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a * a * b * d + a * b * b * c > best) {
        best = a * a * b * d + a * b * b * c;
        res = 0;
    }
    if (a * b * c * c + a * a * c * d > best) {
        best = a * b * c * c + a * a * c * d;
        res = 1;
    }
    if (a * c * d * d + b * c * c * d > best) {
        best = a * c * d * d + b * c * c * d;
        res = 2;
    }
    if (b * b * c * d + a * b * d * d > best) {
        best = b * b * c * d + a * b * d * d;
        res = 3;
    }
    printf("%d", res);
    return 0;
}