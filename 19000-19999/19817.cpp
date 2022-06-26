#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 200000)개의 회사가 있다. 각 회사별 사원의 봉급(<= 10^9)이 주어진다.
이때, 모든 회사를 합치기 위해 올려야 하는 사원의 봉급 합을 구한다. 모든 회사의 사원수 합은 200000 이하다.
회사는 2개씩만 합칠 수 있으며, 두 회사의 최대 봉급이 같아야 한다.
각 회사의 봉급을 임의의 양만큼 늘릴 수 있지만 줄일 수는 없고, 모든 사원의 봉급이 같은 양만큼 올라야 한다.

해결 방법 : 모든 회사의 최대 봉급은 가장 봉급이 높은 회사의 봉급이 되어야 한다.
따라서, 각 사원의 봉급 상승량은 가장 봉급이 높은 회사와의 최대 봉급 차이 * 그 회사의 사원수를
모든 회사에 대해 더한 값과 같다.

주요 알고리즘 : 그리디 알고리즘

출처 : ROI 2018T A번
*/

vector<int> comp[204800];
int hi[204800];

int main(void) {
    int n, m, x, best = 0;
    long long res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            comp[i].push_back(x);
            if (x > hi[i]) hi[i] = x;
        }
        if (hi[i] > best) best = hi[i];
    }
    for (int i = 0; i < n; i++) {
        res += ((long long)best - hi[i]) * (long long)(comp[i].size());
    }
    printf("%lld", res);
    return 0;
}