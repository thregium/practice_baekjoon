#include <stdio.h>
#include <stdlib.h>

/*
문제 : 2 이상의 자연수 N(N <= 10^12)이 주어질 때, N을 합성수로 분해하는 방법 가운데 사전 순으로 가장 빠른 것을 구한다.
그러한 방법이 없다면 -1을 출력한다.

해결 방법 : N을 소인수분해한 것을 사전순으로 정렬한 다음, 앞에서부터 2개씩 묶어나간다.
만약 3개가 남는 경우 3개를 한번에 묶는다.

주요 알고리즘 : 그리디 알고리즘, 수학, 소수 판정

출처 : SUAPC 2021W K번
*/

long long f[64];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int cnt = 0;
    long long n, m, r, r2 = 1;
    scanf("%lld", &m);
    //for (long long m = 2;; m++) {
        cnt = 0, r2 = 1;
        n = m;
        for (long long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                f[cnt++] = i;
            }
        }
        f[cnt++] = n;
        if (f[cnt - 1] == 1) cnt--;
        qsort(f, cnt, sizeof(long long), cmp1);

        if (cnt < 2) {
            printf("-1\n");
            return 0;
            //continue;
        }
        for (int i = 0; i < cnt - 1; i += 2) {
            r = (i == cnt - 3 ? f[i] * f[i + 1] * f[i + 2] : f[i] * f[i + 1]);
            printf("%lld ", r);
            r2 *= r;
            for (long long j = 2; j * j <= r; j++) {
                if (r % j == 0) r /= j;
            }
            if (r == (i == cnt - 3 ? f[i] * f[i + 1] * f[i + 2] : f[i] * f[i + 1])) {
                return 3;
            }
        }
        printf("\n");
        if (r2 != m) {
            //printf("%lld", m);
            return 2;
        }
    //}
    return 0;
}