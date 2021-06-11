#include <stdio.h>

/*
문제 : N개의 임의의 연속한 정수를 더할 때, 이 합이 홀수인지 짝수인지 알 수 없는지 구한다.

해결 방법 : 정수를 더하는 경우 이 합의 홀짝 여부는 더한 홀수의 개수에 따라 달라진다.
홀수를 홀수번 더한 경우 합은 홀수가 되고, 짝수번 더한 경우 합은 짝수가 된다.
N이 홀수인 경우에는 홀수부터 시작하는 경우와 짝수부터 시작하는 경우 홀수의 개수가 달라지므로 홀수인지 짝수인지 알 수 없게 된다.
짝수인 경우에는 4로 나누어 떨어지는 경우와 나누어 떨어지지 않는 경우로 나뉘는데,
4로 나누어 떨어지는 경우는 항상 홀수가 짝수번 나오므로 짝수이고, 나누어 떨어지지 않으면 항상 홀수가 홀수번 나오므로 홀수이다.

주요 알고리즘 : 수학, 정수론

출처 : NCNA 2019 D번
*/

int main(void) {
    long long n;
    scanf("%lld", &n);
    printf("%s", (n & 1) ? "Either" : (n & 2) ? "Odd" : "Even");
    return 0;
}