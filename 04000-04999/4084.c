#include <stdio.h>
#include <math.h>

/*
문제 : 수 4개를 인접한 수의 차로 바꾸는 작업을 반복할 때, 몇 회 반복해야 모든 수가 같아지는지 구한다.
단, 모든 수는 log(N) * 3회 안에 같아진다는 것이 증명 가능하다.

해결 방법 : 매우 빠른 시간 내로 같아지는 것이 확인되었기 때문에 직접 시뮬레이션을 통해 해결하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 수학

출처 : SEUSA 2011 D번
*/

int main(void) {
    long long a, b, c, d, t = 0, z;
    while (1) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        t = 0;
        while (!(a == b && a == c && a == d)) {
            z = llabs(a - d);
            a = llabs(a - b);
            b = llabs(b - c);
            c = llabs(c - d);
            d = z;
            t++;
        }
        printf("%lld\n", t);
    }
    return 0;
}