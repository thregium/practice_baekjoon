#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 자연수(<= 10000)로 이루어진 수열이 주어질 때, 연속한 3개의 그룹으로 묶어
합이 같은 3개의 수열로 만들 수 있는 방법이 있는 지 구하고, 있다면 그 구분선을 출력한다.

해결 방법 : 왼쪽에서부터 누적 합이 전체의 1/3, 2/3가 되는 지점이 모두 있다면 그 지점들을 답으로 출력한다.
하나라도 없다면 그러한 방법이 없으므로 -1을 출력하면 된다.

주요 알고리즘 : 구현, 누적 합

출처 : VTH 2019 A번
*/

int a[1048576];

int main(void) {
    int n;
    long long sum = 0, psum = 0, res1 = -1, res2 = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        psum += a[i];
        if (psum * 3 == sum) res1 = i + 1;
        if (psum * 3 == sum * 2) res2 = i + 1;
    }
    if (res1 >= 0 && res2 >= 0) printf("%lld %lld", res1, res2);
    else printf("-1");
    return 0;
}