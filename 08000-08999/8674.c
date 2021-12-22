#include <stdio.h>

/*
문제 : A * B(A, B <= 2^32) 크기의 격자판을 가로선 또는 세로선으로 최대한 균등하게 자를 때 잘라진 두 격자판의
격자 수의 차이를 구한다.

해결 방법 : 만일 A 또는 B가 짝수라면 완전히 절반으로 자를 수 있으므로 답은 0이다. 둘다 홀수인 경우에는
한 줄만큼에 차이가 나게 되는데, 따라서 A와 B 중 더 짧은 쪽 변으로 자르면 되므로 답은 A 또는 B 중 더 작은 수이다.

주요 알고리즘 : 수학

출처 : ILOCAMP 2011B 4-4번
*/

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if ((a & 1) && (b & 1)) printf("%lld", a < b ? a : b);
    else printf("0");
    return 0;
}