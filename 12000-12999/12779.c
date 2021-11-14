#include <stdio.h>

/*
문제 : 음이 아닌 정수로 된 구간 (a, b](a < b <= 2^60)에서 약수가 홀수개인 수의 비율을 기약분수로 구한다.

해결 방법 : 약수가 홀수개인 수는 제곱수이다. 따라서, b 이하의 제곱수 개수를 구하고, a 이하의 제곱수 개수를 구한 다음
둘을 빼문 그러한 수의 개수이다. 해당 범위에서 전체 수는 b - a이므로 이가 비율이다. 이 둘 사이 유클리드 호제법을
사용하여 기약분수로 만든 다음 출력하면 된다. 단, 0인 경우는 0으로 출력한다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법, 파라메트릭

출처 : 인하대 2016 B번
*/

long long getroot(long long n) {
    long long l = 0, h = (1LL << 29) * 3, m;
    while (l < h) {
        m = ((l + h + 1) >> 1);
        if (m * m <= n) l = m;
        else h = m - 1;
    }
    return l;
}

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    long long s, e, rt, g;
    scanf("%lld %lld", &s, &e);
    rt = getroot(e) - getroot(s);
    if (rt == 0) {
        printf("0");
        return 0;
    }
    g = gcd(e - s, rt);
    printf("%lld/%lld", rt / g, (e - s) / g);
    if (e > (1LL << 58)) return 1;
    return 0;
}