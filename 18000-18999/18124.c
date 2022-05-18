#include <stdio.h>

/*
문제 : 정사각형 형태의 종이를 최대 2가지 크기로 잘라서 같은 크기의 종이를 N(N < 2^32)개 만들기 위해
잘라야 하는 최소 횟수를 구한다.

해결 방법 : 재귀적인 방법을 통해 해결 가능하다. 자세한 식은 코드를 참고한다.

주요 알고리즘 : 수학, 재귀

출처 : 가톨릭대 1회D2 A번
*/

long long hard[4] = { 0, 1, 3, 3 };

long long getres(long long x) {
    if (x <= 3) return hard[x];
    else if ((x >> 1) & 1) return getres(x >> 1) * 2 + 1;
    else return getres(x >> 1) * 2;
}

int main(void) {
    long long n;
    scanf("%lld", &n);
    printf("%lld", getres(n - 1));
    return 0;
}