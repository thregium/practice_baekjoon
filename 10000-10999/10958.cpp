#include <stdio.h>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 40)개의 수들 가운데 합이 M(M <= 10^18) 이하인 집합의 수를 구한다. 각 수는 10^16 이하이고,
공집합도 집합으로 센다.

해결 방법 : N개의 수를 두 부분으로 나누어 첫 번째 집합의 모든 부분합을 구한 다음 정렬한다.
두 번째 집합에서는 모든 부분합에 대해 첫 번째 집합의 부분합이 M - (2번째 집합의 부분합) 이하인 수의 개수를
이분 탐색을 통해 구할 수 있고, 이 값을 전부 더한 것이 답이 된다.

주요 알고리즘 : 이분 탐색, 밋 인 더 미들

출처 : CEOI 2015 4번
*/

long long ticket[64], msum[1280000];

int main(void) {
    long long n, m, s, r = 0, t;
    scanf("%lld %lld", &n, &m);
    s = (n >> 1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ticket[i]);
    }
    for (int i = 0; i < (1 << s); i++) {
        for (int j = 0; j < s; j++) {
            if (i & (1 << j)) msum[i] += ticket[j];
        }
    }
    sort(msum, msum + (1 << s));
    for (int i = 0; i < (1 << (n - s)); i++) {
        t = 0;
        for (int j = 0; j < n - s; j++) {
            if (i & (1 << j)) t += ticket[j + s];
        }
        r += upper_bound(msum, msum + (1 << s), m - t) - msum;
    }
    printf("%lld", r);
    return 0;
}