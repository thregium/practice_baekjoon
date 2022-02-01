#include <stdio.h>
#include <stdlib.h>
#define INF 12345678987

/*
문제 : 2가지 추의 무게(<= 50000, 자연수)와 무게를 잴 물건의 무게(<= 50000, 자연수)가 있다.
이때, 이 물건의 무게를 재기 위해 필요한 두 추의 개수를 구한다. 잴 수 있는 경우가 여럿이므로
추의 개수 합이 가장 적은 것, 그 중에서 가장 무게 합이 적은 것을 선택한다.

해결 방법 : 한쪽에 추 A를 0개부터 50000개까지 차례로 놓아보며 가능한 경우 가운데
가장 우선되는 경우를 찾아나가면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : Ehime 2004 A번
*/

void upd(long long* ra, long long* rb, long long x, long long y, long long a, long long b) {
    if (x + y < *ra + *rb) {
        *ra = x;
        *rb = y;
    }
    else if (x + y == *ra + *rb && a * x + b * y < *ra * a + *rb * b) {
        *ra = x;
        *rb = y;
    }
}

int main(void) {
    long long a, b, d, ra, rb;
    while (1) {
        scanf("%lld %lld %lld", &a, &b, &d);
        if (a == 0) break;
        ra = INF, rb = INF;
        for (int i = 0; i <= 103000; i++) {
            if ((d - (a * i)) % b == 0) {
                upd(&ra, &rb, i, llabs((d - (a * i)) / b), a, b);
            }
            if ((d + (a * i)) % b == 0) {
                upd(&ra, &rb, i, (d + (a * i)) / b, a, b);
            }
        }
        printf("%lld %lld\n", ra, rb);
    }
    return 0;
}