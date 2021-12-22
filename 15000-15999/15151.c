#include <stdio.h>

/*
문제 : K(K <= 365)일동안 글을 써서 첫 책을 만들 수 있고, 그 이후로는 마지막으로 쓴 책을 쓰는데 걸리는 시간 * 2일동안
글을 써서 다음 책을 쓸 수 있다고 한다. 이때, D(D <= 10^9)일의 시간이 있다면 최대 몇 권의 책을 쓸 수 있는지 구한다.

해결 방법 : 쓰는데 걸리는 시간이 기하급수적으로 늘어나기 때문에 직접 책을 쓰는 시간을 구해가며
D를 넘기 전까지 쓴 책의 수를 구하면 된다. 쓴 책의 수는 log(D)에 비례하게 된다.

주요 알고리즘 : 수학

출처 : SPPC 2017D I번
*/

int main(void) {
    long long k, d, t = 0, r = 0;
    scanf("%lld %lld", &k, &d);
    for (long long i = 0;; i++) {
        t += k * (1LL << i);
        if (t > d) break;
        r++;
    }
    printf("%lld", r);
    return 0;
}