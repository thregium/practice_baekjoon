#include <stdio.h>
#define INF 12345678987654321

/*
문제 : 세 변의 길이가 A, B, C(A, B, C <= 100000)인 직육면체가 있을 때, 이 직육면체의 한 꼭짓점에서 반대쪽 꼭짓점까지
직육면체의 표면을 따라 이동할 때의 최단거리의 제곱을 구한다.

해결 방법 : 연속한 두 면을 직선으로 이동하는 것이 최선이다. 이러한 방법은 방향에 따라 3가지이고,
각각 A^2 + (B + C)^2, B^2 + (A + C)^2, C^2 + (A + B)^2의 거리이다. 이들 중 가장 짧은 것을 선택하면 된다.

주요 알고리즘 : 기하학

출처 : GA4 1번
*/

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long t, a, b, c, r;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        r = INF;
        r = small(r, a * a + (b + c) * (b + c));
        r = small(r, b * b + (a + c) * (a + c));
        r = small(r, c * c + (a + b) * (a + b));
        printf("%lld\n", r);
    }
    return 0;
}
