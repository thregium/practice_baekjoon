#include <stdio.h>

/*
문제 : A / B(A, B <= 100000)의 소수점 아래 N(N <= 10^6)번째 자리를 구한다.

해결 방법 : 우선 A를 B로 나눈 나머지를 취해 소수점 아래 부분만 남긴다. 그 다음으로는 앞의 N - 1자리동안
A * 10을 하여 자릿수를 한칸 앞으로옮긴 후 B로 나눈 나머지를 남기는 방식으로 수가 너무 커지지 않게 한다.
마지막 자리에서는 A * 10에서 B로 나눈 나머지를 구하면 해당 자릿수의 값이 된다.

주요 알고리즘 : 수학, 임의 정밀도
*/

int main(void) {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    //printf("%d.", a / b);
    a %= b;
    for (int i = 1; i < n; i++) {
        a *= 10;
        //printf("%d", a / b);
        a %= b;
    }
    printf("%d", a * 10 / b);
    return 0;
}