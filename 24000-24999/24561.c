#include <stdio.h>

/*
문제 : X + Y = Z 또는 X * Y = Z로 주어진 식을 만족시키는 X, Y, Z 중 2개의 값에 대한
진 접두부 교환이 유일하게 존재한다. 세 자연수 X, Y, Z(X, Y, Z < 2^31)가 주어질 때,
그러한 교환을 출력한다. 진 접두부 교환은 두 문자열의 앞에서 1자 이상의 전체 문자열이 아닌
접두부를 서로 교환하는 것이다.

해결 방법 : (X, Y), (X, Z), (Y, Z)의 쌍들에 대해 앞에서부터 가능한 모든 경우를 바꾸어 보며
답이 나오는 경우 그 답을 출력한다. 나머지 연산과 10의 배수를 이용하면 문자열을 이용하지 않고
순서를 바꾼 경우의 값을 찾을 수 있다.

주요 알고리즘 : 수학, 브루트 포스

출처 : ECNA 2021 G번
*/

int main(void) {
    long long x, y, z, r = 1;
    char o;
    scanf("%lld %c %lld = %lld", &x, &o, &y, &z);
    for (long long i = 10; i <= x; i *= 10) {
        for (long long j = 10; j <= z; j *= 10) {
            if (o == '+') {
                if ((x % i + z / j * i) + y == (z % j + x / i * j)) {
                    printf("%lld + %lld = %lld", x % i + z / j * i, y, z % j + x / i * j);
                    r = 0;
                }
            }
            else {
                if ((x % i + z / j * i) * y == (z % j + x / i * j)) {
                    printf("%lld * %lld = %lld", x % i + z / j * i, y, z % j + x / i * j);
                    r = 0;
                }
            }
            if (!r) break;
        }
        if (!r) break;
    }
    for (long long i = 10; i <= x; i *= 10) {
        for (long long j = 10; j <= y; j *= 10) {
            if (o == '+') {
                if ((x % i + y / j * i) + (y % j + x / i * j) == z) {
                    printf("%lld + %lld = %lld", x % i + y / j * i, y % j + x / i * j, z);
                    r = 0;
                }
            }
            else {
                if ((x % i + y / j * i) * (y % j + x / i * j) == z) {
                    printf("%lld * %lld = %lld", x % i + y / j * i, y % j + x / i * j, z);
                    r = 0;
                }
            }
            if (!r) break;
        }
        if (!r) break;
    }
    for (long long i = 10; i <= y; i *= 10) {
        for (long long j = 10; j <= z; j *= 10) {
            if (o == '+') {
                if (x + (y % i + z / j * i) == (z % j + y / i * j)) {
                    printf("%lld + %lld = %lld", x, y % i + z / j * i, z % j + y / i * j);
                    r = 0;
                }
            }
            else {
                if (x * (y % i + z / j * i) == (z % j + y / i * j)) {
                    printf("%lld * %lld = %lld", x, y % i + z / j * i, z % j + y / i * j);
                    r = 0;
                }
            }
            if (!r) break;
        }
        if (!r) break;
    }
    return r;
}