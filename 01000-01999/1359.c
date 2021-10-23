#include <stdio.h>

/*
문제 : N(N <= 8)개의 수 가운데 M개를 뽑고, 또 M개를 뽑았을 때, K개 이상이 같을 확률을 구한다.

해결 방법 : N이 매우 작기 때문에 브루트 포스를 통해 모든 조합을 뽑아본 다음 같은 수(M 이하의 수, 1부터 K까지의 수로
차례로 뽑았다고 가정한다.)의 개수가 K개 이상인 수의 개수를 구한다. 그 다음, 전체 조합의 가짓수로 그 값을 나누면
답을 구할 수 있다.

주요 알고리즘 : 수학, 조합론, 브루트 포스
*/

int pick[16];

int track(int n, int m, int k, int p, int l) {
    int r = 0;
    if (p == m) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (pick[i] <= m) cnt++;
        }
        if (cnt >= k) r = 1;
        return r;
    }
    for (int i = l; i <= n; i++) {
        pick[p] = i;
        r += track(n, m, k, p + 1, i + 1);
    }
    return r;
}

int main(void) {
    int n, m, k, r, fact = 1;
    scanf("%d %d %d", &n, &m, &k);
    r = track(n, m, k, 0, 1);
    for (int i = 2; i <= n; i++) fact *= i;
    for (int i = 2; i <= m; i++) fact /= i;
    for (int i = 2; i <= n - m; i++) fact /= i;
    printf("%.39lf", r / (double)fact);
    return 0;
}