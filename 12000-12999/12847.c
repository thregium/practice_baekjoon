#include <stdio.h>

/*
문제 : N(N <= 100000)개의 음이 아닌 정수(<= 10^6) 가운데 연속한 M(M <= N)개의 수의 합이 가장 큰 것의 연속합을 구한다.

해결 방법 : 첫 M개의 합을 구한 후, 이후로는 M + i번째의 값을 더하고 i번째의 값을 빼 나간다.
그 과정에서 나오는 가장 큰 값을 구하면 된다.

주요 알고리즘 : 자료 구조, 슬라이딩 윈도우

출처 : 숭실대 2016 I번
*/

int t[103000];

int main(void) {
    int n, m;
    long long r = 0, s = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < m; i++) s += t[i];
    if (s > r) r = s;
    for (int i = m; i < n; i++) {
        s += t[i] - t[i - m];
        if (s > r) r = s;
    }
    printf("%lld", r);
    return 0;
}